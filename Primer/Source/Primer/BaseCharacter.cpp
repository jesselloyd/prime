// Fill out your copyright notice in the Description page of Project Settings.

#include "Primer.h"
#include "BaseCharacter.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Implement Calculate Health
void ABaseCharacter::CalculateHealth(float Delta)
{
	Health += Delta;

	if (Health < 0)
		Health = 0;
	else if (Health > 100)
		Health = 100;

	CalculateDead();
}

// Implement Calculate Dead
void ABaseCharacter::CalculateDead() 
{
	if (Health <= 0)
		isDead = true;
	else 
		isDead = false;
}

// Implement PostEditChangedProperty
#if WITH_EDITOR
void ABaseCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	isDead = false;
	Health = 100;

	Super::PostEditChangeProperty(PropertyChangedEvent);

	CalculateDead();
}

#endif