// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeEntity.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>

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

void ACubeEntity::Init(UClass* ThirdPersonCharacterBlueprint, float Acceleration, float Vitesse, UStaticMeshComponent* Cube, int32 HeightSpawn, float Gravity) {
	this->ThirdPersonCharacterBlueprint = ThirdPersonCharacterBlueprint;
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
	this->Cube->OnComponentBeginOverlap.AddDynamic(this, &ACubeEntity::OnOverlapBegin);
}

void ACubeEntity::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	UE_LOG(LogTemp, Display, TEXT("Touchy"));
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		// Turn off the light  
		this->Cube->SetVisibility(false);
	}
}


// Called every frame
void ACubeEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->ChuteT += DeltaTime;

	FVector PreviousPos = this->GetActorLocation();

	float ground = 0;

	float newZ;
	if (PreviousPos.Z < ground) {
		this->ChuteT = 0;
		this->HeightSpawn = ground;
	}

	newZ = this->HeightSpawn - (this->Vitesse * this->ChuteT + this->Acceleration * pow(this->ChuteT, 2) / 2);

	this->SetActorLocation(FVector(PreviousPos.X, PreviousPos.Y, newZ));
}

