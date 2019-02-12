// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class ACustomPlayerController;
class ABaseGrid;

#include "CoreMinimal.h"
#include "Actors/BasePlaceableActor.h"

#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"

#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstance.h"

#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "BaseEdgePlaceableActor.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ABaseEdgePlaceableActor : public ABasePlaceableActor
{
	GENERATED_BODY()

public:

	class UTimelineComponent* getPlaceActorTimeline();

	void setGrid(ABaseGrid* grid) { this->currentGrid = grid; };
	void setIsPlaced(bool isPlaced) { this->isPlaced = isPlaced; };
	bool getIsPlaced() { return isPlaced; };

protected:
	bool isPlaced = false;

	UTimelineComponent * placeActorTimeline;

	ABaseGrid* currentGrid;

	ABaseEdgePlaceableActor();

	UStaticMeshComponent* meshComponent;

	UPROPERTY(EditDefaultsOnly)
		UStaticMesh* staticMesh;

	UPROPERTY(EditDefaultsOnly)
		TArray<UMaterialInstance*> materials;

	virtual void BeginPlay() override;

	virtual void Tick(float deltaTime) override;

	UFUNCTION()
		virtual void onClickedFunc(AActor* actor, FKey key) {};

	UFUNCTION()
		virtual void placeActor() {};

	virtual void initializePlaceActorTimeline() {};

};
