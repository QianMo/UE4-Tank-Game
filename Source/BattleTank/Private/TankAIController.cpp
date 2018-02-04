// Created by QianMo.

#include "BattleTank.h"
#include "TankAIController.h"


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
	UE_LOG(LogTemp, Warning, TEXT("ATankAIController : Tick!"));

	AimTowardPlayer( );
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


// Start the tank moving the barrel so that a shot would be it where the crosshari intersects the world 
void ATankAIController::AimTowardPlayer( )
{
	if (!GetControllerTank())
	{
		return;
	}
	//Out Parameter
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) // Has "Side-effect" , is going to line trace
	{

		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString( ));
	}


	// If it hits the landscape

	// Tell controlled tank to aim at this point

}

// Get world location if linetrace throught crosshair  ,true if hits landscape
bool ATankAIController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);

	return true;
}
