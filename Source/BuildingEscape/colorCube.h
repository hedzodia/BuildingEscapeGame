#pragma once

#include "CoreMinimal.h"
#include "lightProjected.h"
#include "Components/TextRenderComponent.h"
#include "Engine/TriggerBox.h"
#include "Engine/SpotLight.h"
#include "colorCube.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UcolorCube : public UActorComponent
{
	GENERATED_BODY()

public:	
	UcolorCube();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override; 
protected:
	virtual void BeginPlay() override;

private:	
	ATriggerBox* trigger = nullptr; 
	UPROPERTY(EditAnywhere) ASpotLight* triggerLight = nullptr;
	UlightProjected* calcLight = nullptr;
};
