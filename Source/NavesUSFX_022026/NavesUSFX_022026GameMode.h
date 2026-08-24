// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NavesUSFX_022026GameMode.generated.h"

UCLASS(MinimalAPI)
class ANavesUSFX_022026GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANavesUSFX_022026GameMode();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, Category = "Juego")
	TArray<class AEnemigo*> Enemigos;
};



