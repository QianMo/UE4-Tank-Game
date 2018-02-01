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
	
	
};
