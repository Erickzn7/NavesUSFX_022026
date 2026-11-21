// OAqIceberg.cpp

#include "OAqIceberg.h"
#include "UObject/ConstructorHelpers.h"

AOAqIceberg::AOAqIceberg()
{
	TipoObstaculo = TEXT("Iceberg");
	Dano = 50.0f;
	Profundidad = -200.0f;

	// Cono invertido como iceberg
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("/Engine/BasicShapes/Cone.Cone"));
	if (MeshAsset.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(MeshAsset.Object);
		MallaObstaculo->SetRelativeScale3D(FVector(2.0f, 2.0f, 3.0f));
	}
}
