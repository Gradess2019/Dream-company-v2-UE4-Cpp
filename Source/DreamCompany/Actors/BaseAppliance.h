// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/ElectricalActor.h"
#include "BaseAppliance.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ABaseAppliance : public AElectricalActor
{
	GENERATED_BODY()
	
protected:

	bool isBusy;

	uint8 stressDecrement;
	
	
};
