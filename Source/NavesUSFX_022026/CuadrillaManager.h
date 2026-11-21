#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.h"
#include "CuadrillaManager.generated.h"

UCLASS()
class NAVESUSFX_022026_API ACuadrillaManager : public AActor
{
	GENERATED_BODY()

public:
	ACuadrillaManager();

protected:
	virtual void BeginPlay() override;

private:
	void SpawnCuadrilla1();
	void SpawnCuadrilla2();
	void EliminarEnemigoCuadrilla1();

	UPROPERTY()
	TArray<AEnemigo*> Cuadrilla1;

	UPROPERTY()
	TArray<AEnemigo*> Cuadrilla2;

	FTimerHandle TemporizadorDesaparicion;
};