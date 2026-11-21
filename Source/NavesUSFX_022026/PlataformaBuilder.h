// PlataformaBuilder.h
// ============================================================
//  LAB 07 - BUILDER
//  BUILDER ABSTRACTO: define los pasos de construccion.
//  Cada metodo construye un "paso" de la plataforma.
//  Los builders concretos deciden cuantos y como.
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlataformaProducto.h"

// Fabricas del Lab 06 (reutilizadas)
#include "FabricaComponentePlataforma.h"
#include "PlataformaBuilder.generated.h"

UCLASS(Abstract)
class NAVESUSFX_022026_API UPlataformaBuilder : public UObject
{
    GENERATED_BODY()

public:
    // Reinicia el producto para poder construir uno nuevo
    virtual void Reiniciar(UWorld* Mundo, FVector PosicionBase);

    // ============================================================
    //  PASOS DEL BUILDER — cada subclase implementa los que necesita
    // ============================================================
    virtual void ConstruirPisos()      {}
    virtual void ConstruirParedes()    {}
    virtual void ConstruirPuertas()    {}
    virtual void ConstruirTrampolines(){}
    virtual void ConstruirTrampas()    {}

    // Devuelve el producto terminado y libera la referencia interna
    virtual UPlataformaProducto* ObtenerResultado();

protected:
    // Producto en construccion
    UPROPERTY()
    UPlataformaProducto* Producto;

    // Referencia al mundo (para poder spawnear actores)
    UWorld* Mundo;

    // Posicion base desde la que se colocan los componentes
    FVector PosicionBase;

    // Contador interno de IDs para mantener claves unicas
    int32 ContadorID;

    // Fabrica auxiliar: llama al Factory Method del Lab 06
    AComponentePlataforma* SpawnComponente(
        UFabricaComponentePlataforma* Fabrica,
        FVector Offset);
};
