// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomPlayerController.h"
#include "Actors/BaseGrid.h"
#include "Actors/PlayerCharacter.h"
#include "Actors/BasePlaceableActor.h"
#include "Actors/BaseEdgePlaceableActor.h"

ACustomPlayerController::ACustomPlayerController() {
	this->bShowMouseCursor = true;
	this->bEnableMouseOverEvents = true;
	this->bEnableClickEvents = true;

	ConstructorHelpers::FObjectFinder<UCurveVector> Curve(TEXT("/Game/Miscellaneous/Curves/Zoom.Zoom"));
	vectorCurve = Curve.Object;

	currentGameMode = EGameMode::GM_Game;
	LOG("ACustomPlayerController constructed.");
}

class ABasePlaceableActor* ACustomPlayerController::getPlaceableActor() {
	return placeableActor;
}

class ABaseEdgePlaceableActor* ACustomPlayerController::getEdgePlaceableActor() {
	return edgePlaceableActor;
}

void ACustomPlayerController::BeginPlay() {
	Super::BeginPlay();
	playerCharacter = Cast<APlayerCharacter>(this->GetCharacter());
	if (isValidPlayer()) {
		playerCamera = Cast<UCameraComponent>(playerCharacter->
											  GetComponentByClass(UCameraComponent::StaticClass()));
	}
	check(isValidPlayerAndCamera());

	initializeZoomTimelines();
	if (isValidZoomInTimeline() && isValidZoomOutTimeline()) {
		LOG("Zoom Timelines initialized successfully.");
	}

}

void ACustomPlayerController::Tick(float deltaTime) {
	Super::Tick(deltaTime);

	this->setTickComponentToZoomTimelines(deltaTime);

}

//Controls
void ACustomPlayerController::SetupInputComponent() {
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ACustomPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACustomPlayerController::MoveRight);
	InputComponent->BindAxis("Turn", this, &ACustomPlayerController::Turn);

	InputComponent->BindAction("CaptureTurn", EInputEvent::IE_Pressed, this, &ACustomPlayerController::CapturedTurn);
	InputComponent->BindAction("CaptureTurn", EInputEvent::IE_Released, this, &ACustomPlayerController::UncapturedTurn);
	InputComponent->BindAction("ZoomIn", EInputEvent::IE_Pressed, this, &ACustomPlayerController::ZoomIn);
	InputComponent->BindAction("ZoomOut", EInputEvent::IE_Pressed, this, &ACustomPlayerController::ZoomOut);
	InputComponent->BindAction("ZoomOut", EInputEvent::IE_Pressed, this, &ACustomPlayerController::ZoomOut);
	InputComponent->BindAction("ShowAndHideGrid", EInputEvent::IE_Pressed, this, &ACustomPlayerController::ShowAndHideGrid);
	InputComponent->BindAction("LeftMouseButton", EInputEvent::IE_Pressed, this, &ACustomPlayerController::PressedLeftMouseButton);
	InputComponent->BindAction("LeftMouseButton", EInputEvent::IE_Released, this, &ACustomPlayerController::ReleasedLeftMouseButton);
	InputComponent->BindAction("OpenShop", EInputEvent::IE_Pressed, this, &ACustomPlayerController::OpenShop);


	LOG("All bindings were initialized successfully.");
}

void ACustomPlayerController::MoveForward(float Value) {
	if (Value != 0.0f) {
		playerCharacter->AddMovementInput(this->GetCharacter()->GetActorForwardVector(), Value);
	}
}

void ACustomPlayerController::MoveRight(float Value) {
	if (Value != 0.0f && isValidPlayer()) {
		playerCharacter->AddMovementInput(FRotator(0.f, 90.f, 0.f).RotateVector(this->GetCharacter()->GetActorForwardVector()), Value);
	}
}

void ACustomPlayerController::Turn(float Value) {
	if (Value != 0.0f && bTurnIsCaptured && isValidPlayer()) {
		playerCharacter->AddActorWorldRotation(FRotator(0.f, Value, 0.f));
	}
}

void ACustomPlayerController::CapturedTurn() {
	bTurnIsCaptured = true;
}

void ACustomPlayerController::UncapturedTurn() {
	bTurnIsCaptured = false;
}

void ACustomPlayerController::ZoomIn() {
	if (isValidPlayerAndCamera() && isValidZoomInTimeline() && isValidZoomInDistance()) {
		stopZoomTimelines();
		zoomInTimeline->PlayFromStart();
	}
}

void ACustomPlayerController::ZoomOut() {
	if (isValidPlayerAndCamera() && isValidZoomOutTimeline() && isValidZoomOutDistance()) {
		stopZoomTimelines();
		zoomOutTimeline->PlayFromStart();
	}
}

void ACustomPlayerController::ZoomInTimelineFunction(FVector val) {
	if (isValidCamera() && isValidZoomInDistance()) {
		playerCamera->AddRelativeLocation(val);
	}
}

void ACustomPlayerController::ZoomOutTimelineFunction(FVector val) {
	if (isValidCamera() && isValidZoomOutDistance()) {
		playerCamera->AddRelativeLocation(-val);
	}
}

void ACustomPlayerController::ShowAndHideGrid() {
	TArray<AActor*> grid = TArray<AActor*>();
	UGameplayStatics::GetAllActorsOfClass(this, ABaseGrid::StaticClass(), grid);

	for (AActor* gridCell : grid) {
		if (bIsShowGrid) {
			gridCell->SetActorHiddenInGame(true);
		}
		else {
			gridCell->SetActorHiddenInGame(false);
		}
	}

	if (bIsShowGrid) {
		bIsShowGrid = false;
	}
	else {
		bIsShowGrid = true;
	}
}

void ACustomPlayerController::PressedLeftMouseButton() {
	if (currentGameMode == EGameMode::GM_BuildingWalls && IsValid(edgePlaceableActor)) {
		edgePlaceableActor->getPlaceActorTimeline()->PlayFromStart();
		
	}
}

void ACustomPlayerController::ReleasedLeftMouseButton() {
	if (currentGameMode == EGameMode::GM_BuildingWalls && IsValid(edgePlaceableActor)) {
		edgePlaceableActor->getPlaceActorTimeline()->Stop();
		Cast<UStaticMeshComponent>(edgePlaceableActor->GetComponentByClass(UStaticMeshComponent::StaticClass()))->
			SetCollisionProfileName(FName("Wall"));
		edgePlaceableActor->setIsPlaced(true);
		currentGameMode = EGameMode::GM_PlacingWalls; 
		
		FActorSpawnParameters actorSpawnParameters = FActorSpawnParameters();
		actorSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		edgePlaceableActor = GetWorld()->SpawnActor<ABaseEdgePlaceableActor>(
			edgePlaceableActor->GetClass(), 
			FVector(0.f, 0.f, -500.f), 
			FRotator(0.f, 0.f, 0.f), 
			actorSpawnParameters
		);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("New Obj"));
		edgePlaceableActor->getPlaceActorTimeline()->PlayFromStart();
	}
}

void ACustomPlayerController::OpenShop() {
	if (currentGameMode == EGameMode::GM_Game) {
		currentGameMode = EGameMode::GM_Shop;
		LOG("Shop opened");
	}
}



//Zoom Timelines
void ACustomPlayerController::setTickComponentToZoomTimelines(float deltaTime) {
	if (isValidZoomInTimeline()) {
		zoomInTimeline->TickComponent(deltaTime, ELevelTick::LEVELTICK_TimeOnly, NULL);
	}

	if (isValidZoomOutTimeline()) {
		zoomOutTimeline->TickComponent(deltaTime, ELevelTick::LEVELTICK_TimeOnly, NULL);
	}
}

void ACustomPlayerController::stopZoomTimelines() {
	if (isValidZoomInTimeline() && isValidZoomOutTimeline()) {
		if (zoomInTimeline->IsPlaying()) {
			zoomInTimeline->Stop();
		}

		if (zoomOutTimeline->IsPlaying()) {
			zoomOutTimeline->Stop();
		}
	}
}

void ACustomPlayerController::initializeZoomTimelines() {
	zoomInTimeline = this->initializeZoomTimeline(FName("ZoomInTimelineFunction"));
	zoomOutTimeline = this->initializeZoomTimeline(FName("ZoomOutTimelineFunction"));
}

UTimelineComponent* ACustomPlayerController::initializeZoomTimeline(FName functionName) {
	if (vectorCurve != NULL) {
		
		UTimelineComponent* zoomTimeline = NewObject<UTimelineComponent>(this);
		zoomTimeline->CreationMethod = EComponentCreationMethod::UserConstructionScript;

		this->BlueprintCreatedComponents.Add(zoomTimeline);

		zoomTimeline->SetLooping(false);
		zoomTimeline->SetTimelineLength(1.f);
		zoomTimeline->SetTimelineLengthMode(ETimelineLengthMode::TL_LastKeyFrame);
		zoomTimeline->SetPlaybackPosition(0.f, true);

		FOnTimelineVector onTimeline;
		onTimeline.BindUFunction(this, functionName);

		zoomTimeline->AddInterpVector(vectorCurve, onTimeline);
		zoomTimeline->RegisterComponent();
		return zoomTimeline;

	}
	LOG_ERROR("vectorCurve is null!");
	checkNoEntry();
	return nullptr;
}

//Check
bool ACustomPlayerController::isValidZoomInDistance() {
	return (playerCharacter->getMinDistance()) > (playerCamera->RelativeLocation.X);
}

bool ACustomPlayerController::isValidZoomOutDistance() {
	return (playerCharacter->getMaxDistance()) < (playerCamera->RelativeLocation.X);
}

bool ACustomPlayerController::isValidZoomInTimeline() {
	if (IsValid(zoomInTimeline)) {
		return true;
	}
	else {
		LOG_ERROR("zoomInTimeline is null!");
		checkNoEntry();
		return false;
	}
}

bool ACustomPlayerController::isValidZoomOutTimeline() {
	if (IsValid(zoomOutTimeline)) {
		return true;
	}
	else {
		LOG_ERROR("zoomOutTimeline is null!");
		checkNoEntry();
		return false;
	}
}

bool ACustomPlayerController::isValidPlayer() {
	if (IsValid(playerCharacter)) {
		return true;
	}
	else {
		LOG_ERROR("playerCharacter is null!");
		checkNoEntry();
		return false;
	}
}

bool ACustomPlayerController::isValidCamera() {
	if (IsValid(playerCamera)) {
		return true;
	}
	else {
		LOG_ERROR("playerCamera is null!");
		checkNoEntry();
		return false;
	}
}

bool ACustomPlayerController::isValidPlayerAndCamera() {
	return isValidPlayer() && isValidCamera();
}