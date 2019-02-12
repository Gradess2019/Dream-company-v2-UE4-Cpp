// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class ACustomPlayerController;
class ABaseEdgePlaceableActor;

#include "CoreMinimal.h"
#include "Actors/BaseActor.h"

#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstance.h"
#include "Runtime/Engine/Classes/Components/MeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"

#include "Runtime/Engine/Public/Rendering/PositionVertexBuffer.h"

#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

#include "BaseGrid.generated.h"

/**
 * Base grid class for placing objects
 */
UCLASS()
class DREAMCOMPANY_API ABaseGrid : public ABaseActor
{
	GENERATED_BODY()

public:

	ABaseGrid();

	UFUNCTION(BlueprintCallable)
		TArray<FVector> MeshData(const UStaticMeshComponent* StaticMeshComponent);

	void getNearestVertexLocation(FVector &result);

protected:

	UFUNCTION()
		virtual void BeginPlay() override;
	
private:

	bool hasActor;

	UStaticMeshComponent * gridCell;

	UMaterialInstance* normalMaterial;
	UMaterialInstance* hoveredMaterial;
	UMaterialInstance* freeMaterial;
	UMaterialInstance* busyMaterial;

	ACustomPlayerController* playerController;
	TArray<FVector> vertexes;


	UFUNCTION()
		void setNormalMaterial(UPrimitiveComponent* component);

	UFUNCTION()
		void setReleasedMaterial(AActor* actor, FKey key);

	UFUNCTION()
		void setHoveredMaterial(UPrimitiveComponent* component);

	UFUNCTION()
		void setClickedMaterial(AActor* actor, FKey key);


	

	bool checkAllLoadedMaterials();
	bool isValidPlayerController();

	void absVector2D(FVector2D &vector);
	void subtractVectors2D(FVector2D &minuend, FVector2D &subtrahend);
	
};
