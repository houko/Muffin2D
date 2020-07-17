// Fill out your copyright notice in the Description page of Project Settings.


#include "GameCamera.h"


#include "MuffinCharacter.h"
#include "Kismet/GameplayStatics.h"

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
    PlayerController = UGameplayStatics::GetPlayerController(this, 0);
    // 绑定摄像机
    PlayerController->SetViewTargetWithBlend(this, 0);
    MuffinCharacter = Cast<AMuffinCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AGameCamera::MoveCameara()
{
    float Z = MuffinCharacter->GetActorLocation().Z;
    FVector TowardLocation = FVector(GetActorLocation().X, GetActorLocation().Y, Z);
    SetActorLocation(TowardLocation);
}

// Called every frame
void AGameCamera::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    MoveCameara();
}
