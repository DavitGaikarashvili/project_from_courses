// Copyrigt David Gaikarashvili

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Door_Open.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCEPE_API UDoor_Open : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoor_Open();
	UPROPERTY(EditAnywhere)
	AActor* ActorThatOpens;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	
private:
UPROPERTY(EditAnywhere)
float Speed = 0.02f;
UPROPERTY(EditAnywhere)
float InitialYaw;
UPROPERTY(EditAnywhere)
float CurrentYaw;
UPROPERTY(EditAnywhere)
float TargetYaw = 90.0f;
UPROPERTY(EditAnywhere)
ATriggerVolume*PressurePlate;
float DoorLastOpened;
float DoorCloseDelay = .5f;
//UPROPERTY(EditAnywhere)
//TSoftObjectPtr<AActor>  Default_Pawn0;
//UPROPERTY(EditAnywhere)
//AActor* Default_Pawn0;



		
};
