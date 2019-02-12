// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseAppliance.h"
#include "EntertainmentAppliance.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API AEntertainmentAppliance : public ABaseAppliance
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		uint8 stressDecrementMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		uint8 maxEmployees;
	
};
