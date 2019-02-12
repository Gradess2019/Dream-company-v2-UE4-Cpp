// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseAppliance.h"
#include "FoodAppliance.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API AFoodAppliance : public ABaseAppliance
{
	GENERATED_BODY()
	
protected:

	//Uncomment when enum EQuality is created
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		EQuality quailityOfFood;

	//Uncomment when enum EQuality is created
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		EFoodType foodType;
	
	bool isFree;

	uint16 itemPrice;

	uint8 amountOfFood;

	uint8 energyIncrement;
	
};
