// CPuerta.h  -  Componente concreto: Puerta
#pragma once
#include "CoreMinimal.h"
#include "ComponentePlataforma.h"
#include "CPuerta.generated.h"

UCLASS()
class NAVESUSFX_022026_API ACPuerta : public AComponentePlataforma
{
    GENERATED_BODY()
public:
    ACPuerta();

    // La puerta puede estar abierta o cerrada
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plataforma|Puerta")
    bool bEstaAbierta;

    // Tiempo en segundos que tarda en cerrarse
    UPROPERTY(EditAnywhere, Category = "Plataforma|Puerta")
    float TiempoCierre;

    virtual void BeginPlay() override;
    virtual void ComportamientoIndividual() override;
    virtual void ComportamientoGrupo(int32 TotalComponentes) override;

    void Abrir();
    void Cerrar();

private:
    FTimerHandle TimerCierre;
};
