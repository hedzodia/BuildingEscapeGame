#pragma once

#include "CoreMinimal.h"
#pragma region include
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Engine/TriggerBox.h"
#include "Components/PrimitiveComponent.h"
#include "NumberTest.h"
#pragma endregion
#include "TextDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTextDoorEvent);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UTextDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTextDoor();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;;
protected:
	virtual void BeginPlay() override;

private :
	#pragma region triggerDoor
	UPROPERTY(EditAnywhere)	ATriggerBox* triggerDoor = nullptr;
	UPROPERTY(EditAnywhere)	ATriggerBox* triggerDoor2 = nullptr;
	UPROPERTY(EditAnywhere)	ATriggerBox* triggerDoor3 = nullptr;
	UPROPERTY(EditAnywhere)	ATriggerBox* triggerDoor4 = nullptr;
	UPROPERTY(EditAnywhere)	ATriggerBox* triggerDoor5 = nullptr;
	UPROPERTY(EditAnywhere)	ATriggerBox* triggerDoor6 = nullptr;
	UPROPERTY(EditAnywhere)	ATriggerBox* triggerDoor7 = nullptr;
	#pragma endregion

	#pragma region calcText
	UNumberTest* calcText1 = nullptr;
	UNumberTest* calcText2 = nullptr;
	UNumberTest* calcText3 = nullptr;
	UNumberTest* calcText4 = nullptr;
	UNumberTest* calcText5 = nullptr;
	UNumberTest* calcText6 = nullptr;
	UNumberTest* calcText7 = nullptr;
	#pragma endregion

	UPROPERTY(BlueprintAssignable) FTextDoorEvent openRequest;
	UPROPERTY(BlueprintAssignable) FTextDoorEvent closeRequest;
};