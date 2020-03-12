// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeEntity.h"
#include "CubeSpawner.generated.h"

UCLASS()
class EFREI3D_UCLASS_API ACubeSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeSpawner();

protected:


	UPROPERTY(EditAnywhere)
		TSubclassOf<ACubeEntity> CubeClass; 
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BPClasses)
		UClass* ThirdPersonCharacterBlueprint;

	UPROPERTY(EditAnywhere)
		float Acceleration;

	UPROPERTY(EditAnywhere)
		float Vitesse;


	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Cube;

	UPROPERTY(EditAnywhere)
		int32 HeightSpawn = 1000;

	UPROPERTY(EditAnywhere)
		float Gravity = 500;

	UPROPERTY(EditAnywhere)
		int32 NbSpawn = 5;

	UPROPERTY(EditAnywhere)
		int32 Range = 500;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Create_Cube();

};
