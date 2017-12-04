// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UOpenDoor : public UActorComponent
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

private:
  UWorld *world_{ nullptr };
  AActor *owner_{ nullptr };

  UPROPERTY(EditAnywhere)
  float open_angle_ = -90.0f;

  UPROPERTY(EditAnywhere)
  ATriggerVolume *pressure_plate;

  UPROPERTY(EditAnywhere)
  AActor *actor_that_opens_door;

  UPROPERTY(EditAnywhere)
  float door_close_delay = 1.0f;

  float last_door_open_time_{ -1.0f };

  void open_door_();
  void close_door_() const;
  void set_door_rotation_angle_(float const rotation_angle) const;
};
