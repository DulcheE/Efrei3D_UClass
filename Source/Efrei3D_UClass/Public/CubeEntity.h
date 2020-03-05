// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeEntity.generated.h"

UCLASS()
class EFREI3D_UCLASS_API ACubeEntity : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACubeEntity();

	void Init(float Acceleration, float Vitesse, UStaticMeshComponent* Cube, int32 HeightSpawn, float Gravity);

protected:

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


	float ChuteT = 0;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
