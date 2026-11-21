// ObstaculoSpawner.h
// ============================================================
//  CLIENTE DEL ABSTRACT FACTORY
// ============================================================
// Actor que coloca obstáculos en el escenario usando las fábricas.
// No conoce los tipos concretos de obstáculo — solo trabaja con
// UFabricaObstaculos (la interfaz), lo que hace el patrón flexible.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FabricaObstaculos.h"
#include "ObstaculoSpawner.generated.h"

UCLASS()
class NAVESUSFX_022026_API AObstaculoSpawner : public AActor
{
	GENERATED_BODY()

public:
	AObstaculoSpawner();

protected:
	virtual void BeginPlay() override;

private:
	// Coloca obstáculos usando una fábrica concreta dada
	void SpawnObstaculos(UFabricaObstaculos* Fabrica, FVector PosicionBase, int32 Cantidad);

	// Lista de todos los obstáculos activos en escena
	UPROPERTY()
	TArray<AObstaculo*> ObstaculosActivos;
};
