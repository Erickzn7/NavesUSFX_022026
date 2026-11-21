// FabricaTrampa.h  -  Fabrica concreta: produce CTrampa
#pragma once
#include "CoreMinimal.h"
#include "FabricaComponentePlataforma.h"
#include "FabricaTrampa.generated.h"

UCLASS()
class NAVESUSFX_022026_API UFabricaTrampa : public UFabricaComponentePlataforma
{
    GENERATED_BODY()
public:
    virtual AComponentePlataforma* CrearComponente(UWorld* Mundo, FVector Posicion, int32 NumeroUnico) override;
    virtual ETipoComponente ObtenerTipo() const override { return ETipoComponente::Trampa; }
};
