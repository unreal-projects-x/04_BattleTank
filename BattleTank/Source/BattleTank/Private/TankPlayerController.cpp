// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possessing: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	
	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }//*mine* there is obviously no sence in aiming crosshair towards the screen if we arent controlling tank

	FVector HitLocation; // out parameter
	if (GetSightRayHitlocation(HitLocation)) //Has"Side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())

				//TODO tell controlled tank to aim at this point
	}
}
//Get world location of linetrace through crosshair, true if hits landscape

bool ATankPlayerController::GetSightRayHitlocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}