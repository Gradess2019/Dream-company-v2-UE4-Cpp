// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "BaseActor.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(DreamCompanyLog, Log, All);
#define LOG(msg) UE_LOG(DreamCompanyLog, Log, TEXT("%s - %i line - %s - %s"), *FString(__FILE__), __LINE__, *FString(__FUNCTIONW__), *FString(msg));
#define LOG_WARN(msg) UE_LOG(DreamCompanyLog, Warning, TEXT("%s - %i line - %s - %s"), *FString(__FILE__), __LINE__, *FString(__FUNCTIONW__), *FString(msg));
#define LOG_ERROR(msg) UE_LOG(DreamCompanyLog, Error, TEXT("%s - %i line - %s - %s"), *FString(__FILE__), __LINE__, *FString(__FUNCTIONW__), *FString(msg));

UCLASS()
class DREAMCOMPANY_API ABaseActor : public AActor
{
	GENERATED_BODY()

public:
	ABaseActor();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Debug")
		FString debugMessage;

	UPROPERTY(EditDefaultsOnly, Category = "Debug")
		bool bEnableDebugMode;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};

USTRUCT(BlueprintType)
struct FDemandsStruct {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
		float design;

	UPROPERTY(BlueprintReadWrite)
		float programming;

	UPROPERTY(BlueprintReadWrite)
		float art;

	UPROPERTY(BlueprintReadWrite)
		float sound;

	UPROPERTY(BlueprintReadWrite)
		float testing;

	UPROPERTY(BlueprintReadWrite)
		uint8 lossesByBug;

	UPROPERTY(BlueprintReadWrite)
		int bugs;

	FDemandsStruct() {
		design = 0.f;
		programming = 0.f;
		art = 0.f;
		sound = 0.f;
		testing = 0.f;
		lossesByBug = 0;
		bugs = 0;
	}
};

USTRUCT()
struct FDateStruct {
	GENERATED_BODY()

	UPROPERTY()
		uint8 day;

	UPROPERTY()
		uint8 month;

	UPROPERTY()
		uint16 year;

	FDateStruct() {
		day = 1;
		month = 1;
		year = 1980;
	}
};

USTRUCT()
struct FScheduleStruct {
	GENERATED_BODY()

	UPROPERTY()
		uint8 startHour;

	UPROPERTY()
		uint8 startMinute;

	UPROPERTY()
		uint8 endHour;

	UPROPERTY()
		uint8 endMinute;

	FScheduleStruct() {
		startHour = 8;
		startMinute = 0;
		endHour = 17;
		endMinute = 0;
	}
};

USTRUCT()
struct FSkillsStruct {
	GENERATED_BODY()

	UPROPERTY()
		float design;

	UPROPERTY()
		float programming;

	UPROPERTY()
		float art;

	UPROPERTY()
		float sound;

	UPROPERTY()
		float translating;

	UPROPERTY()
		float testing;

	UPROPERTY()
		float debugging;

	UPROPERTY()
		float marketing;

	UPROPERTY()
		float leadership;

	FSkillsStruct() {
		design = 0.f;
		programming = 0.f;
		art = 0.f;
		sound = 0.f;
		translating = 0.f;
		testing = 0.f;
		debugging = 0.f;
		marketing = 0.f;
		leadership = 0.f;
	}
};

UENUM(BlueprintType)
enum class EQuality : uint8 {
	Q_Terrible UMETA(DisplayName = "Ужасное"),
	Q_Bad UMETA(DisplayName = "Плохое"),
	Q_Medium UMETA(DisplayName = "Среднее"),
	Q_Good UMETA(DisplayName = "Хорошее"),
	Q_Perfect UMETA(DisplayName = "Отличное")
	
};

UENUM(BlueprintType)
enum class EPosition : uint8 {
	P_None UMETA(DisplayName = "Неизвестно"),
	P_Junior UMETA(DisplayName = "Junior"),
	P_Middle UMETA(DisplayName = "Middle"),
	P_Senior UMETA(DisplayName = "Senior"),
	P_Teamlead UMETA(DisplayName = "Teamlead"),
	P_Director UMETA(DisplayName = "Director")
};

UENUM(BlueprintType)
enum class ETypeOfNPC : uint8 {
	TN_None UMETA(DisplayName = "Неизвестно"),
	TN_Designer UMETA(DisplayName = "Дизайнер"),
	TN_Programmer UMETA(DisplayName = "Программист"),
	TN_Artist UMETA(DisplayName = "Художник"),
	TN_Composer UMETA(DisplayName = "Композитор"),
	TN_Translator UMETA(DisplayName = "Переводчик"),
	TN_Marketer UMETA(DisplayName = "Маркетолог"),
	TN_Tester UMETA(DisplayName = "Тестировщик"),
	TN_ProjectManager UMETA(DisplayName = "Руководитель проекта")
};

UENUM(BlueprintType)
enum class EProjectType : uint8 {
	PT_None UMETA(DisplayName = "Неизвестно"),
	PT_Software UMETA(DisplayName = "Программное обеспечение"),
	PT_Hardware UMETA(DisplayName = "Аппаратное обеспечение"),
	PT_Marketing UMETA(DisplayName = "Маркетинг"),
	PT_GameDevelopment UMETA(DisplayName = "Игра")
};

UENUM(BlueprintType)
enum class EProjectSize : uint8 {
	PS_None UMETA(DisplayName = "Неизвестно"),
	PS_VerySmall UMETA(DisplayName = "Очень маленький"),
	PS_Small UMETA(DisplayName = "Маленький"),
	PS_Medium UMETA(DisplayName = "Средний"),
	PS_Big UMETA(DisplayName = "Большой"),
	PS_Giant UMETA(DisplayName = "Гигантский")
};

UENUM(BlueprintType)
enum class EFoodType : uint8 {
	FT_Universal UMETA(DisplayName = "Обычная"),
	FT_Italian UMETA(DisplayName = "Итальянская"),
	FT_Western UMETA(DisplayName = "Западная"),
	FT_Russian UMETA(DisplayName = "Российская"),
	FT_Chinese UMETA(DisplayName = "Китайская"),
	FT_French UMETA(DisplayName = "Французская"),
	FT_Brazilian UMETA(DisplayName = "Бразильская"),
	FT_Australian UMETA(DisplayName = "Австралийская"),
	FT_Japanese UMETA(DisplayName = "Японская")
};

UENUM(BlueprintType)
enum class EGameMode : uint8 {
	GM_Game UMETA(DisplayName = "Игра"),
	GM_Shop UMETA(DisplayName = "Магазин"),
	GM_PlacingFurniture UMETA(DisplayName = "Размещение мебели"),
	GM_PlacingWalls UMETA(DisplayName = "Размещение стен"),
	GM_BuildingWalls UMETA(DisplayName = "Строительство стен")
};