#include "WorldPosition.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPosition::UWorldPosition()
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();

	FVector Position = GetOwner()->GetActorLocation();
	FString Name = GetOwner()->GetName();
	
	UE_LOG(LogTemp, Warning, TEXT("%s is at position: %s"), *Name, *Position.ToString() );
	
}


// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

