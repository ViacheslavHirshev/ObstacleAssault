// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	platformStartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (getDistanceMoved())
	{
		FVector moveDirectionVector = platformMovingVelocity.GetSafeNormal();
		platformStartLocation += moveDirectionVector * maxDistance;
		SetActorLocation(platformStartLocation);
		platformMovingVelocity = -platformMovingVelocity;
	}
	else
	{
		FVector platformCurrentLocation = GetActorLocation();
		platformCurrentLocation += platformMovingVelocity * DeltaTime;
		SetActorLocation(platformCurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(platformRotationVelocity * DeltaTime);
}

float AMovingPlatform::getDistanceMoved() const
{
	return FVector::Dist(platformStartLocation, GetActorLocation()) > maxDistance;
}