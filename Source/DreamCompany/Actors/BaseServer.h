// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/ElectricalActor.h"
#include "Actors/Team.h"
#include "BaseServer.generated.h"

/**
 *
 */
UCLASS()
class DREAMCOMPANY_API ABaseServer : public AElectricalActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		uint8 workingSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		uint8 maxLoad;

	uint8 currentLoad;

	ATeam* teamOwner;

};
