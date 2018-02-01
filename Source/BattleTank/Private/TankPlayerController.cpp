// Created by QianMo .

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay( )
{
	Super::BeginPlay( );

	auto ControlledTank = GetControllerTank( );
	if (ControlledTank==nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not prossesing a tank "));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController processing : %s "),*ControlledTank->GetName());
	}

	
}

ATank* ATankPlayerController::GetControllerTank( ) const
{
	return Cast<ATank>(GetPawn( ));
}


