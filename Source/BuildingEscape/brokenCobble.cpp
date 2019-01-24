#include "brokenCobble.h"

UbrokenCobble::UbrokenCobble()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UbrokenCobble::BeginPlay()
{
	Super::BeginPlay();
	if (!triggerBroken) { UE_LOG(LogTemp, Error, TEXT("error trigger at triggerBroken")); return; }
	calcMass = triggerBroken->FindComponentByClass<UcalculMass>();
}


// Called every frame
void UbrokenCobble::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction); 
	if (!calcMass) { UE_LOG(LogTemp, Error, TEXT("error calcMass at triggerBroken")); return; };
	if (calcMass->MajMass() <= 0) { brokenRequest.Broadcast();};
}

