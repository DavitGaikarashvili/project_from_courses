// Copyrigt David Gaikarashvili
#include "Door_Open.h"
#include"Engine/World.h"
#include"GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"//damxmare faili rotatestvis




// Sets default values for this component's properties
UDoor_Open::UDoor_Open()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoor_Open::BeginPlay()
{
	Super::BeginPlay();
	// 
	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw += InitialYaw ;
	if(!PressurePlate){
		UE_LOG(LogTemp, Error, TEXT("%s has the open door component on it, but no pressureplate set"), *GetOwner()->GetName())
	}

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	// ...
	
}


// Called every frame
void UDoor_Open::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (PressurePlate && PressurePlate->IsOverlappingActor( ActorThatOpens))
	{
		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld()->GetTimeSeconds();
	}else{
		if(GetWorld() -> GetTimeSeconds() - DoorLastOpened > DoorCloseDelay){
			CloseDoor(DeltaTime);
		}
		
	}
	
	// ...
	

	// float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	// FRotator OpenDoor(0.f, TargetYaw, 0.f);
	// OpenDoor.Yaw = FMath::FInterpConstantTo(CurrentYaw, TargetYaw, DeltaTime, 20);
	// GetOwner()->SetActorRotation(OpenDoor);
	//float MyFloat = 90.f;
	// FRotator CurrentRotation = GetOwner()->GetActorRotation();//miige aqedan informazia rotatis shesaxeb
	// CurrentRotation.Yaw = 90.f;//z gerdzi sheatriale amdenit
	// GetOwner()->SetActorRotation(CurrentRotation);//daayene amis monacemebi
}
void UDoor_Open:: OpenDoor(float DeltaTime){
	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, DeltaTime* Speed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}
void UDoor_Open:: CloseDoor(float DeltaTime){
	CurrentYaw = FMath::Lerp(CurrentYaw, InitialYaw, DeltaTime* 2.0f);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}
