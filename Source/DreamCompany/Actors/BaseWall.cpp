// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseWall.h"

void ABaseWall::BeginPlay() {
	Super::BeginPlay();
}

void ABaseWall::Tick(float deltaTime) {
	Super::Tick(deltaTime);
}

void ABaseWall::onClickedFunc(AActor* actor, FKey key) {
	if (!isPlaced) {
		ACustomPlayerController* playerController =
			Cast<ACustomPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

		if ((playerController != NULL) && (playerController->getEdgePlaceableActor() == NULL) &&
			(playerController->getCurrentGameMode() == EGameMode::GM_Shop) && (placeActorTimeline != NULL)) {

			UStaticMeshComponent* mesh = Cast<UStaticMeshComponent>(this->GetComponentByClass(UStaticMeshComponent::StaticClass()));

			if (mesh != NULL) {
				mesh->SetCollisionProfileName(FName("WallPlaceCollision"));
			}
			else {
				LOG_ERROR("mesh is null");
			}

			playerController->setEdgePlaceableActor(this);
			playerController->setCurrentGameMode(EGameMode::GM_PlacingWalls);

			if (placeActorTimeline->IsPlaying()) {
				placeActorTimeline->Stop();
			}
			placeActorTimeline->PlayFromStart();
		}
		else {
			if (playerController == NULL) {
				LOG_ERROR("playerController is null");
			}
			LOG_WARN("placeActorTimeline not started!");
		}
	}
}

void ABaseWall::placeActor() {
	ACustomPlayerController* playerController =
		Cast<ACustomPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (playerController != NULL && IsValid(playerController->getEdgePlaceableActor()) && currentGrid != NULL) {

		FVector nearestVertexLocation = FVector(100000.f, 100000.f, 100000.f);
		currentGrid->getNearestVertexLocation(nearestVertexLocation);

		if (playerController->getCurrentGameMode() == EGameMode::GM_PlacingWalls) {
			playerController->getEdgePlaceableActor()->SetActorLocation(nearestVertexLocation);
		}
		else if (playerController->getCurrentGameMode() == EGameMode::GM_BuildingWalls) {

			float vectorLengthXY = UKismetMathLibrary::Abs(
				UKismetMathLibrary::VSizeXY(UKismetMathLibrary::Subtract_VectorVector(this->GetActorLocation(), nearestVertexLocation))
			);

			FRotator rotation = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), nearestVertexLocation);
			this->SetActorRotation(FRotator(0.f, rotation.Yaw, 0.f));

			UStaticMeshComponent* mesh = Cast<UStaticMeshComponent>(
				this->GetComponentByClass(UStaticMeshComponent::StaticClass())
				);
			mesh->SetRelativeScale3D(
				FVector(((vectorLengthXY) / 100.f), mesh->RelativeScale3D.Y, mesh->RelativeScale3D.Z)
			);
			mesh->SetRelativeLocation(FVector((vectorLengthXY / 2.f), mesh->RelativeLocation.Y, mesh->RelativeLocation.Z));
		}
	}
}

void ABaseWall::initializePlaceActorTimeline() {
	placeActorTimeline = NewObject<UTimelineComponent>(this);
	placeActorTimeline->CreationMethod = EComponentCreationMethod::UserConstructionScript;

	this->BlueprintCreatedComponents.Add(placeActorTimeline);

	placeActorTimeline->SetLooping(true);
	placeActorTimeline->SetTimelineLength(1.f);
	placeActorTimeline->SetTimelineLengthMode(ETimelineLengthMode::TL_LastKeyFrame);
	placeActorTimeline->SetPlaybackPosition(0.f, true);

	FOnTimelineEvent onClickEvent;
	onClickEvent.BindUFunction(this, FName("placeActor"));

	placeActorTimeline->SetTimelinePostUpdateFunc(onClickEvent);
	placeActorTimeline->RegisterComponent();
	LOG("placeEdgeActorTimeline initialized succesfully.");
}