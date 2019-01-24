#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerBox.h"
#include <string>
#include "Components/TextRenderComponent.h"
#include "NumberTest.generated.h"

using namespace std;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UNumberTest : public UActorComponent
{
	GENERATED_BODY()

public:	
	UNumberTest();
	bool open();
	void color();

	bool Color;
protected:
	virtual void BeginPlay() override;	
	

private:
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		ATriggerBox* trigger = nullptr;
		UPROPERTY(EditAnywhere) FString text;
		
};