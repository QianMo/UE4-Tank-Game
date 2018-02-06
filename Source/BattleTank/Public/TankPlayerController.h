// Created by QianMo .

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	
	ATank* GetControllerTank( ) const;

	virtual void BeginPlay( ) override;
	
	virtual void Tick(float DeltaTime) override;

	// Start the tank moving the barrel so that a shot would be it where the crosshari intersects the world 
	void AimTowardsPlayer( );

	// Return an OUT parameter ,ture if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	
};
