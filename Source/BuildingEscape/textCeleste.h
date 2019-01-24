#pragma once

#include "CoreMinimal.h"
#pragma region include
#include "Components/ActorComponent.h"
#include "Engine/TriggerBox.h"
#include "Components/TextRenderComponent.h"
#include "NumberTest.h"
#pragma endregion
#include "textCeleste.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UtextCeleste : public UActorComponent
{
	GENERATED_BODY()

public:	
	UtextCeleste();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:		
	UTextRenderComponent* textRender = nullptr;
	UPROPERTY(EditAnywhere)	ATriggerBox* triggerDoor = nullptr;
	UNumberTest* calcText = nullptr;
};
