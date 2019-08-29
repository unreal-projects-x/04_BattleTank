// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Can't find Player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Found Player %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank())
	{
		//TODO Move towards the player
		//Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	
		//Fire if ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}