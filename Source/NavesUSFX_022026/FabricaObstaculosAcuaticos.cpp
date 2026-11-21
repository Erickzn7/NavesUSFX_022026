// FabricaObstaculosAcuaticos.cpp

#include "FabricaObstaculosAcuaticos.h"
#include "OAqMina.h"
#include "OAqIceberg.h"
#include "Engine/World.h"

AObstaculo* UFabricaObstaculosAcuaticos::CrearObstaculoPrincipal(UWorld* Mundo, FVector Posicion)
{
	if (!Mundo) return nullptr;

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	return Mundo->SpawnActor<AOAqMina>(AOAqMina::StaticClass(), Posicion, FRotator::ZeroRotator, Params);
}

AObstaculo* UFabricaObstaculosAcuaticos::CrearObstaculoSecundario(UWorld* Mundo, FVector Posicion)
{
	if (!Mundo) return nullptr;

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	return Mundo->SpawnActor<AOAqIceberg>(AOAqIceberg::StaticClass(), Posicion, FRotator::ZeroRotator, Params);
}
