// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseGrid.h"
#include "Controllers/CustomPlayerController.h"
#include "Actors/BaseEdgePlaceableActor.h"

ABaseGrid::ABaseGrid() {

	normalMaterial = (ConstructorHelpers::FObjectFinder<UMaterialInstance>(TEXT("/Game/Materials/MaterialInstances/GridMaterialNormal.GridMaterialNormal"))).Object;
	hoveredMaterial = (ConstructorHelpers::FObjectFinder<UMaterialInstance>(TEXT("/Game/Materials/MaterialInstances/GridMaterialHovered.GridMaterialHovered"))).Object;
	freeMaterial = (ConstructorHelpers::FObjectFinder<UMaterialInstance>(TEXT("/Game/Materials/MaterialInstances/GridMaterialFree.GridMaterialFree"))).Object;
	busyMaterial = (ConstructorHelpers::FObjectFinder<UMaterialInstance>(TEXT("/Game/Materials/MaterialInstances/GridMaterialBusy.GridMaterialBusy"))).Object;

	if (!checkAllLoadedMaterials()) {
		LOG_ERROR("Loading materials failed!");
		checkNoEntry();
	}
}

TArray<FVector> ABaseGrid::MeshData(const UStaticMeshComponent* StaticMeshComponent) {
	TArray<FVector> vertexes = TArray<FVector>();

	if (!IsValidLowLevel()) return vertexes;
	if (!StaticMeshComponent) return vertexes;
	if (!StaticMeshComponent->GetStaticMesh()) return vertexes;
	if (!StaticMeshComponent->GetStaticMesh()->RenderData) return vertexes;

	if (StaticMeshComponent->GetStaticMesh()->RenderData->LODResources.Num() > 0) {
		FPositionVertexBuffer* VertexBuffer = &StaticMeshComponent->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.PositionVertexBuffer;
		if (VertexBuffer)
		{
			const int32 VertexCount = VertexBuffer->GetNumVertices();
			for (int32 Index = 0; Index < VertexCount; Index++)
			{
				const FVector WorldSpaceVertexLocation = StaticMeshComponent->GetComponentTransform().TransformPosition(VertexBuffer->VertexPosition(Index));
				GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(
					TEXT("%s %s %s"),
					*FString::SanitizeFloat(WorldSpaceVertexLocation.X),
					*FString::SanitizeFloat(WorldSpaceVertexLocation.Y),
					*FString::SanitizeFloat(WorldSpaceVertexLocation.Z)
				));
				vertexes.Add(WorldSpaceVertexLocation);
			}
		}
	}

	return vertexes;
}

void ABaseGrid::BeginPlay() {
	Super::BeginPlay();

	gridCell = Cast<UStaticMeshComponent>(this->GetComponentByClass(UStaticMeshComponent::StaticClass()));
	if (gridCell == NULL) {
		LOG_ERROR("gridCell is null!");
		checkNoEntry();
	}
	else {
		gridCell->OnBeginCursorOver.AddDynamic(this, &ABaseGrid::setHoveredMaterial);
		gridCell->OnEndCursorOver.AddDynamic(this, &ABaseGrid::setNormalMaterial);
		OnClicked.AddUniqueDynamic(this, &ABaseGrid::setClickedMaterial);
		OnReleased.AddUniqueDynamic(this, &ABaseGrid::setReleasedMaterial);
	}

	playerController = Cast<ACustomPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	isValidPlayerController();
}

void ABaseGrid::setNormalMaterial(UPrimitiveComponent* component) {
	gridCell->SetMaterial(0, normalMaterial);
}

void ABaseGrid::setReleasedMaterial(AActor* actor, FKey key) {
	gridCell->SetMaterial(0, hoveredMaterial);
}

void ABaseGrid::setHoveredMaterial(UPrimitiveComponent* component) {
	gridCell->SetMaterial(0, hoveredMaterial);
	if (isValidPlayerController() && 
		(playerController->getCurrentGameMode() == EGameMode::GM_PlacingWalls ||
		 playerController->getCurrentGameMode() == EGameMode::GM_BuildingWalls) &&
		IsValid(playerController->getEdgePlaceableActor()
		)) {

		if (vertexes.Num() == 0) {
			vertexes = MeshData(gridCell);
		}
		playerController->getEdgePlaceableActor()->setGrid(this);
	}
}

void ABaseGrid::setClickedMaterial(AActor* actor, FKey key) {
	//this->MeshData(Cast<UStaticMeshComponent>(this->GetComponentByClass(UStaticMeshComponent::StaticClass())));
	if (playerController->getCurrentGameMode() == EGameMode::GM_PlacingWalls &&
		IsValid(playerController->getEdgePlaceableActor())
		) {
		playerController->setCurrentGameMode(EGameMode::GM_BuildingWalls);
	}

	if (hasActor) {
		gridCell->SetMaterial(0, busyMaterial);
	}
	else {
		gridCell->SetMaterial(0, freeMaterial);
	}
}

bool ABaseGrid::checkAllLoadedMaterials() {
	return IsValid(normalMaterial) && IsValid(hoveredMaterial) &&
		IsValid(freeMaterial) && IsValid(busyMaterial);
}

void ABaseGrid::getNearestVertexLocation(FVector &result) {
	//if (vertexes.Num() == 0) {
	//	vertexes = this->MeshData(gridCell);
	//}
	vertexes = this->MeshData(gridCell);
	FVector minDistance = FVector(10000.f, 10000.f, 0.f);
	for (FVector vertexLocation : vertexes) {
		FVector2D vertexLocation2D = FVector2D::ZeroVector;
		playerController->ProjectWorldLocationToScreen(vertexLocation, vertexLocation2D, false);

		FVector2D minDistance2D = FVector2D::ZeroVector;
		playerController->ProjectWorldLocationToScreen(minDistance, minDistance2D, false);

		FVector2D mouseLocation2D = FVector2D::ZeroVector;
		playerController->GetMousePosition(mouseLocation2D.X, mouseLocation2D.Y);

		absVector2D(vertexLocation2D);
		absVector2D(minDistance2D);
		absVector2D(mouseLocation2D);

		subtractVectors2D(vertexLocation2D, mouseLocation2D);
		subtractVectors2D(minDistance2D, mouseLocation2D);

		if (UKismetMathLibrary::VSize2D(vertexLocation2D) < UKismetMathLibrary::VSize2D(minDistance2D)) {
			minDistance = vertexLocation;
		}
	}

	result = minDistance;
}

bool ABaseGrid::isValidPlayerController() {
	if (IsValid(playerController)) {
		return true;
	}
	else {
		LOG_ERROR("playerController is null");
		return false;
	}
}

void ABaseGrid::absVector2D(FVector2D &vector) {
	vector.X = UKismetMathLibrary::Abs(vector.X);
	vector.Y = UKismetMathLibrary::Abs(vector.Y);
}

void ABaseGrid::subtractVectors2D(FVector2D &minuend, FVector2D &subtrahend) {
	minuend = UKismetMathLibrary::Subtract_Vector2DVector2D(minuend, subtrahend);
}