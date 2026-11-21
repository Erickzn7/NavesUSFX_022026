// CTrampa.h  -  Componente concreto: Trampa
#pragma once
#include "CoreMinimal.h"
#include "ComponentePlataforma.h"
#include "CTrampa.generated.h"

UCLASS()
class NAVESUSFX_022026_API ACTrampa : public AComponentePlataforma
{
    GENERATED_BODY()
public:
    ACTrampa();

    // Dano que inflige al activarse
    UPROPERTY(EditAnywhere, Category = "Plataforma|Trampa")
    float DanoAlActivar;

    // Tiempo entre activaciones (segundos)
    UPROPERTY(EditAnywhere, Category = "Plataforma|Trampa")
    float IntervaloActivacion;

    virtual void BeginPlay() override;
    virtual void ComportamientoIndividual() override;
    virtual void ComportamientoGrupo(int32 TotalComponentes) override;

private:
    FTimerHandle TimerActivacion;
    bool bActivada;

    void Activar();
    void Desactivar();
};
