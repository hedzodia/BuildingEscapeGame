// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#pragma region include
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerBox.h"
#include "Components/PrimitiveComponent.h"
#pragma endregion

#include "calculMass.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UcalculMass : public UActorComponent
{
	GENERATED_BODY()

public:	
	UcalculMass();
	int MajMass();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere)float MinMass = 90;
	ATriggerBox* trigger = nullptr;
protected:
	virtual void BeginPlay() override;	
};
