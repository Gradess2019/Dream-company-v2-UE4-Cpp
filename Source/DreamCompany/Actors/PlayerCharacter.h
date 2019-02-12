// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class ACustomPlayerController;

#include "CoreMinimal.h"
#include "Actors/BasePawn.h"
#include "Controllers/CustomPlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API APlayerCharacter : public ABasePawn
{
	GENERATED_BODY()
public:
	APlayerCharacter();

	float getMinDistance() { return minDistance; }

	float getMaxDistance() { return maxDistance; }

	float getZoomNumber() { return zoomNumber; }
	
protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Camera Settings")
		float minDistance;

	UPROPERTY(EditDefaultsOnly, Category = "Camera Settings")
		float maxDistance;

	UPROPERTY(EditDefaultsOnly, Category = "Camera Settings")
		float zoomNumber;
};
