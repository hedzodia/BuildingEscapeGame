#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "lightRecev.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UlightRecev : public UActorComponent
{
	GENERATED_BODY()

public:
	UlightRecev();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:	

		
	
};
