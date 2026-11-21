// FabricaObstaculosTerrestre.cpp

#include "FabricaObstaculosTerrestre.h"
#include "OTPared.h"
#include "OTArbol.h"
#include "Engine/World.h"

AObstaculo* UFabricaObstaculosTerrestre::CrearObstaculoPrincipal(UWorld* Mundo, FVector Posicion)
{
	if (!Mundo) return nullptr;

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	return Mundo->SpawnActor<AOTPared>(AOTPared::StaticClass(), Posicion, FRotator::ZeroRotator, Params);
}

AObstaculo* UFabricaObstaculosTerrestre::CrearObstaculoSecundario(UWorld* Mundo, FVector Posicion)
{
	if (!Mundo) return nullptr;

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	return Mundo->SpawnActor<AOTArbol>(AOTArbol::StaticClass(), Posicion, FRotator::ZeroRotator, Params);
}
