// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#pragma region include
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#pragma endregion

#include "GetPositionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGetPositionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGetPositionComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
};
