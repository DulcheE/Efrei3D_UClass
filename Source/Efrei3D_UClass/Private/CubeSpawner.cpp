// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeSpawner.h"

// Sets default values
ACubeSpawner::ACubeSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));

	this->Cube->SetupAttachment(RootComponent);
	this->Cube->SetMobility(EComponentMobility::Movable);
	//this->Cube->SetStaticMesh(TEXT("StaticMesh'/Game/Shapes/Shape_Cube.Shape_Cube'"));
}

// Called when the game starts or when spawned
void ACubeSpawner::BeginPlay()
{
	Super::BeginPlay();


	FVector PreviousPos = this->GetActorLocation();

	this->SetActorLocation(FVector(PreviousPos.X, PreviousPos.Y, this->HeightSpawn));
}


// Called every frame
void ACubeSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->ChuteT += DeltaTime;

	FVector PreviousPos = this->GetActorLocation();

	float newZ;
	if (PreviousPos.Z < 0) {
		newZ = this->HeightSpawn;
		this->ChuteT = 0;
	}
	else {
		newZ = this->HeightSpawn - (this->Vitesse * this->ChuteT + this->Acceleration * pow(this->ChuteT, 2) / 2);
	}

	this->SetActorLocation(FVector(PreviousPos.X, PreviousPos.Y, newZ));
}

