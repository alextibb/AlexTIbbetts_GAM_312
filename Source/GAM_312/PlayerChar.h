// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Resource_M.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerChar.generated.h"

UCLASS()
class GAM_312_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	// These are the functions/properties like camera
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveForward(float axisValue);

	UFUNCTION()
		void MoveRight(float axisValue);

	UFUNCTION()
		void StartJump();

	UFUNCTION()
		void StopJump();

	UFUNCTION()
		void FindObject();

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* PlayerCamComp;
	
	// health hunger and stamina varibles 
	
	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "player stats")
		float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "player stats")
		float Hunger = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "player stats")
		float Stamina = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Resources")
		int Wood;

	UPROPERTY(EditAnywhere, Category = "Resources")
		int Stone;

	UPROPERTY(EditAnywhere, Category = "Resources")
		int Berry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
		TArray<int> ResourcesArray;

	UPROPERTY(EditAnywhere, Category = "Resources")
		TArray<FString> ResourcesNameArray;
	
	UPROPERTY(EditAnywhere, Category = "HitMarker")
		UMaterialInterface* hitDecal;

	UFUNCTION(Blueprintcallable)
		void SetHealth(float amount);

	UFUNCTION(Blueprintcallable)
		void SetHunger(float amount);

	UFUNCTION(BlueprintCallable)
		void SetStamina(float amount);
	
	UFUNCTION()
		void DecreaseStats();

	UFUNCTION()
		void GiveResource(float amount, FString resourceType);
};
