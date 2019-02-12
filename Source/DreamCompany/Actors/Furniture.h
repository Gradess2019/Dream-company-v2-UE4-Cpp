// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePlaceableActor.h"
#include "Furniture.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API AFurniture : public ABasePlaceableActor
{
	GENERATED_BODY()
	
protected:

	uint8 comfort;
};
