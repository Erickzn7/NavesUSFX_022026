// PlataformaDirector.h
// ============================================================
//  LAB 07 - BUILDER
//  DIRECTOR: sabe en que orden llamar los pasos del builder.
//  Tiene recetas predefinidas para cada tipo de plataforma.
//  El cliente solo elige la receta y obtiene el producto.
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlataformaBuilder.h"
#include "PlataformaProducto.h"
#include "PlataformaDirector.generated.h"

UCLASS()
class NAVESUSFX_022026_API UPlataformaDirector : public UObject
{
    GENERATED_BODY()

public:
    // Asigna el builder que el director debe usar
    void EstablecerBuilder(UPlataformaBuilder* Builder);

    // ============================================================
    //  RECETAS — el director decide el orden de los pasos
    // ============================================================

    // Receta 1: solo pisos y paredes (plataforma minima)
    UPlataformaProducto* ConstruirPlataformaMinima(UWorld* Mundo, FVector Posicion);

    // Receta 2: plataforma completa con pisos, paredes y puertas (fortaleza)
    UPlataformaProducto* ConstruirFortaleza(UWorld* Mundo, FVector Posicion);

    // Receta 3: plataforma de peligro con trampolines y trampas
    UPlataformaProducto* ConstruirNivelTrampas(UWorld* Mundo, FVector Posicion);

private:
    UPROPERTY()
    UPlataformaBuilder* BuilderActual;
};
