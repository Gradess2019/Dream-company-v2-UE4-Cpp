// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseActor.h"
#include "Actors/BaseGrid.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "GridConstructor.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API AGridConstructor : public ABaseActor
{
	GENERATED_BODY()
	
public:

	AGridConstructor();

protected:

	virtual void BeginPlay() override;

private:
	TArray<ABaseGrid*> grid;

	UPROPERTY(EditDefaultsOnly, Category = "Grid settings")
		TSubclassOf<ABaseGrid> gridCellClass;

	UPROPERTY(EditInstanceOnly, Category = "Grid settings")
		AGridConstructor* ownerActor;

	UPROPERTY(EditInstanceOnly)
		uint8 X;

	UPROPERTY(EditInstanceOnly)
		uint8 Y;

	UPROPERTY(EditInstanceOnly)
		float edgeSize;

	float defaultEdgeSize;
	float defaultScaleValue;


};
