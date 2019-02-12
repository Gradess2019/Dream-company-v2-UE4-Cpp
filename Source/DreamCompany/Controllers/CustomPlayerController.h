// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Curves/CurveVector.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"

#include "Runtime/Core/Public/Containers/Array.h"

#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

#include "CustomPlayerController.generated.h"

class APlayerCharacter;
class ABasePlaceableActor;
class ABaseEdgePlaceableActor;
class ABaseGrid;

/**
 * Main Player controller
 */
UCLASS()
class DREAMCOMPANY_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	

	ACustomPlayerController();

	class ABasePlaceableActor* getPlaceableActor();
	class ABaseEdgePlaceableActor* getEdgePlaceableActor();
	EGameMode getCurrentGameMode() { return currentGameMode; };

	void setEdgePlaceableActor(ABaseEdgePlaceableActor* newActor) { edgePlaceableActor = newActor; };
	void setCurrentGameMode(EGameMode newGameMode) { currentGameMode = newGameMode; };
	
protected:

	UFUNCTION()
		virtual void BeginPlay() override;

	UFUNCTION()
		virtual void Tick(float deltaTime) override;

	UFUNCTION()
		virtual void SetupInputComponent() override;
		
private:
	APlayerCharacter * playerCharacter;
	UCameraComponent* playerCamera;

	UTimelineComponent * zoomInTimeline;
	UTimelineComponent * zoomOutTimeline;
	
	UCurveVector* vectorCurve;

	ABasePlaceableActor* placeableActor;
	ABaseEdgePlaceableActor* edgePlaceableActor;

	bool bTurnIsCaptured = false;
	bool bIsShowGrid = false;

	EGameMode currentGameMode;

	//Controls
	UFUNCTION()
		void MoveForward(float Val);

	UFUNCTION()
		void MoveRight(float Val);

	UFUNCTION()
		void Turn(float Val);

	UFUNCTION()
		void CapturedTurn();

	UFUNCTION()
		void UncapturedTurn();

	UFUNCTION()
		void ZoomIn();

	UFUNCTION()
		void ZoomOut();

	UFUNCTION()
		void ZoomInTimelineFunction(FVector val);

	UFUNCTION()
		void ZoomOutTimelineFunction(FVector val);

	UFUNCTION()
		void ShowAndHideGrid();

	UFUNCTION()
		void PressedLeftMouseButton();

	UFUNCTION()
		void ReleasedLeftMouseButton();

	UFUNCTION()
		void OpenShop();

	//Zoom Timelines
	void setTickComponentToZoomTimelines(float deltaTime);
	void stopZoomTimelines();
	void initializeZoomTimelines();
	UTimelineComponent* initializeZoomTimeline(FName functionName);

	//Check
	bool isValidZoomInDistance();
	bool isValidZoomOutDistance();
	bool isValidZoomInTimeline();
	bool isValidZoomOutTimeline();
	bool isValidPlayer();
	bool isValidCamera();
	bool isValidPlayerAndCamera();
};
