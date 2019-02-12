// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePlaceableActor.h"

ABasePlaceableActor::ABasePlaceableActor() {
	debugMessage = FString(TEXT("BasePlaceableActor"));

	ConstructorHelpers::FObjectFinder<UMaterialInstance> loadAllowMaterial(TEXT("/Game/Materials/MaterialInstances/AllowMaterial.AllowMaterial"));
	allowMaterialInstance = loadAllowMaterial.Object;

	ConstructorHelpers::FObjectFinder<UMaterialInstance> loadBanMaterial(TEXT("/Game/Materials/MaterialInstances/BanMaterial.BanMaterial"));
	banMaterialInstance = loadBanMaterial.Object;

}

void ABasePlaceableActor::BeginPlay() {
	Super::BeginPlay();

	if (allowMaterialInstance != NULL && banMaterialInstance != NULL) {
		LOG("Material Instances loaded successfully.")
	}

	staticMeshComponent = Cast<UStaticMeshComponent>(this->GetComponentByClass(UStaticMeshComponent::StaticClass()));
	
	if (staticMeshComponent == NULL) {
		staticMeshComponent = NewObject<UStaticMeshComponent>(this);
		staticMeshComponent->RegisterComponent();
	}
	LOG("StaticMeshComponent created successfully.")

}

void ABasePlaceableActor::changePlaceMaterialInsatnce(bool isAllowMaterialInstance) {
	if (isAllowMaterialInstance) {
		staticMeshComponent->SetMaterial(0, allowMaterialInstance);
	}
	else {
		staticMeshComponent->SetMaterial(0, banMaterialInstance);
	}
}

void ABasePlaceableActor::setDefaultMaterialInstance() {
	staticMeshComponent->SetMaterial(0, defaultMaterialInstance);
}

