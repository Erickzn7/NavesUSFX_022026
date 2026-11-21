// CPared.h  -  Componente concreto: Pared
#pragma once
#include "CoreMinimal.h"
#include "ComponentePlataforma.h"
#include "CPared.generated.h"

UCLASS()
class NAVESUSFX_022026_API ACPared : public AComponentePlataforma
{
    GENERATED_BODY()
public:
    ACPared();

    // La pared puede ser destructible
    UPROPERTY(EditAnywhere, Category = "Plataforma|Pared")
    bool bEsDestructible;

    virtual void ComportamientoIndividual() override;
    virtual void ComportamientoGrupo(int32 TotalComponentes) override;

    // Recibe dano
    void RecibirDano(float Cantidad);
};
