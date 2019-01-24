#pragma once

#include "CoreMinimal.h"
#pragma region include
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Engine/TriggerBox.h"
#include "Components/PrimitiveComponent.h"
#include "calculMass.h"
#pragma endregion
#include "RotateDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API URotateDoor : public UActorComponent
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	URotateDoor();

private:
#pragma region trigger
	UPROPERTY(EditAnywhere)	ATriggerBox* triggerDoor = nullptr;
	UPROPERTY(EditAnywhere)	ATriggerBox* triggerDoor2 = nullptr;
	UPROPERTY(EditAnywhere)	ATriggerBox* triggerDoor3 = nullptr;
	UPROPERTY(EditAnywhere)	ATriggerBox* triggerDoor4 = nullptr;
#pragma endregion

#pragma region calcMass
	UcalculMass* calcMass1 = nullptr;
	UcalculMass* calcMass2 = nullptr;
	UcalculMass* calcMass3 = nullptr;
	UcalculMass* calcMass4 = nullptr;
#pragma endregion

	UPROPERTY(BlueprintAssignable) FDoorEvent openRequest;
	UPROPERTY(BlueprintAssignable) FDoorEvent closeRequest;
};
