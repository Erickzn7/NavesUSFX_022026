// OARoca.cpp

#include "OARoca.h"
#include "UObject/ConstructorHelpers.h"

AOARoca::AOARoca()
{
	TipoObstaculo = TEXT("Roca Flotante");
	Dano = 20.0f;
	Altitud = 600.0f;

	// Esfera como representación visual de roca
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (MeshAsset.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(MeshAsset.Object);
	}
}
