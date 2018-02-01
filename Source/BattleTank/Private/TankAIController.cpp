﻿// Created by QianMo.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay( )
{
	Super::BeginPlay( );

	auto ControlledTank = GetControllerTank( );
	if (ControlledTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController not prossesing a tank "));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController processing : %s "), *ControlledTank->GetName( ));
	}


}

ATank* ATankAIController::GetControllerTank( ) const
{
	return Cast<ATank>(GetPawn( ));
}

