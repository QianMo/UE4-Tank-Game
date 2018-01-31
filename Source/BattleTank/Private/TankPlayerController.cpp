// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControllerTank( ) const
{
	return Cast<ATank>(GetPawn( ));
}

