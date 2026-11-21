// PlataformaSimpleBuilder.h
// ============================================================
//  BUILDER CONCRETO 1 — Plataforma Simple
//  Solo pisos y paredes basicos. Ideal para niveles iniciales.
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "PlataformaBuilder.h"
#include "FabricaPiso.h"
#include "FabricaPared.h"
#include "PlataformaSimpleBuilder.generated.h"

UCLASS()
class NAVESUSFX_022026_API UPlataformaSimpleBuilder : public UPlataformaBuilder
{
    GENERATED_BODY()

public:
    virtual void Reiniciar(UWorld* Mundo, FVector PosicionBase) override;
    virtual void ConstruirPisos()   override;
    virtual void ConstruirParedes() override;

private:
    UPROPERTY()
    UFabricaPiso*  FabPiso;

    UPROPERTY()
    UFabricaPared* FabPared;
};
