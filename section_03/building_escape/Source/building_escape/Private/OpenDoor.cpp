// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
  owner_ = GetOwner();
  FString const owner_name{ owner_->GetName() };
  FRotator const rotation{ owner_->GetActorRotation() };
  UE_LOG(LogTemp, Warning, TEXT("%s roatation = %s."), *owner_name, *rotation.ToString());
	
  world_ = GetWorld();
  AActor *pawn{ world_->GetFirstPlayerController()->GetPawn() };
  actor_that_opens_door = pawn;
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
  bool const is_overlapping{ pressure_plate->IsOverlappingActor(actor_that_opens_door) };
  if (is_overlapping) {
    open_door_();
  } else {
    float const time_elapsed{ world_->GetTimeSeconds() - last_door_open_time_ };
    bool const should_close{ last_door_open_time_ >= 0.0f && time_elapsed >= door_close_delay };
    if (should_close) {
      close_door_();
    }
  }
}

void UOpenDoor::open_door_()
{
  last_door_open_time_ = world_->GetTimeSeconds();
  set_door_rotation_angle_(open_angle_);
}

void UOpenDoor::close_door_() const
{
  set_door_rotation_angle_(0.0f);
}


void UOpenDoor::set_door_rotation_angle_(float const rotation_angle) const
{
  FRotator target_rotation{ 0.0f, rotation_angle, 0.0f };
  owner_->SetActorRotation(target_rotation);
}

