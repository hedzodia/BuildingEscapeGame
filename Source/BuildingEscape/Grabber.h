#pragma once

#include "CoreMinimal.h"

#pragma region include
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#pragma endregion

#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	void release();
	void Grab();

private:
	FVector startPoint;
	FRotator playerRot; 
	FVector endPoint;
	APlayerController* player = nullptr;//for viewpoint
	UPhysicsHandleComponent* handle = nullptr;//for grab & release
	UPROPERTY(EditAnywhere)//max grab
		float maxDist = 100;
public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UGrabber();
};
