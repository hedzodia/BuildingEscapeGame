#pragma once

#include "CoreMinimal.h"
#pragma region include
#include "Engine/TriggerBox.h"
#include "calculMass.h"
#pragma endregion
#include "brokenCobble.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFloorEvent);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UbrokenCobble : public UActorComponent
{
	GENERATED_BODY()

public:	
	UbrokenCobble();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private :	
	UPROPERTY(EditAnywhere)	ATriggerBox* triggerBroken = nullptr;	
	UcalculMass* calcMass = nullptr;
	UPROPERTY(BlueprintAssignable) FFloorEvent brokenRequest;

};
