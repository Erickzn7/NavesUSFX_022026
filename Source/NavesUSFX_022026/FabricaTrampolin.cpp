// FabricaTrampolin.cpp
#include "FabricaTrampolin.h"
#include "CTrampolin.h"
#include "Engine/World.h"

AComponentePlataforma* UFabricaTrampolin::CrearComponente(UWorld* Mundo, FVector Posicion, int32 NumeroUnico)
{
    if (!Mundo) return nullptr;

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    ACTrampolin* Nuevo = Mundo->SpawnActor<ACTrampolin>(ACTrampolin::StaticClass(), Posicion, FRotator::ZeroRotator, Params);
    if (Nuevo)
    {
        Nuevo->NumeroComponente = NumeroUnico;
        Nuevo->TipoComponente   = ETipoComponente::Trampolin;
    }
    return Nuevo;
}
