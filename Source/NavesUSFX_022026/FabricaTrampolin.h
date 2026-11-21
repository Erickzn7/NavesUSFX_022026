// FabricaTrampolin.h  -  Fabrica concreta: produce CTrampolin
#pragma once
#include "CoreMinimal.h"
#include "FabricaComponentePlataforma.h"
#include "FabricaTrampolin.generated.h"

UCLASS()
class NAVESUSFX_022026_API UFabricaTrampolin : public UFabricaComponentePlataforma
{
    GENERATED_BODY()
public:
    virtual AComponentePlataforma* CrearComponente(UWorld* Mundo, FVector Posicion, int32 NumeroUnico) override;
    virtual ETipoComponente ObtenerTipo() const override { return ETipoComponente::Trampolin; }
};
