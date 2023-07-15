// Copyrigt David Gaikarashvili

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "siarulicda1.generated.h"

UCLASS()
class BUILDING_ESCEPE_API Asiarulicda1 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	Asiarulicda1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
