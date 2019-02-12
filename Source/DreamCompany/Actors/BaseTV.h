// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/EntertainmentAppliance.h"
#include "BaseTV.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ABaseTV : public AEntertainmentAppliance
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		uint8 numOfChannels;
	
	
};
