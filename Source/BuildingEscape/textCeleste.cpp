#include "textCeleste.h"

UtextCeleste::UtextCeleste()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UtextCeleste::BeginPlay()
{
	Super::BeginPlay();
	if (!triggerDoor) { UE_LOG(LogTemp, Error, TEXT("triggerMass at textComponent not found")); return; }
	calcText = triggerDoor->FindComponentByClass<UNumberTest>();
	textRender = GetOwner()->FindComponentByClass<UTextRenderComponent>();
}


void UtextCeleste::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}