// Fill out your copyright notice in the Description page of Project Settings.

#include "GridConstructor.h"

AGridConstructor::AGridConstructor() {
	X = 32;
	Y = 32;
	defaultEdgeSize = 64.f;
	defaultScaleValue = 1.28125f;
	edgeSize = defaultEdgeSize;
	grid = TArray<ABaseGrid*>();
}

void AGridConstructor::BeginPlay() {
	Super::BeginPlay();

	for (int yStep = 0; yStep < Y; yStep++) {
		for (int xStep = 0; xStep < X; xStep++) {
			FVector spawnLocation = {
				(this->GetActorLocation().X + (((edgeSize + 2.f) * 2.f) * xStep)),
				(this->GetActorLocation().Y + (((edgeSize + 2.f) * 2.f) * yStep)),
				this->GetActorLocation().Z
			};

			ABaseGrid* gridCell = this->GetWorld()->SpawnActor<ABaseGrid>(gridCellClass, spawnLocation, FRotator(0.f, 0.f, 0.f));
			if (gridCell != NULL) {
				float scaleValue = (edgeSize / defaultEdgeSize) * defaultScaleValue;

				Cast<UBoxComponent>(gridCell->GetComponentByClass(UBoxComponent::StaticClass()))->
					SetBoxExtent(FVector(edgeSize, edgeSize, 0.5f), true);

				Cast<UStaticMeshComponent>(gridCell->GetComponentByClass(UStaticMeshComponent::StaticClass()))->
					SetRelativeScale3D(FVector(scaleValue, scaleValue, 1.f));

				grid.AddUnique(gridCell);
				gridCell->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
			}
			else {
				LOG_ERROR("gridCell is null!");
			}
		}
	}
	LOG("Grid constructed successfully");
}


