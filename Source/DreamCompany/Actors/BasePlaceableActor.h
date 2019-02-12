// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"

#include "Runtime/Engine/Classes/Materials/MaterialInstance.h"
#include "Runtime/Engine/Classes/Materials/Material.h"

#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"

#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

#include "BasePlaceableActor.generated.h"

/**
 * 
 */
UCLASS()
class DREAMCOMPANY_API ABasePlaceableActor : public ABaseActor
{
	GENERATED_BODY()

public:
	ABasePlaceableActor();

	void changePlaceMaterialInsatnce(bool isAllowMaterialInstance);
	void setDefaultMaterialInstance();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly)
		UMaterialInstance* defaultMaterialInstance;

	UStaticMeshComponent* staticMeshComponent;

	UMaterialInstance* allowMaterialInstance;
	UMaterialInstance* banMaterialInstance;

	uint8 condition;
	uint8 conditionDecrement;

	uint16 price;
};
