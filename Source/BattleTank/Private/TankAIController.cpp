// Created by QianMo.

#include "BattleTank.h"
#include "TankAIController.h"

#define OUT

void ATankAIController::BeginPlay( )
{
	Super::BeginPlay( );

	auto PlayerTank = GetPlayerTank( );
	if (PlayerTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController cant find a player tank "));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController find player tank : %s "), *(PlayerTank->GetName( )));
	}


}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// Move towards the player

		//Aim towards the player
		GetControllerTank( )->AimAt(GetPlayerTank( )->GetActorLocation( ));
	}
}

ATank* ATankAIController::GetControllerTank( ) const
{
	return Cast<ATank>(GetPawn( ));
}


ATank* ATankAIController::GetPlayerTank( ) const
{
	auto PlayerPawn = GetWorld( )->GetFirstPlayerController( )->GetPawn( );
	if (!PlayerPawn)
	{
		return nullptr;
	}
	
	return Cast<ATank>(PlayerPawn);
}


