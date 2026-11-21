// ObstaculoSpawner.cpp
// ============================================================
//  CLIENTE DEL ABSTRACT FACTORY – Implementación
// ============================================================
// BeginPlay crea una instancia de cada fábrica concreta y llama
// a SpawnObstaculos. El cliente (este archivo) nunca menciona
// AOARoca, AOANube, etc. directamente: todo pasa por la interfaz.

#include "ObstaculoSpawner.h"
#include "FabricaObstaculosAereos.h"
#include "FabricaObstaculosTerrestre.h"
#include "FabricaObstaculosAcuaticos.h"
#include "Engine/World.h"

AObstaculoSpawner::AObstaculoSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AObstaculoSpawner::BeginPlay()
{
	Super::BeginPlay();

	// --- Crear las tres fábricas concretas ---
	UFabricaObstaculosAereos* FabricaAerea =
		NewObject<UFabricaObstaculosAereos>(this);

	UFabricaObstaculosTerrestre* FabricaTerrestre =
		NewObject<UFabricaObstaculosTerrestre>(this);

	UFabricaObstaculosAcuaticos* FabricaAcuatica =
		NewObject<UFabricaObstaculosAcuaticos>(this);

	// --- Usar cada fábrica para poblar el escenario ---
	// Obstáculos aéreos: aparecen elevados (Z = 600)
	FVector PosAerea = GetActorLocation() + FVector(0.0f, 0.0f, 600.0f);
	SpawnObstaculos(FabricaAerea, PosAerea, 3);

	// Obstáculos terrestres: en el suelo (Z = 0)
	FVector PosTerrestre = GetActorLocation() + FVector(500.0f, 0.0f, 0.0f);
	SpawnObstaculos(FabricaTerrestre, PosTerrestre, 3);

	// Obstáculos acuáticos: bajo el nivel del agua (Z = -100)
	FVector PosAcuatica = GetActorLocation() + FVector(-500.0f, 0.0f, -100.0f);
	SpawnObstaculos(FabricaAcuatica, PosAcuatica, 3);
}

void AObstaculoSpawner::SpawnObstaculos(UFabricaObstaculos* Fabrica, FVector PosicionBase, int32 Cantidad)
{
	UWorld* Mundo = GetWorld();
	if (!Mundo || !Fabrica) return;

	for (int32 i = 0; i < Cantidad; i++)
	{
		FVector Pos = PosicionBase + FVector(0.0f, i * 300.0f, 0.0f);

		// Alternamos entre obstáculo principal y secundario
		AObstaculo* Nuevo = nullptr;
		if (i % 2 == 0)
		{
			Nuevo = Fabrica->CrearObstaculoPrincipal(Mundo, Pos);
		}
		else
		{
			Nuevo = Fabrica->CrearObstaculoSecundario(Mundo, Pos);
		}

		if (Nuevo)
		{
			ObstaculosActivos.Add(Nuevo);
			UE_LOG(LogTemp, Log, TEXT("[ObstaculoSpawner] Spawneado: %s en %s"),
				*Nuevo->TipoObstaculo, *Pos.ToString());
		}
	}
}
