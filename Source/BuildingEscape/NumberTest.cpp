#include "NumberTest.h"

UNumberTest::UNumberTest()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UNumberTest::BeginPlay()
{
	Super::BeginPlay();
	trigger = (ATriggerBox*)GetOwner();
}

bool  UNumberTest::open() {
	TSet<AActor*>overlapingActor;
	trigger->GetOverlappingActors(overlapingActor);
	for (AActor* actor : overlapingActor) {
		if (actor->FindComponentByClass<UTextRenderComponent>() != nullptr) {
			UTextRenderComponent* textRender = actor->FindComponentByClass<UTextRenderComponent>();
			if (text == textRender->GetName()) {
				if (Color == true) {textRender->SetTextRenderColor(FColor(0, 255, 0, 255));}
				return true; 
			}
		}
	}
	return false;
}


void  UNumberTest::color() {
	Color = true;
}

void UNumberTest::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}