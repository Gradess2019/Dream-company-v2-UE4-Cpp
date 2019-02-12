// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Furniture.h"
#include "Decoration.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ADecoration : public AFurniture
{
	GENERATED_BODY()
	
protected:
	uint8 cosiness;
};
