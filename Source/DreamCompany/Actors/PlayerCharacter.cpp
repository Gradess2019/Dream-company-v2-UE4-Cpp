// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"

APlayerCharacter::APlayerCharacter() {
	this->AIControllerClass = ACustomPlayerController::StaticClass();
	minDistance = -150.f;
	maxDistance = -1500.f;
	zoomNumber = 5.f;
}

void APlayerCharacter::BeginPlay() {
	Super::BeginPlay();
	Cast<USceneComponent>(this->GetComponentByClass(UCameraComponent::StaticClass()))->
		SetRelativeLocation(FVector(maxDistance / 2, 0, 0));
	/*UCapsuleComponent* capsuleComponent = GetCapsuleComponent();

	if (capsuleComponent != NULL) {
		capsuleComponent->SetCapsuleHalfHeight(88.f, true);
		capsuleComponent->SetCapsuleRadius(34.f, true);
		capsuleComponent->bDynamicObstacle = true;
		capsuleComponent->bVisible = true;
		capsuleComponent->bHiddenInGame = true;
		capsuleComponent->bVisibleInReflectionCaptures = false;
		capsuleComponent->bReceivesDecals = false;
		capsuleComponent->SetSimulatePhysics(false);
		capsuleComponent->SetLinearDamping(0.f);
		capsuleComponent->SetEnableGravity(false);
		capsuleComponent->bApplyImpulseOnDamage = false;
		capsuleComponent->SetMassScale(capsuleComponent->GetFName(), 0.f);
		capsuleComponent->bGenerateOverlapEvents = false;
		capsuleComponent->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
		capsuleComponent->SetCollisionProfileName(TEXT("NoCollision"));
		printCustomDebugMessage(FColor::Green, TEXT("Capsule Component initialized"));
	}
	else {
		printCustomDebugMessage(FColor::Red, TEXT("Capsule Component not initialized"));
	}

	USkeletalMeshComponent* meshComponent = GetMesh();

	if (meshComponent != NULL) {
		meshComponent->SetEnableGravity(false);
		meshComponent->bApplyImpulseOnDamage = false;
		meshComponent->bGenerateOverlapEvents = false;
		meshComponent->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_Owner;
		meshComponent->SetCollisionProfileName(TEXT("CharacterMesh"));
		meshComponent->CastShadow = false;
		meshComponent->bVisible = true;
		meshComponent->bHiddenInGame = false;
		printCustomDebugMessage(FColor::Green, TEXT("Skeletal Mesh Component initialized"));
	}
	else {
		printCustomDebugMessage(FColor::Red, TEXT("Skeletal Mesh Component not initialized"));
	}


	UCharacterMovementComponent* movementComponent = GetCharacterMovement();
	
	if (movementComponent != NULL) {
		movementComponent->bApplyGravityWhileJumping = false;
		movementComponent->GravityScale = 0.f;
		movementComponent->Mass = 40.f;
		movementComponent->DefaultLandMovementMode = EMovementMode::MOVE_Flying;
		movementComponent->DefaultWaterMovementMode = EMovementMode::MOVE_Swimming;
		movementComponent->MaxWalkSpeed = 1200.f;
		movementComponent->MaxFlySpeed = 1200.f;
		movementComponent->BrakingDecelerationFlying = 2048.f;
		movementComponent->SetJumpAllowed(false);
		movementComponent->SetCanEverAffectNavigation(false);
		if (movementComponent->CanEverFly()) {
			printCustomDebugMessage(FColor::Green, TEXT("Can fly"));
		}
		printCustomDebugMessage(FColor::Green, TEXT("Character Movement Component initialized"));
	}
	else {
		printCustomDebugMessage(FColor::Red, TEXT("Character Movement Component not initialized"));
	}*/
}


