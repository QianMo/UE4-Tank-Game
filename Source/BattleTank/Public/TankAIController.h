// Created by QianMo.

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	

	ATank* GetControllerTank( ) const;

	virtual void BeginPlay( ) override;

	virtual void Tick(float DeltaTime ) override;
	
	ATank* GetPlayerTank( ) const;

	// Start the tank moving the barrel so that a shot would be it where the crosshari intersects the world 
	void AimTowardPlayer( );

	// Return an OUT parameter ,ture if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

};
