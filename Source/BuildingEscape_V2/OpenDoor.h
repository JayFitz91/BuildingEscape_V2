// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_V2_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void OpenDoor();
	void CloseDoor();

private:
	UPROPERTY(EditAnywhere)
	float OpenDoorAngle = 60.0f;

	UPROPERTY(EditAnywhere)
	float DoorDelay = 1.0f;

	UPROPERTY(VisibleAnywhere)
	float LastDoorOpenTime;

	UPROPERTY(VsibleAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(VisibleAnywhere)
	AActor* ActorThatOpens;

	UPROPERTY(VisibleAnywhere)
	AActor* Owner;

};
