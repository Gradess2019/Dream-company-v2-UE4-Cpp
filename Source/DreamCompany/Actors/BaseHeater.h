// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/ConsumeWaterActor.h"
#include "BaseHeater.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ABaseHeater : public AConsumeWaterActor
{
	GENERATED_BODY()
	
protected:
	uint8 temperatureIncrement;
	
	
};
