// FabricaPared.cpp
#include "FabricaPared.h"
#include "CPared.h"
#include "Engine/World.h"

AComponentePlataforma* UFabricaPared::CrearComponente(UWorld* Mundo, FVector Posicion, int32 NumeroUnico)
{
    if (!Mundo) return nullptr;

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    ACPared* Nuevo = Mundo->SpawnActor<ACPared>(ACPared::StaticClass(), Posicion, FRotator::ZeroRotator, Params);
    if (Nuevo)
    {
        Nuevo->NumeroComponente = NumeroUnico;
        Nuevo->TipoComponente   = ETipoComponente::Pared;
    }
    return Nuevo;
}
