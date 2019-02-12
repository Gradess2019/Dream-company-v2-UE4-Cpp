// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Actors/BaseActor.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "BasePawn.generated.h"

/**
 * Base Pawn for Player and NPCs
 */
UCLASS()
class DREAMCOMPANY_API ABasePawn : public ACharacter
{
	GENERATED_BODY()
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float walkingSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float rotateSpeed;
};
