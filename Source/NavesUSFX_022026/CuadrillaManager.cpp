#include "CuadrillaManager.h"
#include "Engine/World.h"
#include "TimerManager.h"

#include "EAHelicoptero.h"
#include "EAAvion.h"
#include "EADron.h"
#include "ETSoldado.h"
#include "ETTanque.h"
#include "ETCamion.h"
#include "ETBlindado.h"
#include "EABarco.h"
#include "EALancha.h"
#include "EAMotoAcuatica.h"

ACuadrillaManager::ACuadrillaManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACuadrillaManager::BeginPlay()
{
	Super::BeginPlay();

	// 1. Inicia creando la cuadrilla 1
	SpawnCuadrilla1();

	// 2. Temporizador que llama a EliminarEnemigoCuadrilla1 cada 3 segundos
	GetWorldTimerManager().SetTimer(
		TemporizadorDesaparicion,
		this,
		&ACuadrillaManager::EliminarEnemigoCuadrilla1,
		3.0f,
		true
	);
}

void ACuadrillaManager::SpawnCuadrilla1()
{
	UWorld* const Mundo = GetWorld();
	if (!Mundo) return;

	FVector PosicionBase = GetActorLocation();

	TArray<UClass*> ClasesCuadrilla1 = {
		AEAHelicoptero::StaticClass(),
		AEAAvion::StaticClass(),
		AEADron::StaticClass(),
		AETTanque::StaticClass(),
		AETCamion::StaticClass()
	};

	for (int32 i = 0; i < ClasesCuadrilla1.Num(); ++i)
	{
		FVector PosSpawn = PosicionBase + FVector(0.0f, i * 250.0f, 0.0f);
		AEnemigo* NuevoEnemigo = Mundo->SpawnActor<AEnemigo>(ClasesCuadrilla1[i], PosSpawn, FRotator::ZeroRotator);
		if (NuevoEnemigo)
		{
			Cuadrilla1.Add(NuevoEnemigo);
		}
	}
}

void ACuadrillaManager::SpawnCuadrilla2()
{
	UWorld* const Mundo = GetWorld();
	if (!Mundo) return;

	FVector PosicionBase = GetActorLocation() + FVector(0.0f, 0.0f, 300.0f);

	TArray<UClass*> ClasesCuadrilla2 = {
		AETSoldado::StaticClass(),
		AETBlindado::StaticClass(),
		AEABarco::StaticClass(),
		AEALancha::StaticClass(),
		AEAMotoAcuatica::StaticClass()
	};

	for (int32 i = 0; i < ClasesCuadrilla2.Num(); ++i)
	{
		FVector PosSpawn = PosicionBase + FVector(0.0f, i * 250.0f, 0.0f);
		AEnemigo* NuevoEnemigo = Mundo->SpawnActor<AEnemigo>(ClasesCuadrilla2[i], PosSpawn, FRotator::ZeroRotator);
		if (NuevoEnemigo)
		{
			if (i % 2 == 1)
			{
				NuevoEnemigo->Direccion = FVector(-1.0f, 0.0f, 0.0f);
			}
			Cuadrilla2.Add(NuevoEnemigo);
		}
	}
}

void ACuadrillaManager::EliminarEnemigoCuadrilla1()
{
	if (Cuadrilla1.Num() > 0)
	{
		AEnemigo* EnemigoAEliminar = Cuadrilla1[0];
		Cuadrilla1.RemoveAt(0);

		if (IsValid(EnemigoAEliminar))
		{
			EnemigoAEliminar->Destroy();
		}

		if (Cuadrilla1.Num() == 0)
		{
			GetWorldTimerManager().ClearTimer(TemporizadorDesaparicion);
			SpawnCuadrilla2();
		}
	}
}