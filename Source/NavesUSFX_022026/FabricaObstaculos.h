// FabricaObstaculos.h
// ============================================================
//  ABSTRACT FACTORY  –  Interfaz base
// ============================================================
// Define el contrato que toda fábrica de obstáculos debe cumplir.
// Cada fábrica concreta sabe qué subclases de AObstaculo crear
// sin que el código cliente (ObstaculoSpawner) lo necesite saber.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Obstaculo.h"
#include "FabricaObstaculos.generated.h"

UCLASS(Abstract)
class NAVESUSFX_022026_API UFabricaObstaculos : public UObject
{
	GENERATED_BODY()

public:
	// Crea el obstáculo principal de esta familia (p.ej. el más peligroso)
	virtual AObstaculo* CrearObstaculoPrincipal(UWorld* Mundo, FVector Posicion) PURE_VIRTUAL(UFabricaObstaculos::CrearObstaculoPrincipal, return nullptr;);

	// Crea el obstáculo secundario de esta familia (p.ej. el más leve)
	virtual AObstaculo* CrearObstaculoSecundario(UWorld* Mundo, FVector Posicion) PURE_VIRTUAL(UFabricaObstaculos::CrearObstaculoSecundario, return nullptr;);
};
