// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MuffinCharacter.generated.h"

UCLASS()
class MUFFIN2D_API AMuffinCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AMuffinCharacter();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    APlayerController* PlayerController;

    FVector LaunchVelocity;

    void MoveTowardsCursor();

    void LaunchOnAnyKeyPress();

    void Launch();

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
