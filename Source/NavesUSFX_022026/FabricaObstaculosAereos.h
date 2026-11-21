// FabricaObstaculosAereos.h
// ============================================================
//  CONCRETE FACTORY  –  Familia Aérea
// ============================================================
// Fabrica obstáculos del entorno aéreo: Roca flotante y Nube.

#pragma once

#include "CoreMinimal.h"
#include "FabricaObstaculos.h"
#include "FabricaObstaculosAereos.generated.h"

UCLASS()
class NAVESUSFX_022026_API UFabricaObstaculosAereos : public UFabricaObstaculos
{
	GENERATED_BODY()

public:
	// Principal: Roca Flotante (mayor daño)
	virtual AObstaculo* CrearObstaculoPrincipal(UWorld* Mundo, FVector Posicion) override;

	// Secundario: Nube de Tormenta (daño leve, visual)
	virtual AObstaculo* CrearObstaculoSecundario(UWorld* Mundo, FVector Posicion) override;
};
