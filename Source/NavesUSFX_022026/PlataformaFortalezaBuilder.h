// PlataformaFortalezaBuilder.h
// ============================================================
//  BUILDER CONCRETO 2 — Plataforma Fortaleza
//  Muchas paredes, puertas controladas, alta resistencia.
//  Ideal para niveles defensivos o de jefe final.
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "PlataformaBuilder.h"
#include "FabricaPiso.h"
#include "FabricaPared.h"
#include "FabricaPuerta.h"
#include "PlataformaFortalezaBuilder.generated.h"

UCLASS()
class NAVESUSFX_022026_API UPlataformaFortalezaBuilder : public UPlataformaBuilder
{
    GENERATED_BODY()

public:
    virtual void Reiniciar(UWorld* Mundo, FVector PosicionBase) override;
    virtual void ConstruirPisos()   override;
    virtual void ConstruirParedes() override;
    virtual void ConstruirPuertas() override;

private:
    UPROPERTY()
    UFabricaPiso*   FabPiso;

    UPROPERTY()
    UFabricaPared*  FabPared;

    UPROPERTY()
    UFabricaPuerta* FabPuerta;
};
