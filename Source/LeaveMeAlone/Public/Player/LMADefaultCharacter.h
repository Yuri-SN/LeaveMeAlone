// LeaveMeAlone Game by Netologiya. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LMADefaultCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ULMAHealthComponent;

UCLASS()
class LEAVEMEALONE_API ALMADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALMADefaultCharacter();

	// Health
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	ULMAHealthComponent* HealthComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY()
	UDecalComponent* CurrentCursor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	UMaterialInterface* CursorMaterial = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	FVector CursorSize = FVector(20.0f, 40.0f, 40.0f);

	// Zoom

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom", meta = (ClampMin = "300.0", ClampMax = "1400.0"))
	float TargetArmLength = 1400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom", meta = (ClampMin = "300.0", ClampMax = "1400.0"))
	float MinArmLength = 400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom", meta = (ClampMin = "300.0", ClampMax = "1400.0"))
	float MaxArmLength = 1400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	float ZoomSpeed = 2.0f;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	float YRotation = -75.0f;
	float ArmLength = 1400.0f;
	float FOV = 55.0f;

	void MoveForward(float Value);
	void MoveRight(float Value);

	void ZoomCamera(float AxisValue);
};
