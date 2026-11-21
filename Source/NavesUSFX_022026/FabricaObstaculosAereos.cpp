// FabricaObstaculosAereos.cpp

#include "FabricaObstaculosAereos.h"
#include "OARoca.h"
#include "OANube.h"
#include "Engine/World.h"

AObstaculo* UFabricaObstaculosAereos::CrearObstaculoPrincipal(UWorld* Mundo, FVector Posicion)
{
	if (!Mundo) return nullptr;

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	return Mundo->SpawnActor<AOARoca>(AOARoca::StaticClass(), Posicion, FRotator::ZeroRotator, Params);
}

AObstaculo* UFabricaObstaculosAereos::CrearObstaculoSecundario(UWorld* Mundo, FVector Posicion)
{
	if (!Mundo) return nullptr;

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	return Mundo->SpawnActor<AOANube>(AOANube::StaticClass(), Posicion, FRotator::ZeroRotator, Params);
}
