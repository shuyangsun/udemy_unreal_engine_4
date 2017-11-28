// © 2017 Shuyang Sun. All rights reserved.

#include "PositionReport.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
  bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();
  AActor *owner{ GetOwner() };
  FString owner_name = owner->GetName();
  UE_LOG(LogTemp, Warning, TEXT("PositionReport initialized on %s."), *owner_name);
  UE_LOG(LogTemp, Warning, TEXT("PositionReport began play."));
	
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
  _delta_time += DeltaTime;
  //UE_LOG(LogTemp, Log, TEXT("DeltaTime = %.2fs."), _delta_time);
	// ...
}

