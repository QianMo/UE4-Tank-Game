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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("ATankAIController : Tick!"));

	AimTowardsPlayer( );
}


ATank* ATankPlayerController::GetControllerTank( ) const
{
	return Cast<ATank>(GetPawn( ));
}

// Start the tank moving the barrel so that a shot would be it where the crosshari intersects the world
void ATankPlayerController::AimTowardsPlayer( )
{
	if (!GetControllerTank( ))
	{
		return;
	}
	//Out Parameter
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) // Has "Side-effect" , is going to line trace
	{

		//UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString( ));
		GetControllerTank( )->AimAt(HitLocation);
	}


	// If it hits the landscape

	// Tell controlled tank to aim at this point

}

// Get world location if linetrace throught crosshair  ,true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation , ViewportSizeY *CrosshairYLocation);

	 
	// De-project the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation,LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("look Direction: %s"), *LookDirection.ToString( ));
	}


	// Line-trace along that look direction ,and see what we hit ( up to max range )
	return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);

}



