// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "BattleTank.h"
void UTankBarrel::Elevate(float DegreesperSecond)
{
	// Move the barrel the right amount this frame

	// Given a max elevation speed, and the frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel-elevate() called at speed %s"),DegreesperSecond)
}