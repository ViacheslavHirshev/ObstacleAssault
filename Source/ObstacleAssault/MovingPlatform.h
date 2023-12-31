// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

private:
	FVector platformStartLocation{ 0, 0, 0 };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Moving")
	FVector platformMovingVelocity{ 0, 0, 0 };

	UPROPERTY(EditAnywhere, Category="Moving")
	float maxDistance{ 0 };

	UPROPERTY(EditAnywhere, Category="Rotating")
	FRotator platformRotationVelocity{ 0, 0, 0 };

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	float getDistanceMoved() const;
};
