// FabricaPuerta.h  -  Fabrica concreta: produce CPuerta
#pragma once
#include "CoreMinimal.h"
#include "FabricaComponentePlataforma.h"
#include "FabricaPuerta.generated.h"

UCLASS()
class NAVESUSFX_022026_API UFabricaPuerta : public UFabricaComponentePlataforma
{
    GENERATED_BODY()
public:
    virtual AComponentePlataforma* CrearComponente(UWorld* Mundo, FVector Posicion, int32 NumeroUnico) override;
    virtual ETipoComponente ObtenerTipo() const override { return ETipoComponente::Puerta; }
};
