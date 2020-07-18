// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MuffinCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "GameCamera.generated.h"

UCLASS()
class MUFFIN2D_API AGameCamera : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AGameCamera();

protected:

    UPROPERTY(VisibleAnywhere)
    UCameraComponent* CameraComponent;

    APlayerController* PlayerController;

    AMuffinCharacter* MuffinCharacter;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    void MoveCamera();

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};
