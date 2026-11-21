// PlataformaBuilder.cpp

#include "PlataformaBuilder.h"
#include "Engine/World.h"

void UPlataformaBuilder::Reiniciar(UWorld* InMundo, FVector InPosicionBase)
{
    Mundo        = InMundo;
    PosicionBase = InPosicionBase;
    ContadorID   = 1;

    // Crear producto nuevo en cada construccion
    Producto = NewObject<UPlataformaProducto>(this);
}

UPlataformaProducto* UPlataformaBuilder::ObtenerResultado()
{
    UPlataformaProducto* Resultado = Producto;
    Producto = nullptr;   // liberar referencia interna
    return Resultado;
}

AComponentePlataforma* UPlataformaBuilder::SpawnComponente(
    UFabricaComponentePlataforma* Fabrica, FVector Offset)
{
    if (!Fabrica || !Mundo) return nullptr;

    int32 ID = ContadorID++;
    FVector Pos = PosicionBase + Offset;

    AComponentePlataforma* Comp = Fabrica->CrearComponente(Mundo, Pos, ID);
    if (Comp)
    {
        Producto->AgregarComponente(ID, Comp);
    }
    return Comp;
}
