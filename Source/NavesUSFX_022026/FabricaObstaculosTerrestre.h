// FabricaObstaculosTerrestre.h
// ============================================================
//  CONCRETE FACTORY  –  Familia Terrestre
// ============================================================
// Fabrica obstáculos del entorno terrestre: Pared y Árbol.

#pragma once

#include "CoreMinimal.h"
#include "FabricaObstaculos.h"
#include "FabricaObstaculosTerrestre.generated.h"

UCLASS()
class NAVESUSFX_022026_API UFabricaObstaculosTerrestre : public UFabricaObstaculos
{
	GENERATED_BODY()

public:
	// Principal: Pared de Piedra (mayor daño, bloqueo total)
	virtual AObstaculo* CrearObstaculoPrincipal(UWorld* Mundo, FVector Posicion) override;

	// Secundario: Árbol (daño medio)
	virtual AObstaculo* CrearObstaculoSecundario(UWorld* Mundo, FVector Posicion) override;
};
