#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

UCLASS()
class NAVESUSFX_022026_API AEnemigo : public AActor
{
	GENERATED_BODY()

public:
	AEnemigo();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "Visual")
	UStaticMeshComponent* MallaEnemigo;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float Velocidad;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	FVector Direccion;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float LimiteX;
};
