// CPiso.h  -  Componente concreto: Piso
#pragma once
#include "CoreMinimal.h"
#include "ComponentePlataforma.h"
#include "CPiso.generated.h"

UCLASS()
class NAVESUSFX_022026_API ACPiso : public AComponentePlataforma
{
    GENERATED_BODY()
public:
    ACPiso();

    // Comportamiento individual: el piso puede moverse horizontalmente
    UPROPERTY(EditAnywhere, Category = "Plataforma|Piso")
    bool bEsMovil;

    UPROPERTY(EditAnywhere, Category = "Plataforma|Piso")
    float VelocidadMovimiento;

    virtual void Tick(float DeltaTime) override;
    virtual void ComportamientoIndividual() override;
    virtual void ComportamientoGrupo(int32 TotalComponentes) override;

private:
    FVector DireccionMovimiento;
};
