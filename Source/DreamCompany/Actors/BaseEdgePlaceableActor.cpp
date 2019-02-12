// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseEdgePlaceableActor.h"
#include "Controllers/CustomPlayerController.h"
#include "Actors/BaseGrid.h"

ABaseEdgePlaceableActor::ABaseEdgePlaceableActor() {
	this->SetActorTickInterval(0.2f);
}

void ABaseEdgePlaceableActor::BeginPlay() {
	Super::BeginPlay();

	OnClicked.AddDynamic(this, &ABaseEdgePlaceableActor::onClickedFunc);
	initializePlaceActorTimeline();
}

void ABaseEdgePlaceableActor::Tick(float deltaTime) {
	Super::Tick(deltaTime);

	if (placeActorTimeline != NULL) {
		placeActorTimeline->TickComponent(deltaTime, ELevelTick::LEVELTICK_TimeOnly, NULL);
	}
}

class UTimelineComponent* ABaseEdgePlaceableActor::getPlaceActorTimeline() {
	return placeActorTimeline;
}
