#include "Enemigo.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AEnemigo::AEnemigo()
{
	PrimaryActorTick.bCanEverTick = true;

	MallaEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigo"));
	RootComponent = MallaEnemigo;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cone.Cone"));
	if (MeshAsset.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(MeshAsset.Object);
	}

	Velocidad = 300.0f;
	Direccion = FVector(1.0f, 0.0f, 0.0f);
	LimiteX = 800.0f;
}

void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector PosicionActual = GetActorLocation();
	PosicionActual += Direccion * Velocidad * DeltaTime;

	if (PosicionActual.X > LimiteX)
	{
		Direccion.X = -1.0f;
	}
	else if (PosicionActual.X < -LimiteX)
	{
		Direccion.X = 1.0f;
	}

	SetActorLocation(PosicionActual);
}