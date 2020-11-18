#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	StartYaw = GetOwner()->GetActorRotation().Yaw;
	TargetYaw = StartYaw - 90.f;
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	CurrentRotation.Yaw = FMath::FInterpTo(CurrentRotation.Yaw, TargetYaw, DeltaTime, 2);
	GetOwner()->SetActorRotation(CurrentRotation);
}

//	UE_LOG(LogTemp, Warning, TEXT("Current rotation: %s"), *CurrrentRotation.ToString());