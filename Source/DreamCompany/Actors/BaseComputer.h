// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseAppliance.h"
#include "BaseComputer.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ABaseComputer : public ABaseAppliance
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		uint8 energyDecrement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		uint8 stressIncrement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		uint8 workingSpeed;

};