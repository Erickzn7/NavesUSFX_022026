// PlataformaSimpleBuilder.cpp

#include "PlataformaSimpleBuilder.h"

void UPlataformaSimpleBuilder::Reiniciar(UWorld* InMundo, FVector InPosBase)
{
    Super::Reiniciar(InMundo, InPosBase);

    Producto->NombrePlataforma = TEXT("Plataforma Simple");
    Producto->Descripcion      = TEXT("Plataforma basica: pisos y paredes sin peligros.");

    FabPiso  = NewObject<UFabricaPiso>(this);
    FabPared = NewObject<UFabricaPared>(this);
}

void UPlataformaSimpleBuilder::ConstruirPisos()
{
    // 3 pisos alineados en Y
    for (int32 i = 0; i < 3; i++)
    {
        SpawnComponente(FabPiso, FVector(0.0f, i * 400.0f, 0.0f));
    }

    UE_LOG(LogTemp, Log,
        TEXT("[SimpleBuilder] 3 pisos construidos"));
}

void UPlataformaSimpleBuilder::ConstruirParedes()
{
    // 2 paredes laterales
    SpawnComponente(FabPared, FVector(200.0f, -50.0f, 150.0f));
    SpawnComponente(FabPared, FVector(200.0f, 850.0f, 150.0f));

    UE_LOG(LogTemp, Log,
        TEXT("[SimpleBuilder] 2 paredes laterales construidas"));
}
