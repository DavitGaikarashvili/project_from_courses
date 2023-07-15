// Copyrigt David Gaikarashvili


#include "World___Position.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorld___Position::UWorld___Position()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UWorld___Position::BeginPlay()
{
	Super::BeginPlay();

	// ...

	UE_LOG(LogTemp, Display, TEXT("Just a Log nothing to see!"));
	UE_LOG(LogTemp, Warning, TEXT("Thes is warning!"));
	FString Object = GetOwner()->GetName();
	FString ObjectPosition = GetOwner()->GetActorLocation().ToString();
	UE_LOG(LogTemp, Error, TEXT("%s is on these position: %s"), *Object, *ObjectPosition);

}


// Called every frame
void UWorld___Position::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

