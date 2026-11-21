// FabricaObstaculosAcuaticos.h
// ============================================================
//  CONCRETE FACTORY  –  Familia Acuática
// ============================================================
// Fabrica obstáculos del entorno acuático: Iceberg y Mina.

#pragma once

#include "CoreMinimal.h"
#include "FabricaObstaculos.h"
#include "FabricaObstaculosAcuaticos.generated.h"

UCLASS()
class NAVESUSFX_022026_API UFabricaObstaculosAcuaticos : public UFabricaObstaculos
{
	GENERATED_BODY()

public:
	// Principal: Mina Submarina (daño máximo, explosivo)
	virtual AObstaculo* CrearObstaculoPrincipal(UWorld* Mundo, FVector Posicion) override;

	// Secundario: Iceberg (daño alto, estático)
	virtual AObstaculo* CrearObstaculoSecundario(UWorld* Mundo, FVector Posicion) override;
};
