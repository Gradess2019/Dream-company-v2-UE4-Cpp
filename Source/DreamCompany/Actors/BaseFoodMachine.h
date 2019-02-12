// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/FoodAppliance.h"
#include "BaseFoodMachine.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ABaseFoodMachine : public AFoodAppliance
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float hangChance;
	
	
};
