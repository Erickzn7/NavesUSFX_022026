// PlataformaManager.cpp
// ============================================================
//  LAB 06 - FACTORY METHOD  —  Implementacion del Manager
// ============================================================

#include "PlataformaManager.h"
#include "Engine/World.h"

// Fabricas concretas
#include "FabricaPiso.h"
#include "FabricaPared.h"
#include "FabricaPuerta.h"
#include "FabricaTrampolin.h"
#include "FabricaTrampa.h"

APlataformaManager::APlataformaManager()
{
    PrimaryActorTick.bCanEverTick = false;

    ContadorID          = 1;    // Las claves del TMap arrancan en 1
    CantidadPisos       = 4;
    CantidadParedes     = 3;
    CantidadPuertas     = 2;
    CantidadTrampolines = 2;
    CantidadTrampas     = 3;
    Espaciado           = 350.0f;
}

void APlataformaManager::BeginPlay()
{
    Super::BeginPlay();

    InicializarFabricas();
    GenerarPlataformaInicial();
    ImprimirRegistro();

    // Comportamiento de grupo por tipo
    EjecutarComportamientoGrupo(ETipoComponente::Piso);
    EjecutarComportamientoGrupo(ETipoComponente::Pared);
    EjecutarComportamientoGrupo(ETipoComponente::Puerta);
    EjecutarComportamientoGrupo(ETipoComponente::Trampolin);
    EjecutarComportamientoGrupo(ETipoComponente::Trampa);
}

// -----------------------------------------------------------------
void APlataformaManager::InicializarFabricas()
{
    // Registrar una fabrica concreta por cada tipo de componente
    Fabricas.Add(ETipoComponente::Piso,      NewObject<UFabricaPiso>(this));
    Fabricas.Add(ETipoComponente::Pared,     NewObject<UFabricaPared>(this));
    Fabricas.Add(ETipoComponente::Puerta,    NewObject<UFabricaPuerta>(this));
    Fabricas.Add(ETipoComponente::Trampolin, NewObject<UFabricaTrampolin>(this));
    Fabricas.Add(ETipoComponente::Trampa,    NewObject<UFabricaTrampa>(this));
}

// -----------------------------------------------------------------
void APlataformaManager::GenerarPlataformaInicial()
{
    FVector Base = GetActorLocation();

    // Fila de Pisos — eje Y
    for (int32 i = 0; i < CantidadPisos; i++)
    {
        FVector Pos = Base + FVector(0.0f, i * Espaciado, 0.0f);
        CrearComponente(ETipoComponente::Piso, Pos);
    }

    // Fila de Paredes — eje X (desplazada en Z para que sean paredes laterales)
    for (int32 i = 0; i < CantidadParedes; i++)
    {
        FVector Pos = Base + FVector(i * Espaciado, -200.0f, 150.0f);
        CrearComponente(ETipoComponente::Pared, Pos);
    }

    // Puertas — a un lado del nivel
    for (int32 i = 0; i < CantidadPuertas; i++)
    {
        FVector Pos = Base + FVector(600.0f, i * Espaciado, 150.0f);
        CrearComponente(ETipoComponente::Puerta, Pos);
    }

    // Trampolines — centrados
    for (int32 i = 0; i < CantidadTrampolines; i++)
    {
        FVector Pos = Base + FVector(200.0f, i * Espaciado, 20.0f);
        CrearComponente(ETipoComponente::Trampolin, Pos);
    }

    // Trampas — dispersas
    for (int32 i = 0; i < CantidadTrampas; i++)
    {
        FVector Pos = Base + FVector(-200.0f, i * Espaciado, 15.0f);
        CrearComponente(ETipoComponente::Trampa, Pos);
    }
}

// -----------------------------------------------------------------
AComponentePlataforma* APlataformaManager::CrearComponente(
    ETipoComponente Tipo, FVector Posicion)
{
    UFabricaComponentePlataforma** FabricaPtr = Fabricas.Find(Tipo);
    if (!FabricaPtr || !(*FabricaPtr)) return nullptr;

    UWorld* Mundo = GetWorld();
    if (!Mundo) return nullptr;

    // Generar numero unico para este componente
    int32 NumeroUnico = ContadorID++;

    // Llamada al Factory Method
    AComponentePlataforma* Nuevo =
        (*FabricaPtr)->CrearComponente(Mundo, Posicion, NumeroUnico);

    if (Nuevo)
    {
        // Almacenar en el TMap con clave unica
        Componentes.Add(NumeroUnico, Nuevo);

        UE_LOG(LogTemp, Log,
            TEXT("[PlataformaManager] Componente #%d creado — Tipo: %d — Total: %d"),
            NumeroUnico, (int32)Tipo, Componentes.Num());
    }

    return Nuevo;
}

// -----------------------------------------------------------------
AComponentePlataforma* APlataformaManager::ObtenerComponente(int32 Numero) const
{
    AComponentePlataforma* const* Encontrado = Componentes.Find(Numero);
    if (Encontrado && IsValid(*Encontrado))
    {
        return *Encontrado;
    }
    UE_LOG(LogTemp, Warning,
        TEXT("[PlataformaManager] Componente #%d NO encontrado"), Numero);
    return nullptr;
}

// -----------------------------------------------------------------
void APlataformaManager::EliminarComponente(int32 Numero)
{
    AComponentePlataforma* Comp = ObtenerComponente(Numero);
    if (!Comp) return;

    Comp->Destroy();
    Componentes.Remove(Numero);

    UE_LOG(LogTemp, Log,
        TEXT("[PlataformaManager] Componente #%d eliminado — Restantes: %d"),
        Numero, Componentes.Num());
}

// -----------------------------------------------------------------
void APlataformaManager::EjecutarComportamientoGrupo(ETipoComponente Tipo)
{
    // Recolectar todos los del mismo tipo
    TArray<AComponentePlataforma*> Grupo;
    for (auto& Par : Componentes)
    {
        if (IsValid(Par.Value) && Par.Value->TipoComponente == Tipo)
        {
            Grupo.Add(Par.Value);
        }
    }

    int32 Total = Grupo.Num();
    if (Total == 0) return;

    UE_LOG(LogTemp, Log,
        TEXT("[PlataformaManager] ComportamientoGrupo Tipo %d — %d componentes"),
        (int32)Tipo, Total);

    // Llamar ComportamientoGrupo en cada miembro del grupo
    for (AComponentePlataforma* Comp : Grupo)
    {
        Comp->ComportamientoGrupo(Total);
    }
}

// -----------------------------------------------------------------
void APlataformaManager::ImprimirRegistro() const
{
    UE_LOG(LogTemp, Log,
        TEXT("===== REGISTRO DE COMPONENTES DE PLATAFORMA (%d total) ====="),
        Componentes.Num());

    for (const auto& Par : Componentes)
    {
        if (IsValid(Par.Value))
        {
            UE_LOG(LogTemp, Log,
                TEXT("  Clave #%d  |  Tipo: %d  |  Activo: %s  |  Resistencia: %.0f"),
                Par.Key,
                (int32)Par.Value->TipoComponente,
                Par.Value->bActivo ? TEXT("SI") : TEXT("NO"),
                Par.Value->Resistencia);
        }
    }

    UE_LOG(LogTemp, Log, TEXT("====================================================="));
}
