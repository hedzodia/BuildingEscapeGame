#include "colorCube.h"

UcolorCube::UcolorCube()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UcolorCube::BeginPlay()
{
	Super::BeginPlay();
	trigger = (ATriggerBox*)GetOwner(); 
	if (!calcLight) { UE_LOG(LogTemp, Error, TEXT("error trigger at calcLight")); return; }
	calcLight = triggerLight->FindComponentByClass<UlightProjected>();
}

void UcolorCube::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	TSet<AActor*>overlapingActor;
	trigger->GetOverlappingActors(overlapingActor);
	for (AActor* actor : overlapingActor) {
		if (actor->FindComponentByClass<UTextRenderComponent>() != nullptr) {
			if (!calcLight) { UE_LOG(LogTemp, Error, TEXT("error trigger at calcLight")); return; }
			UTextRenderComponent* textRender = actor->FindComponentByClass<UTextRenderComponent>();
			UE_LOG(LogTemp, Error, TEXT("%f %f %f"), calcLight->Color.R, calcLight->Color.G, calcLight->Color.B);
			//textRender->SetTextRenderColor(FColor());
		}
	}
}