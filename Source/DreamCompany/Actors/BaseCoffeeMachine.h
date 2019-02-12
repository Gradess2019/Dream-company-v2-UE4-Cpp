// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/ConsumeWaterAppliance.h"
#include "BaseCoffeeMachine.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ABaseCoffeeMachine : public AConsumeWaterAppliance
{
	GENERATED_BODY()
	
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		uint8 cookingSpeed;
	
};
