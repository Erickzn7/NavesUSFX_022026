// OTPared.cpp

#include "OTPared.h"
#include "UObject/ConstructorHelpers.h"

AOTPared::AOTPared()
{
	TipoObstaculo = TEXT("Pared de Piedra");
	Dano = 30.0f;
	bBloqueo = true;

	// Cubo aplanado como pared
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MeshAsset.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(MeshAsset.Object);
		MallaObstaculo->SetRelativeScale3D(FVector(0.5f, 4.0f, 3.0f));
	}
}
