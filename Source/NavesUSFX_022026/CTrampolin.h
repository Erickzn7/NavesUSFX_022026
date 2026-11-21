// CTrampolin.h  -  Componente concreto: Trampolin
#pragma once
#include "CoreMinimal.h"
#include "ComponentePlataforma.h"
#include "CTrampolin.generated.h"

UCLASS()
class NAVESUSFX_022026_API ACTrampolin : public AComponentePlataforma
{
    GENERATED_BODY()
public:
    ACTrampolin();

    // Fuerza de impulso que aplica al jugador
    UPROPERTY(EditAnywhere, Category = "Plataforma|Trampolin")
    float FuerzaImpulso;

    virtual void ComportamientoIndividual() override;
    virtual void ComportamientoGrupo(int32 TotalComponentes) override;

    // Aplica el impulso a un actor
    void AplicarImpulso(AActor* Actor);
};
