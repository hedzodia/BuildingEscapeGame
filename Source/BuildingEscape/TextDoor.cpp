#include "TextDoor.h"

UTextDoor::UTextDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTextDoor::BeginPlay()
{
	Super::BeginPlay();
	if (!triggerDoor || !triggerDoor2 || !triggerDoor3 || !triggerDoor4 || !triggerDoor5 || !triggerDoor6 || !triggerDoor7) { UE_LOG(LogTemp, Error, TEXT("error trigger at triggerDoor: rotateDoor")); return; }
	#pragma region calcText	
	calcText1 = triggerDoor->FindComponentByClass<UNumberTest>();
	calcText2 = triggerDoor2->FindComponentByClass<UNumberTest>();
	calcText3 = triggerDoor3->FindComponentByClass<UNumberTest>();
	calcText4 = triggerDoor4->FindComponentByClass<UNumberTest>();
	calcText5 = triggerDoor5->FindComponentByClass<UNumberTest>();
	calcText6 = triggerDoor6->FindComponentByClass<UNumberTest>();
	calcText7 = triggerDoor7->FindComponentByClass<UNumberTest>();
	#pragma endregion
}

void UTextDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);	
	if (!calcText1 || !calcText2 || !calcText3 || !calcText4 || !calcText5 || !calcText6 || !calcText7) { UE_LOG(LogTemp, Error, TEXT("error calcMass at triggerMass: rotateDoor")); return; };
	if (calcText1->open() == true && calcText2->open() == true && calcText3->open() == true && calcText4->open() == true && calcText5->open() == true && calcText6->open() == true && calcText7->open() == true) {
		openRequest.Broadcast();

		#pragma region color
		calcText1->color();
		calcText2->color();
		calcText3->color();
		calcText4->color();
		calcText5->color();
		calcText6->color();
		calcText7->color();
		#pragma endregion
	}
	else { closeRequest.Broadcast();	}
}