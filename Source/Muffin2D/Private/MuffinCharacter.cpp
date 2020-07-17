// Fill out your copyright notice in the Description page of Project Settings.


#include "MuffinCharacter.h"

// Sets default values
AMuffinCharacter::AMuffinCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMuffinCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuffinCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMuffinCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

