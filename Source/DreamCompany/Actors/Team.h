// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class ABaseEmployee;
class AProject;
class AContract;

#include "CoreMinimal.h"
#include "Actors/BaseActor.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include "Team.generated.h"



/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ATeam : public ABaseActor
{
	GENERATED_BODY()

private:
	FString name;
	
	FScheduleStruct schedule;

	TArray<ABaseEmployee*> employees;
	
	AProject* currentProject;

	AContract* currentContract;
	
};
