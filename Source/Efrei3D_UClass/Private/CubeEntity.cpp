// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeEntity.h"

// Sets default values
ACubeEntity::ACubeEntity()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));

	this->Cube->SetupAttachment(RootComponent);
	this->Cube->SetMobility(EComponentMobility::Movable);
	//this->Cube->SetStaticMesh(TEXT("StaticMesh'/Game/Shapes/Shape_Cube.Shape_Cube'"));
}

void ACubeEntity::Init(float Acceleration, float Vitesse, UStaticMeshComponent* Cube, int32 HeightSpawn, float Gravity) {
	this->Acceleration = Acceleration;
	this->Vitesse = Vitesse;
	this->HeightSpawn = HeightSpawn;
	this->Gravity = Gravity;

	this->Cube->SetStaticMesh(Cube->GetStaticMesh());
}


// Called when the game starts or when spawned
void ACubeEntity::BeginPlay()
{
	Super::BeginPlay();


	FVector PreviousPos = this->GetActorLocation();

	this->SetActorLocation(FVector(PreviousPos.X, PreviousPos.Y, this->HeightSpawn));
}


// Called every frame
void ACubeEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->ChuteT += DeltaTime;

	FVector PreviousPos = this->GetActorLocation();

	float newZ;
	if (PreviousPos.Z < 0) {
		this->ChuteT = 0;
		this->HeightSpawn = 0;
	}

	newZ = this->HeightSpawn - (this->Vitesse * this->ChuteT + this->Acceleration * pow(this->ChuteT, 2) / 2);

	this->SetActorLocation(FVector(PreviousPos.X, PreviousPos.Y, newZ));
}

