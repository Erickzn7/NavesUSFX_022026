// FabricaPared.h  -  Fabrica concreta: produce CPared
#pragma once
#include "CoreMinimal.h"
#include "FabricaComponentePlataforma.h"
#include "FabricaPared.generated.h"

UCLASS()
class NAVESUSFX_022026_API UFabricaPared : public UFabricaComponentePlataforma
{
    GENERATED_BODY()
public:
    virtual AComponentePlataforma* CrearComponente(UWorld* Mundo, FVector Posicion, int32 NumeroUnico) override;
    virtual ETipoComponente ObtenerTipo() const override { return ETipoComponente::Pared; }
};
