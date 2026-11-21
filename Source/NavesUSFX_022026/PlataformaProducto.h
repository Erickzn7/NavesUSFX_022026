// PlataformaProducto.h
// ============================================================
//  LAB 07 - BUILDER
//  PRODUCTO: resultado final que el Builder construye.
//  Contiene el TMap de componentes ya creados (reutiliza Lab 06)
//  y metadatos descriptivos de la plataforma.
// ============================================================

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ComponentePlataforma.h"
#include "PlataformaProducto.generated.h"

UCLASS(BlueprintType)
class NAVESUSFX_022026_API UPlataformaProducto : public UObject
{
    GENERATED_BODY()

public:
    UPlataformaProducto();

    // Nombre descriptivo de la plataforma construida
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Plataforma|Builder")
    FString NombrePlataforma;

    // Descripcion del tipo de plataforma
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Plataforma|Builder")
    FString Descripcion;

    // TMap: clave = numero unico de componente, valor = actor en escena
    UPROPERTY(VisibleAnywhere, Category = "Plataforma|Builder")
    TMap<int32, AComponentePlataforma*> Componentes;

    // Agrega un componente al producto (llamado por los builders)
    void AgregarComponente(int32 Clave, AComponentePlataforma* Componente);

    // Muestra en log el resumen completo del producto
    void MostrarResumen() const;

    // Retorna cuantos componentes tiene
    int32 TotalComponentes() const { return Componentes.Num(); }
};
