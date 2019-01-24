#include "calculMass.h"

UcalculMass::UcalculMass()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UcalculMass::BeginPlay()
{
	Super::BeginPlay(); 
	trigger = (ATriggerBox*)GetOwner();
}

int  UcalculMass::MajMass() {
	TSet<AActor*>overlapingActor;
	float mass = 0;
	if (!trigger) {	UE_LOG(LogTemp, Error, TEXT("error trigger at calculMass")); return 0;	}
	trigger->GetOverlappingActors(overlapingActor);
	for (AActor* actor : overlapingActor) {
		mass += actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return MinMass - mass;
}

void UcalculMass::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}