// FabricaComponentePlataforma.h
// ============================================================
//  LAB 06 - FACTORY METHOD
//  Creator abstracto — define el metodo fabrica
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ComponentePlataforma.h"
#include "FabricaComponentePlataforma.generated.h"

UCLASS(Abstract)
class NAVESUSFX_022026_API UFabricaComponentePlataforma : public UObject
{
    GENERATED_BODY()

public:
    // ===== FACTORY METHOD =====
    // Cada fábrica concreta sabe qué subclase crear.
    // El cliente solo llama a este método.
    virtual AComponentePlataforma* CrearComponente(
        UWorld* Mundo,
        FVector Posicion,
        int32 NumeroUnico) PURE_VIRTUAL(UFabricaComponentePlataforma::CrearComponente, return nullptr;);

    // Tipo que produce esta fabrica
    virtual ETipoComponente ObtenerTipo() const PURE_VIRTUAL(UFabricaComponentePlataforma::ObtenerTipo, return ETipoComponente::Piso;);
};
