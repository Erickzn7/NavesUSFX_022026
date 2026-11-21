// Obstaculo.cpp

#include "Obstaculo.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AObstaculo::AObstaculo()
{
	PrimaryActorTick.bCanEverTick = false;

	MallaObstaculo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaObstaculo"));
	RootComponent = MallaObstaculo;

	// Malla por defecto: cubo básico de Unreal
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MeshAsset.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(MeshAsset.Object);
	}

	Dano = 10.0f;
	TipoObstaculo = TEXT("Generico");
}

void AObstaculo::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("Obstaculo spawneado: %s"), *TipoObstaculo);
}

void AObstaculo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
