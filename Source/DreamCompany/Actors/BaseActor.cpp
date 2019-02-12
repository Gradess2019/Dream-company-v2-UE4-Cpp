// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseActor.h"
DEFINE_LOG_CATEGORY(DreamCompanyLog);

ABaseActor::ABaseActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}