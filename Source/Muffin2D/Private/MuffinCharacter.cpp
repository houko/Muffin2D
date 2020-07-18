// Fill out your copyright notice in the Description page of Project Settings.


#include "MuffinCharacter.h"

#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMuffinCharacter::AMuffinCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    LaunchVelocity = FVector(0, 0, 1500);
}

// Called when the game starts or when spawned
void AMuffinCharacter::BeginPlay()
{
    Super::BeginPlay();
    PlayerController = Cast<APlayerController>(GetController());
    PlayerController->bShowMouseCursor = true;
    UBoxComponent SpawnArea;
    FVector origin = SpawnArea.Bounds.Origin;
}

void AMuffinCharacter::MoveTowardsCursor()
{
    FVector MouseLocation, MouseDirection;

    PlayerController->DeprojectMousePositionToWorld(MouseLocation, MouseDirection);
    float YDirection = FMath::Clamp(MouseLocation.Y - GetActorLocation().Y, -1.0f, 1.0f);
    FVector MoveDirection = FVector(0, YDirection, 0);
    AddMovementInput(MoveDirection);
}


void AMuffinCharacter::LaunchOnAnyKeyPress()
{
    Launch();
}

void AMuffinCharacter::Launch()
{
    LaunchCharacter(LaunchVelocity, false, true);
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
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMuffinCharacter::LaunchOnAnyKeyPress);
}
