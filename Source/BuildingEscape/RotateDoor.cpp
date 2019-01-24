#include "RotateDoor.h"

URotateDoor::URotateDoor()
{	PrimaryComponentTick.bCanEverTick = true;	}

void URotateDoor::BeginPlay()
{
	Super::BeginPlay();
	if (!triggerDoor || !triggerDoor2 ||!triggerDoor3 ||!triggerDoor4) {	UE_LOG(LogTemp, Error, TEXT("error trigger at triggerDoor: rotateDoor")); return;	}
#pragma region calcMass
	calcMass1 = triggerDoor->FindComponentByClass<UcalculMass>(); 
	calcMass2 = triggerDoor2->FindComponentByClass<UcalculMass>(); 
	calcMass3 = triggerDoor3->FindComponentByClass<UcalculMass>(); 
	calcMass4 = triggerDoor4->FindComponentByClass<UcalculMass>(); 
#pragma endregion
}

void URotateDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction); 
	if (!calcMass1 || !calcMass2 || !calcMass3 || !calcMass4) { UE_LOG(LogTemp, Error, TEXT("error calcMass at triggerMass: rotateDoor")); return; };
	if (calcMass1->MajMass() == 0 && calcMass2->MajMass() == 0 && calcMass3->MajMass() == 0 && calcMass4->MajMass() == 0)openRequest.Broadcast();
	else closeRequest.Broadcast();
}