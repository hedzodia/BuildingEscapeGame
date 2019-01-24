#include "GetPositionComponent.h"

UGetPositionComponent::UGetPositionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGetPositionComponent::BeginPlay()
{
	Super::BeginPlay();
	FVector actorPos = GetOwner()->GetTransform().GetLocation();
	FString actorName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s : %s"),*actorName,*actorPos.ToString());
}

void UGetPositionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

