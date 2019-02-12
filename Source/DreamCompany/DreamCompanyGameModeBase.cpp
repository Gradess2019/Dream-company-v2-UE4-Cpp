// Fill out your copyright notice in the Description page of Project Settings.

#include "DreamCompanyGameModeBase.h"
#include "Actors/PlayerCharacter.h"

ADreamCompanyGameModeBase::ADreamCompanyGameModeBase(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {

	DefaultPawnClass = APlayerCharacter::StaticClass();
}




