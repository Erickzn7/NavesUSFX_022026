// ObstaculoAereo.h
// Subtipo de obstáculo que representa elementos del entorno aéreo.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "ObstaculoAereo.generated.h"

UCLASS()
class NAVESUSFX_022026_API AObstaculoAereo : public AObstaculo
{
	GENERATED_BODY()

public:
	AObstaculoAereo();

	// Altitud mínima a la que flota el obstáculo
	UPROPERTY(EditAnywhere, Category = "Obstaculo")
	float Altitud;
};
