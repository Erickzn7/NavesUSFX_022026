// ComponentePlataforma.h
// ============================================================
//  LAB 06 - FACTORY METHOD
//  Clase base de todos los componentes de plataforma
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComponentePlataforma.generated.h"

// Enumeracion de tipos de componentes de plataforma
UENUM(BlueprintType)
enum class ETipoComponente : uint8
{
    Piso        UMETA(DisplayName = "Piso"),
    Pared       UMETA(DisplayName = "Pared"),
    Puerta      UMETA(DisplayName = "Puerta"),
    Trampolin   UMETA(DisplayName = "Trampolin"),
    Trampa      UMETA(DisplayName = "Trampa")
};

UCLASS()
class NAVESUSFX_022026_API AComponentePlataforma : public AActor
{
    GENERATED_BODY()

public:
    AComponentePlataforma();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // ---- Malla visual ----
    UPROPERTY(VisibleAnywhere, Category = "Visual")
    UStaticMeshComponent* Malla;

    // ---- Propiedades del componente ----

    // Tipo del componente (enumeracion)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plataforma")
    ETipoComponente TipoComponente;

    // Numero unico del componente (clave del TMap)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Plataforma")
    int32 NumeroComponente;

    // Resistencia del componente
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plataforma")
    float Resistencia;

    // Si el componente esta activo
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plataforma")
    bool bActivo;

    // ---- Comportamientos ----

    // Comportamiento individual: cada subclase lo sobreescribe
    virtual void ComportamientoIndividual();

    // Comportamiento de grupo: llamado por el manager
    virtual void ComportamientoGrupo(int32 TotalComponentes);
};
