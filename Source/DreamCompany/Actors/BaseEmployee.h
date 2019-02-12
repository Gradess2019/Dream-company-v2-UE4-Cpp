// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class ATeam;

#include "CoreMinimal.h"
#include "Actors/BasePawn.h"
#include "BaseEmployee.generated.h"



/**
 *
 */
UCLASS()
class DREAMCOMPANY_API ABaseEmployee : public ABasePawn
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly)
		uint8 stressIncrement;

	UPROPERTY(EditDefaultsOnly)
		uint16 salary;

	float energy;
	float stress;
	float mood;

	uint8 foodCondition;
	uint8 waterCondition;
	uint8 toilet;
	uint8 type;
	uint8 position;

	FSkillsStruct skills;
	FScheduleStruct schedule;

	ATeam* team;

};
