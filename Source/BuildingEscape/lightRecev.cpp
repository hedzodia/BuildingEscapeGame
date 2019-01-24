#include "lightRecev.h"

UlightRecev::UlightRecev()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UlightRecev::BeginPlay()
{
	Super::BeginPlay();
}

void UlightRecev::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

