// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseActor.h"
#include "Actors/Contract.h"
#include "GlobalData.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API AGlobalData : public ABaseActor
{
	GENERATED_BODY()
	
private:
	
	uint64 totalMoney;

	uint16 time;

	//Uncomment when struct DateStruct is created
	//DateStruct date;

	TArray<AContract*> availableContracts;

	float rating;
	
	
};
