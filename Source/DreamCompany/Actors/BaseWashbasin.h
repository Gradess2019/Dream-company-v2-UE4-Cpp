// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/ConsumeWaterActor.h"
#include "BaseWashbasin.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ABaseWashbasin : public AConsumeWaterActor
{
	GENERATED_BODY()
	
protected:
	uint8 employeeTemperatureDecrement;
	
	
};
