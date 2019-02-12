// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseEdgePlaceableActor.h"
#include "BaseWall.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ABaseWall : public ABaseEdgePlaceableActor
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	
private:

	UFUNCTION()
		virtual void onClickedFunc(AActor* actor, FKey key) override;

	UFUNCTION()
		virtual void placeActor() override;

	virtual void initializePlaceActorTimeline() override;
};
