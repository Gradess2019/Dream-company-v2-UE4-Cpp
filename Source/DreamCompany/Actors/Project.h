// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class ATeam;

#include "CoreMinimal.h"
#include "Actors/BaseActor.h"
#include "Project.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API AProject : public ABaseActor
{
	GENERATED_BODY()
	
private:
	FString name;

	uint8 time;
	uint8 projectType;
	uint8 projectSize;
	uint8 estimatedQuality;
	
	FDemandsStruct demands;

	uint32 estimatedUsers;

	ATeam* myTeam;
	
};
