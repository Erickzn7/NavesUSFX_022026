#include "NavesUSFX_022026GameMode.h"
#include "NavesUSFX_022026Pawn.h"
#include "Enemigo.h"
#include "Engine/World.h"

ANavesUSFX_022026GameMode::ANavesUSFX_022026GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ANavesUSFX_022026Pawn::StaticClass();
}

void ANavesUSFX_022026GameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* const World = GetWorld();
	if (World)
	{
		// Generar un grupo de enemigos distribuidos en el escenario
		int32 CantidadEnemigos = 5;
		float EspaciadoY = 300.0f;
		float PosicionInicialY = -600.0f;

		for (int32 i = 0; i < CantidadEnemigos; i++)
		{
			FVector PosicionSpawn = FVector(0.0f, PosicionInicialY + (i * EspaciadoY), 200.0f);
			FRotator RotacionSpawn = FRotator::ZeroRotator;

			AEnemigo* NuevoEnemigo = World->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), PosicionSpawn, RotacionSpawn);
			if (NuevoEnemigo)
			{
				// Configurar parámetros individuales para variedad de movimiento
				NuevoEnemigo->Velocidad = 250.0f + (i * 50.0f);
				Enemigos.Add(NuevoEnemigo);
			}
		}
	}
}


