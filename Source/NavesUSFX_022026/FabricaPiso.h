// FabricaPiso.h  -  Fabrica concreta: produce CPiso
#pragma once
#include "CoreMinimal.h"
#include "FabricaComponentePlataforma.h"
#include "FabricaPiso.generated.h"

UCLASS()
class NAVESUSFX_022026_API UFabricaPiso : public UFabricaComponentePlataforma
{
    GENERATED_BODY()
public:
    virtual AComponentePlataforma* CrearComponente(UWorld* Mundo, FVector Posicion, int32 NumeroUnico) override;
    virtual ETipoComponente ObtenerTipo() const override { return ETipoComponente::Piso; }
};
