// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/FoodAppliance.h"
#include "ConsumeWaterAppliance.generated.h"

/**
 *
 */
UCLASS()
class DREAMCOMPANY_API AConsumeWaterAppliance : public AFoodAppliance
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		uint8 waterConsumption;


};
