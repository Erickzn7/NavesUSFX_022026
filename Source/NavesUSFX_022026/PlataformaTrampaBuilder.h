// PlataformaTrampaBuilder.h
// ============================================================
//  BUILDER CONCRETO 3 — Plataforma de Trampas
//  Mezcla de trampolines y trampas para un nivel de obstaculos.
//  Pocos pisos, sin paredes, peligro maximo.
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "PlataformaBuilder.h"
#include "FabricaPiso.h"
#include "FabricaTrampolin.h"
#include "FabricaTrampa.h"
#include "PlataformaTrampaBuilder.generated.h"

UCLASS()
class NAVESUSFX_022026_API UPlataformaTrampaBuilder : public UPlataformaBuilder
{
    GENERATED_BODY()

public:
    virtual void Reiniciar(UWorld* Mundo, FVector PosicionBase) override;
    virtual void ConstruirPisos()       override;
    virtual void ConstruirTrampolines() override;
    virtual void ConstruirTrampas()     override;

private:
    UPROPERTY()
    UFabricaPiso*      FabPiso;

    UPROPERTY()
    UFabricaTrampolin* FabTrampolin;

    UPROPERTY()
    UFabricaTrampa*    FabTrampa;
};
