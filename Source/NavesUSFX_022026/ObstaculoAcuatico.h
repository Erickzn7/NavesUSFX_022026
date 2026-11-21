// ObstaculoAcuatico.h
// Subtipo de obstáculo que representa elementos del entorno acuático.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "ObstaculoAcuatico.generated.h"

UCLASS()
class NAVESUSFX_022026_API AObstaculoAcuatico : public AObstaculo
{
	GENERATED_BODY()

public:
	AObstaculoAcuatico();

	// Profundidad del obstáculo bajo la superficie
	UPROPERTY(EditAnywhere, Category = "Obstaculo")
	float Profundidad;
};
