// ComponentePlataforma.cpp

#include "ComponentePlataforma.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AComponentePlataforma::AComponentePlataforma()
{
    PrimaryActorTick.bCanEverTick = true;

    Malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
    RootComponent = Malla;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
        TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (MeshAsset.Succeeded())
    {
        Malla->SetStaticMesh(MeshAsset.Object);
    }

    TipoComponente   = ETipoComponente::Piso;
    NumeroComponente = 0;
    Resistencia      = 100.0f;
    bActivo          = true;
}

void AComponentePlataforma::BeginPlay()
{
    Super::BeginPlay();
    ComportamientoIndividual();
}

void AComponentePlataforma::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AComponentePlataforma::ComportamientoIndividual()
{
    UE_LOG(LogTemp, Log,
        TEXT("[CP #%d] Comportamiento individual base (Tipo: %d)"),
        NumeroComponente, (int32)TipoComponente);
}

void AComponentePlataforma::ComportamientoGrupo(int32 TotalComponentes)
{
    UE_LOG(LogTemp, Log,
        TEXT("[CP #%d] Comportamiento de grupo — total en escena: %d"),
        NumeroComponente, TotalComponentes);
}
