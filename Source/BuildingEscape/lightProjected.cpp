#include "lightProjected.h"

UlightProjected::UlightProjected()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UlightProjected::BeginPlay()
{
	Super::BeginPlay(); 
	light = GetOwner()->FindComponentByClass<USpotLightComponent>();
}


void UlightProjected::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	light->SetLightColor(Color); 
}