
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

class UStaticMeshComponent;

UENUM(BlueprintType)
enum EMovementState :uint8
{
	Mobility,
	Static
};

UCLASS()
class CPPBASE_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly)
	FString PlayerName = "Player";

	UPROPERTY(EditAnywhere)
	int EnemyNum = 20;

	UPROPERTY(EditDefaultsOnly)
	float CurrentHelth = 57.123;

	UPROPERTY(EditInstanceOnly)
	bool IsAlive = true;

	static inline int gt = 0;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

    UFUNCTION(BlueprintCallable)
	void ShowInformation();

    UFUNCTION(BlueprintCallable)
	void SinMovement();

	UPROPERTY(EditAnywhere)
	float Amplitude = 20;

	UPROPERTY(EditAnywhere)
	float Frequency = 0.020;

	UPROPERTY(EditAnywhere)
	FVector InitialLocation;

	float RunningTime =0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
