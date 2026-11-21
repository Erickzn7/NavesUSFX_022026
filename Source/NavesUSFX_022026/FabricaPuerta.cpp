// FabricaPuerta.cpp
#include "FabricaPuerta.h"
#include "CPuerta.h"
#include "Engine/World.h"

AComponentePlataforma* UFabricaPuerta::CrearComponente(UWorld* Mundo, FVector Posicion, int32 NumeroUnico)
{
    if (!Mundo) return nullptr;

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    ACPuerta* Nuevo = Mundo->SpawnActor<ACPuerta>(ACPuerta::StaticClass(), Posicion, FRotator::ZeroRotator, Params);
    if (Nuevo)
    {
        Nuevo->NumeroComponente = NumeroUnico;
        Nuevo->TipoComponente   = ETipoComponente::Puerta;
    }
    return Nuevo;
}
