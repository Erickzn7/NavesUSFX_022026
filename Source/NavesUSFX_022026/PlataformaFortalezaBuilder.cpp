// PlataformaFortalezaBuilder.cpp

#include "PlataformaFortalezaBuilder.h"
#include "CPared.h"

void UPlataformaFortalezaBuilder::Reiniciar(UWorld* InMundo, FVector InPosBase)
{
    Super::Reiniciar(InMundo, InPosBase);

    Producto->NombrePlataforma = TEXT("Fortaleza");
    Producto->Descripcion      =
        TEXT("Plataforma defensiva: pisos reforzados, muro perimetral y puertas de acceso.");

    FabPiso   = NewObject<UFabricaPiso>(this);
    FabPared  = NewObject<UFabricaPared>(this);
    FabPuerta = NewObject<UFabricaPuerta>(this);
}

void UPlataformaFortalezaBuilder::ConstruirPisos()
{
    // 4 pisos solidos (sin movimiento) con resistencia alta
    for (int32 i = 0; i < 4; i++)
    {
        AComponentePlataforma* Piso =
            SpawnComponente(FabPiso, FVector(i * 400.0f, 0.0f, 0.0f));

        if (Piso)
        {
            Piso->Resistencia = 500.0f;   // Reforzado
        }
    }

    UE_LOG(LogTemp, Log,
        TEXT("[FortalezaBuilder] 4 pisos reforzados (Resistencia=500)"));
}

void UPlataformaFortalezaBuilder::ConstruirParedes()
{
    // Muro perimetral: 4 paredes indestructibles
    TArray<FVector> Offsets = {
        FVector(-50.0f,  600.0f, 200.0f),   // Norte
        FVector(1250.0f, 600.0f, 200.0f),   // Sur
        FVector(600.0f, -50.0f,  200.0f),   // Oeste
        FVector(600.0f, 1250.0f, 200.0f)    // Este
    };

    for (const FVector& Off : Offsets)
    {
        AComponentePlataforma* Pared =
            SpawnComponente(FabPared, Off);

        if (Pared)
        {
            // Paredes de fortaleza NO son destructibles
            ACPared* ParedCast = Cast<ACPared>(Pared);
            if (ParedCast)
            {
                ParedCast->bEsDestructible = false;
                ParedCast->Resistencia     = 9999.0f;
            }
        }
    }

    UE_LOG(LogTemp, Log,
        TEXT("[FortalezaBuilder] 4 paredes perimetrales indestructibles"));
}

void UPlataformaFortalezaBuilder::ConstruirPuertas()
{
    // 2 puertas de acceso controlado (norte y sur)
    SpawnComponente(FabPuerta, FVector(0.0f,   600.0f, 150.0f));
    SpawnComponente(FabPuerta, FVector(1200.0f, 600.0f, 150.0f));

    UE_LOG(LogTemp, Log,
        TEXT("[FortalezaBuilder] 2 puertas de acceso construidas"));
}
