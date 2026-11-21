// OTArbol.cpp

#include "OTArbol.h"
#include "UObject/ConstructorHelpers.h"

AOTArbol::AOTArbol()
{
	TipoObstaculo = TEXT("Arbol");
	Dano = 15.0f;
	bBloqueo = true;

	// Cono representa tronco/copa del árbol
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
		TEXT("/Engine/BasicShapes/Cone.Cone"));
	if (MeshAsset.Succeeded())
	{
		MallaObstaculo->SetStaticMesh(MeshAsset.Object);
		MallaObstaculo->SetRelativeScale3D(FVector(1.0f, 1.0f, 2.5f));
	}
}
