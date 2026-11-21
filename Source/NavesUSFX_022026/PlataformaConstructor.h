// PlataformaConstructor.h
// ============================================================
//  LAB 07 - BUILDER
//  ACTOR CLIENTE — coloca las plataformas en el nivel.
//  Instancia el Director y los tres Builders concretos,
//  construye una plataforma de cada tipo y las expone
//  en el nivel separadas espacialmente.
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlataformaDirector.h"
#include "PlataformaSimpleBuilder.h"
#include "PlataformaFortalezaBuilder.h"
#include "PlataformaTrampaBuilder.h"
#include "PlataformaProducto.h"
#include "PlataformaConstructor.generated.h"

UCLASS()
class NAVESUSFX_022026_API APlataformaConstructor : public AActor
{
    GENERATED_BODY()

public:
    APlataformaConstructor();

protected:
    virtual void BeginPlay() override;

public:
    // Separacion entre plataformas en el eje X
    UPROPERTY(EditAnywhere, Category = "Builder|Config")
    float SeparacionEntrePlataformas;

    // Productos construidos (guardados para inspeccionar en editor)
    UPROPERTY(VisibleAnywhere, Category = "Builder|Resultado")
    UPlataformaProducto* PlataformaSimple;

    UPROPERTY(VisibleAnywhere, Category = "Builder|Resultado")
    UPlataformaProducto* PlataformaFortaleza;

    UPROPERTY(VisibleAnywhere, Category = "Builder|Resultado")
    UPlataformaProducto* PlataformaTrampas;

private:
    UPROPERTY()
    UPlataformaDirector* Director;

    UPROPERTY()
    UPlataformaSimpleBuilder* BuilderSimple;

    UPROPERTY()
    UPlataformaFortalezaBuilder* BuilderFortaleza;

    UPROPERTY()
    UPlataformaTrampaBuilder* BuilderTrampas;
};
