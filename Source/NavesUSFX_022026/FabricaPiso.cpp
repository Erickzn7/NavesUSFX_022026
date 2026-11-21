// FabricaPiso.cpp
#include "FabricaPiso.h"
#include "CPiso.h"
#include "Engine/World.h"

AComponentePlataforma* UFabricaPiso::CrearComponente(UWorld* Mundo, FVector Posicion, int32 NumeroUnico)
{
    if (!Mundo) return nullptr;

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    ACPiso* Nuevo = Mundo->SpawnActor<ACPiso>(ACPiso::StaticClass(), Posicion, FRotator::ZeroRotator, Params);
    if (Nuevo)
    {
        Nuevo->NumeroComponente = NumeroUnico;
        Nuevo->TipoComponente   = ETipoComponente::Piso;
    }
    return Nuevo;
}
