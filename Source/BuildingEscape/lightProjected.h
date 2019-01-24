#pragma once

#include "CoreMinimal.h"
#pragma region include
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "Components/SpotLightComponent.h"
#pragma endregion
#include "lightProjected.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UlightProjected : public UActorComponent
{
	GENERATED_BODY()

public:	
	FLinearColor color();
	UlightProjected();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere)FLinearColor Color;
protected:
	virtual void BeginPlay() override;

private:
	USpotLightComponent* light = nullptr;
};