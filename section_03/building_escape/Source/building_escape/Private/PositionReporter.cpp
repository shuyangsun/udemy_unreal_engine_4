// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReporter.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
  UE_LOG(LogTemp, Warning, TEXT("PositionReporter initialized."));
}


// Called when the game starts
void UPositionReporter::BeginPlay()
{
	Super::BeginPlay();
  AActor *owner{ GetOwner() };
  FString owner_name{ owner->GetName() };
  FVector pos{ owner->GetTransform().GetLocation() };
  UE_LOG(LogTemp, Warning, TEXT("%s.GetTransform().GetLocation()=(%s)"), *owner_name, *(pos.ToString()));
  UE_LOG(LogTemp, Warning, TEXT("%s.GetActorLocation()=(%s)"), *owner_name, *(owner->GetActorLocation().ToString()));
}


// Called every frame
void UPositionReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

