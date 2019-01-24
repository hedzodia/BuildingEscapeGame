#pragma once

#include "CoreMinimal.h"

#pragma region include
#include "Components/ActorComponent.h"
#include "Engine/TriggerBox.h"
#include "Components/TextRenderComponent.h"
#include "calculMass.h"
#pragma endregion

#include "textComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UtextComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UtextComponent();

protected:
	virtual void BeginPlay() override;

private:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void majText();
	UTextRenderComponent* textRender =nullptr; 
	UPROPERTY(EditAnywhere)	ATriggerBox* triggerDoor = nullptr;
	UcalculMass* calcMass = nullptr;
};
