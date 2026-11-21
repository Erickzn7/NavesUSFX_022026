// PlataformaProducto.cpp

#include "PlataformaProducto.h"

UPlataformaProducto::UPlataformaProducto()
{
    NombrePlataforma = TEXT("Sin nombre");
    Descripcion      = TEXT("Plataforma generica");
}

void UPlataformaProducto::AgregarComponente(int32 Clave, AComponentePlataforma* Componente)
{
    if (!Componente) return;

    // Verificar que la clave sea unica
    if (Componentes.Contains(Clave))
    {
        UE_LOG(LogTemp, Warning,
            TEXT("[Producto] Clave #%d ya existe — componente no agregado"), Clave);
        return;
    }

    Componentes.Add(Clave, Componente);
}

void UPlataformaProducto::MostrarResumen() const
{
    UE_LOG(LogTemp, Log,
        TEXT("============================================"));
    UE_LOG(LogTemp, Log,
        TEXT(" PLATAFORMA: %s"), *NombrePlataforma);
    UE_LOG(LogTemp, Log,
        TEXT(" Descripcion: %s"), *Descripcion);
    UE_LOG(LogTemp, Log,
        TEXT(" Total de componentes: %d"), Componentes.Num());

    for (const auto& Par : Componentes)
    {
        if (IsValid(Par.Value))
        {
            UE_LOG(LogTemp, Log,
                TEXT("   [#%d] Tipo: %d | Resistencia: %.0f | Activo: %s"),
                Par.Key,
                (int32)Par.Value->TipoComponente,
                Par.Value->Resistencia,
                Par.Value->bActivo ? TEXT("SI") : TEXT("NO"));
        }
    }

    UE_LOG(LogTemp, Log,
        TEXT("============================================"));
}
