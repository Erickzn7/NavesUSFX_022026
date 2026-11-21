// PlataformaConstructor.cpp
// ============================================================
//  ACTOR CLIENTE — BeginPlay construye las tres plataformas
//  usando el Director con diferentes Builders concretos.
// ============================================================

#include "PlataformaConstructor.h"
#include "Engine/World.h"

APlataformaConstructor::APlataformaConstructor()
{
    PrimaryActorTick.bCanEverTick = false;

    SeparacionEntrePlataformas = 2000.0f;

    PlataformaSimple   = nullptr;
    PlataformaFortaleza = nullptr;
    PlataformaTrampas  = nullptr;
}

void APlataformaConstructor::BeginPlay()
{
    Super::BeginPlay();

    UWorld* Mundo = GetWorld();
    if (!Mundo) return;

    FVector BasePos = GetActorLocation();

    // ---- Crear el Director (unico, reutilizable) ----
    Director = NewObject<UPlataformaDirector>(this);

    // ---- Crear los builders concretos ----
    BuilderSimple    = NewObject<UPlataformaSimpleBuilder>(this);
    BuilderFortaleza = NewObject<UPlataformaFortalezaBuilder>(this);
    BuilderTrampas   = NewObject<UPlataformaTrampaBuilder>(this);

    // ============================================================
    //  CONSTRUCCION 1: Plataforma Simple
    //  Director usa el builder simple para la receta minima
    // ============================================================
    Director->EstablecerBuilder(BuilderSimple);
    PlataformaSimple = Director->ConstruirPlataformaMinima(
        Mundo, BasePos);

    if (PlataformaSimple)
    {
        PlataformaSimple->MostrarResumen();
    }

    // ============================================================
    //  CONSTRUCCION 2: Fortaleza
    //  Mismo director, builder diferente
    // ============================================================
    Director->EstablecerBuilder(BuilderFortaleza);
    PlataformaFortaleza = Director->ConstruirFortaleza(
        Mundo, BasePos + FVector(SeparacionEntrePlataformas, 0.0f, 0.0f));

    if (PlataformaFortaleza)
    {
        PlataformaFortaleza->MostrarResumen();
    }

    // ============================================================
    //  CONSTRUCCION 3: Nivel de Trampas
    //  Mismo director, builder diferente
    // ============================================================
    Director->EstablecerBuilder(BuilderTrampas);
    PlataformaTrampas = Director->ConstruirNivelTrampas(
        Mundo, BasePos + FVector(SeparacionEntrePlataformas * 2.0f, 0.0f, 0.0f));

    if (PlataformaTrampas)
    {
        PlataformaTrampas->MostrarResumen();
    }

    UE_LOG(LogTemp, Log,
        TEXT("[PlataformaConstructor] =============================="));
    UE_LOG(LogTemp, Log,
        TEXT("[PlataformaConstructor] 3 plataformas construidas con Builder:"));
    UE_LOG(LogTemp, Log,
        TEXT("  1. %s (%d comp.) en X=%.0f"),
        PlataformaSimple    ? *PlataformaSimple->NombrePlataforma    : TEXT("NULL"),
        PlataformaSimple    ? PlataformaSimple->TotalComponentes()   : 0,
        BasePos.X);
    UE_LOG(LogTemp, Log,
        TEXT("  2. %s (%d comp.) en X=%.0f"),
        PlataformaFortaleza ? *PlataformaFortaleza->NombrePlataforma  : TEXT("NULL"),
        PlataformaFortaleza ? PlataformaFortaleza->TotalComponentes() : 0,
        BasePos.X + SeparacionEntrePlataformas);
    UE_LOG(LogTemp, Log,
        TEXT("  3. %s (%d comp.) en X=%.0f"),
        PlataformaTrampas   ? *PlataformaTrampas->NombrePlataforma    : TEXT("NULL"),
        PlataformaTrampas   ? PlataformaTrampas->TotalComponentes()   : 0,
        BasePos.X + SeparacionEntrePlataformas * 2.0f);
    UE_LOG(LogTemp, Log,
        TEXT("[PlataformaConstructor] =============================="));
}
