// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Actors/PlayerCharacter.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "DreamCompanyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ADreamCompanyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	ADreamCompanyGameModeBase(const FObjectInitializer& ObjectInitializer);  // Our added constructor

	//virtual void StartPlay() override;
};
