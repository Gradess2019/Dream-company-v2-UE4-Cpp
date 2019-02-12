// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/ElectricalActor.h"
#include "BaseVentilation.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ABaseVentilation : public AElectricalActor
{
	GENERATED_BODY()
	
protected:
	uint8 temperatureDecrement;
	
};
