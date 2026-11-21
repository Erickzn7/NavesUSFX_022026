// PlataformaDirector.cpp
// El Director orquesta el orden exacto de los pasos.
// Cambia el builder sin modificar ninguna receta.

#include "PlataformaDirector.h"

void UPlataformaDirector::EstablecerBuilder(UPlataformaBuilder* Builder)
{
    BuilderActual = Builder;
}

// ----------------------------------------------------------------
// Receta 1: Plataforma Minima — solo pisos y paredes
// ----------------------------------------------------------------
UPlataformaProducto* UPlataformaDirector::ConstruirPlataformaMinima(
    UWorld* Mundo, FVector Posicion)
{
    if (!BuilderActual) return nullptr;

    BuilderActual->Reiniciar(Mundo, Posicion);

    // Orden de construccion definido por el Director
    BuilderActual->ConstruirPisos();
    BuilderActual->ConstruirParedes();

    UPlataformaProducto* Resultado = BuilderActual->ObtenerResultado();

    UE_LOG(LogTemp, Log,
        TEXT("[Director] Plataforma Minima construida: %d componentes"),
        Resultado ? Resultado->TotalComponentes() : 0);

    return Resultado;
}

// ----------------------------------------------------------------
// Receta 2: Fortaleza — pisos reforzados + paredes + puertas
// ----------------------------------------------------------------
UPlataformaProducto* UPlataformaDirector::ConstruirFortaleza(
    UWorld* Mundo, FVector Posicion)
{
    if (!BuilderActual) return nullptr;

    BuilderActual->Reiniciar(Mundo, Posicion);

    // El Director controla el orden: primero la estructura, luego accesos
    BuilderActual->ConstruirPisos();
    BuilderActual->ConstruirParedes();
    BuilderActual->ConstruirPuertas();

    UPlataformaProducto* Resultado = BuilderActual->ObtenerResultado();

    UE_LOG(LogTemp, Log,
        TEXT("[Director] Fortaleza construida: %d componentes"),
        Resultado ? Resultado->TotalComponentes() : 0);

    return Resultado;
}

// ----------------------------------------------------------------
// Receta 3: Nivel de Trampas — pisos + trampolines + trampas
// ----------------------------------------------------------------
UPlataformaProducto* UPlataformaDirector::ConstruirNivelTrampas(
    UWorld* Mundo, FVector Posicion)
{
    if (!BuilderActual) return nullptr;

    BuilderActual->Reiniciar(Mundo, Posicion);

    // Primero la base, luego los peligros
    BuilderActual->ConstruirPisos();
    BuilderActual->ConstruirTrampolines();
    BuilderActual->ConstruirTrampas();

    UPlataformaProducto* Resultado = BuilderActual->ObtenerResultado();

    UE_LOG(LogTemp, Log,
        TEXT("[Director] Nivel de Trampas construido: %d componentes"),
        Resultado ? Resultado->TotalComponentes() : 0);

    return Resultado;
}
