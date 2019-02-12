// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/ConsumeWaterActor.h"
#include "BasePlant.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ABasePlant : public AConsumeWaterActor
{
	GENERATED_BODY()
	
protected:
	uint8 amountOfWater;
	
	
};
