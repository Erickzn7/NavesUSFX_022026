// OAqMina.cpp

#include "OAqMina.h"
#include "UObject/ConstructorHelpers.h"

AOAqMina::AOAqMina()
{
	TipoObstaculo = TEXT("Mina Submarina");
	Dano = 100.0f;
	Profundidad = -100.0f;

	// Esfera como mina
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (MeshAsset.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(MeshAsset.Object);
	}
}
