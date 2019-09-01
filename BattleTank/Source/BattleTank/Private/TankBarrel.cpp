// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "BattleTank.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame

	// Given a max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationSecond, MaxElevationSecond);
	SetRelativeRotation(FRotator(Elevation,0 ,0));
	

}