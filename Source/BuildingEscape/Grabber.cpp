#include "Grabber.h"

UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	player = GetWorld()->GetFirstPlayerController();
	handle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	UInputComponent* mouseLeft = GetOwner()->FindComponentByClass<UInputComponent>();
	UInputComponent* mouseRight = GetOwner()->FindComponentByClass<UInputComponent>();

	if (handle->GetGrabbedComponent() != nullptr) {
		UE_LOG(LogTemp, Error, TEXT("error triggerDoor rotateDoor")); return;
	}
	if (!handle) {	UE_LOG(LogTemp, Error, TEXT("Error handle"));	}

	mouseLeft->BindAction("mouseLeft", IE_Pressed, this, &UGrabber::Grab);
	mouseLeft->BindAction("mouseLeft", IE_Released, this, &UGrabber::release);
}

void UGrabber::release()
{
	handle->ReleaseComponent();
	UE_LOG(LogTemp, Warning, TEXT("release"));
}

void UGrabber::Grab()
{
	player->GetPlayerViewPoint(startPoint, playerRot);//TODO at opti
	endPoint = startPoint + (playerRot.Vector()*maxDist);
	FHitResult hit;
	UE_LOG(LogTemp, Warning, TEXT("grab"));
	if (GetWorld()->LineTraceSingleByObjectType(hit, startPoint, endPoint, ECollisionChannel::ECC_PhysicsBody, FCollisionQueryParams(FName(), false, GetOwner()))) {
		UE_LOG(LogTemp, Warning, TEXT("Hit actor : %s"), *hit.GetActor()->GetName());
		handle->GrabComponent(hit.GetComponent(), NAME_None, hit.GetActor()->GetActorLocation(),true);
	}
}

void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (handle->GetGrabbedComponent() != nullptr) {
		player->GetPlayerViewPoint(startPoint, playerRot);//TODO at opti
		endPoint = startPoint + (playerRot.Vector()*maxDist);
		handle->SetTargetLocation(endPoint);
	}
}

