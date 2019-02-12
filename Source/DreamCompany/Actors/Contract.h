// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class ATeam;

#include "CoreMinimal.h"
#include "Actors/BaseActor.h"
#include "Contract.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API AContract : public ABaseActor
{
	GENERATED_BODY()
	
private:

	uint32 payment;

	uint8 time;
	uint8 requiredQuality;

	FDemandsStruct demands;

	ATeam* myTeam;	
	
};
