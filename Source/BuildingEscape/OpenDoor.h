#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:
	UOpenDoor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float Deltatime);

private:
	float StartYaw;

	float DoorLastOpened = 0.f;

	UPROPERTY(EditAnywhere)
	float OpenAngle = -90.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.35f;

	UPROPERTY(EditAnywhere)
	float OpenSpeed = 1.f;

	UPROPERTY(EditAnywhere)
	float CloseSpeed = 4.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume *PressurePlate;

	AActor *OpeningActor;
};
