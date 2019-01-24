#include "textComponent.h"

UtextComponent::UtextComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UtextComponent::BeginPlay()
{
	Super::BeginPlay();
	if(!triggerDoor){ UE_LOG(LogTemp, Error, TEXT("triggerMass at textComponent not found")); return; }
	calcMass = triggerDoor->FindComponentByClass<UcalculMass>();
	textRender = GetOwner()->FindComponentByClass<UTextRenderComponent>();
}

void UtextComponent::majText()
{
	if (!textRender) { UE_LOG(LogTemp, Error, TEXT("textRenderer rotateDoor not found")); return; }
	textRender->SetText(FString::SanitizeFloat(calcMass->MajMass()));
}

void UtextComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	majText();
}

