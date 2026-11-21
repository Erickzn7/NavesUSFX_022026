// Obstaculo.h
// Clase base para todos los obstáculos del escenario.
// Sigue la misma estructura que AEnemigo (clase de templates).

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstaculo.generated.h"

UCLASS()
class NAVESUSFX_022026_API AObstaculo : public AActor
{
	GENERATED_BODY()

public:
	AObstaculo();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// Malla visual del obstáculo
	UPROPERTY(VisibleAnywhere, Category = "Visual")
	UStaticMeshComponent* MallaObstaculo;

	// Puntos de daño al colisionar
	UPROPERTY(EditAnywhere, Category = "Obstaculo")
	float Dano;

	// Nombre descriptivo del tipo de obstáculo
	UPROPERTY(EditAnywhere, Category = "Obstaculo")
	FString TipoObstaculo;
};
