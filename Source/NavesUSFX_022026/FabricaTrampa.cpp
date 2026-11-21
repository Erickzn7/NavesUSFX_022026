// FabricaTrampa.cpp
#include "FabricaTrampa.h"
#include "CTrampa.h"
#include "Engine/World.h"

AComponentePlataforma* UFabricaTrampa::CrearComponente(UWorld* Mundo, FVector Posicion, int32 NumeroUnico)
{
    if (!Mundo) return nullptr;

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    ACTrampa* Nuevo = Mundo->SpawnActor<ACTrampa>(ACTrampa::StaticClass(), Posicion, FRotator::ZeroRotator, Params);
    if (Nuevo)
    {
        Nuevo->NumeroComponente = NumeroUnico;
        Nuevo->TipoComponente   = ETipoComponente::Trampa;
    }
    return Nuevo;
}
