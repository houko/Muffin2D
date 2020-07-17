// Fill out your copyright notice in the Description page of Project Settings.


#include "MuffinCharacter.h"
#include "Kismet/GameplayStatics.h"

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
    PlayerController = Cast<APlayerController>(GetController());
    PlayerController->bShowMouseCursor = true;
}

void AMuffinCharacter::MoveTowardsCursor()
{
    FVector MouseLocation, MouseDirection;

    PlayerController->DeprojectMousePositionToWorld(MouseLocation, MouseDirection);
    float YDirection = FMath::Clamp(MouseLocation.Y - GetActorLocation().Y, -1.0f, 1.0f);
    FVector MoveDirection = FVector(0,YDirection,0);
    AddMovementInput(MoveDirection);
}

// Called every frame
void AMuffinCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    MoveTowardsCursor();
}

// Called to bind functionality to input
void AMuffinCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}