// PlataformaTrampaBuilder.cpp

#include "PlataformaTrampaBuilder.h"
#include "CPiso.h"
#include "CTrampa.h"
#include "CTrampolin.h"

void UPlataformaTrampaBuilder::Reiniciar(UWorld* InMundo, FVector InPosBase)
{
    Super::Reiniciar(InMundo, InPosBase);

    Producto->NombrePlataforma = TEXT("Plataforma de Trampas");
    Producto->Descripcion      =
        TEXT("Nivel de obstaculos: pisos moviles, trampolines potentes y trampas rapidas.");

    FabPiso      = NewObject<UFabricaPiso>(this);
    FabTrampolin = NewObject<UFabricaTrampolin>(this);
    FabTrampa    = NewObject<UFabricaTrampa>(this);
}

void UPlataformaTrampaBuilder::ConstruirPisos()
{
    // 3 pisos moviles (desafiantes)
    for (int32 i = 0; i < 3; i++)
    {
        AComponentePlataforma* Piso =
            SpawnComponente(FabPiso, FVector(i * 500.0f, 0.0f, 0.0f));

        if (Piso)
        {
            ACPiso* PisoCast = Cast<ACPiso>(Piso);
            if (PisoCast)
            {
                PisoCast->bEsMovil            = true;
                PisoCast->VelocidadMovimiento = 200.0f + i * 50.0f;
            }
        }
    }

    UE_LOG(LogTemp, Log,
        TEXT("[TrampaBuilder] 3 pisos moviles construidos"));
}

void UPlataformaTrampaBuilder::ConstruirTrampolines()
{
    // 2 trampolines de alto impulso
    for (int32 i = 0; i < 2; i++)
    {
        AComponentePlataforma* Tramp =
            SpawnComponente(FabTrampolin, FVector(250.0f + i * 500.0f, 200.0f, 20.0f));

        if (Tramp)
        {
            ACTrampolin* TC = Cast<ACTrampolin>(Tramp);
            if (TC)
            {
                TC->FuerzaImpulso = 2000.0f;   // Muy potente
            }
        }
    }

    UE_LOG(LogTemp, Log,
        TEXT("[TrampaBuilder] 2 trampolines de alto impulso construidos"));
}

void UPlataformaTrampaBuilder::ConstruirTrampas()
{
    // 4 trampas rapidas intercaladas
    for (int32 i = 0; i < 4; i++)
    {
        AComponentePlataforma* Trampa =
            SpawnComponente(FabTrampa, FVector(i * 350.0f, 100.0f, 15.0f));

        if (Trampa)
        {
            ACTrampa* TC = Cast<ACTrampa>(Trampa);
            if (TC)
            {
                TC->DanoAlActivar       = 40.0f;
                TC->IntervaloActivacion = 1.0f;  // Muy frecuente
            }
        }
    }

    UE_LOG(LogTemp, Log,
        TEXT("[TrampaBuilder] 4 trampas rapidas construidas"));
}
