// OANube.cpp

#include "OANube.h"
#include "UObject/ConstructorHelpers.h"

AOANube::AOANube()
{
	TipoObstaculo = TEXT("Nube de Tormenta");
	Dano = 5.0f;
	Altitud = 800.0f;

	// Cubo escalado simula nube
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MeshAsset.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(MeshAsset.Object);
		MallaObstaculo->SetRelativeScale3D(FVector(3.0f, 3.0f, 0.5f));
	}
}
