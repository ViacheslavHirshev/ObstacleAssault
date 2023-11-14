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

	//Move platform forwards
	FVector platformCurrentLocation = GetActorLocation();
	platformCurrentLocation += platformVelocityVector * DeltaTime;
	SetActorLocation(platformCurrentLocation);
	float distanceMoved = FVector::Dist(platformStartLocation, platformCurrentLocation);
	//Reverse direction of motion if gone too far
	if (distanceMoved > maxDistance)
	{
		FVector moveDirectionVector = platformVelocityVector.GetSafeNormal();
		platformStartLocation += moveDirectionVector * maxDistance;
		SetActorLocation(platformStartLocation);
		platformVelocityVector = -platformVelocityVector;
	}
}

