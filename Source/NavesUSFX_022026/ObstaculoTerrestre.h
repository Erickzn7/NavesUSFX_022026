// ObstaculoTerrestre.h
// Subtipo de obstáculo que representa elementos del entorno terrestre.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "ObstaculoTerrestre.generated.h"

UCLASS()
class NAVESUSFX_022026_API AObstaculoTerrestre : public AObstaculo
{
	GENERATED_BODY()

public:
	AObstaculoTerrestre();

	// Indica si el obstáculo bloquea el paso completamente
	UPROPERTY(EditAnywhere, Category = "Obstaculo")
	bool bBloqueo;
};
