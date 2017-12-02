// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
  AActor * const owner{ GetOwner() };
  FString const owner_name{ owner->GetName() };
  FRotator const rotation{ owner->GetActorRotation() };
  UE_LOG(LogTemp, Warning, TEXT("%s roatation = %s."), *owner_name, *rotation.ToString());

  FRotator target_rotation{ 0.0f, 75.0f, 0.0f };
  owner->SetActorRotation(target_rotation);
  UE_LOG(LogTemp, Warning, TEXT("%s roatation = %s."), *owner_name, *owner->GetActorRotation().ToString());
	// ...
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

