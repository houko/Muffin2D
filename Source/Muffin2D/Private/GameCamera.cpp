// Fill out your copyright notice in the Description page of Project Settings.


#include "GameCamera.h"

// Sets default values
AGameCamera::AGameCamera()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    CameraComponent = CreateDefaultSubobject<UCameraComponent>((TEXT("CameraComponent")));
    CameraComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGameCamera::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AGameCamera::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
