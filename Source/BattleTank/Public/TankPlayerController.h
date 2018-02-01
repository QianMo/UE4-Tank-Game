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
	
	ATank* GetControllerTank( ) const;

	virtual void BeginPlay( ) override;
	
	
};
