// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeSpawner.h"
#include <time.h>

// Sets default values
ACubeSpawner::ACubeSpawner()
{
	srand(time(NULL));

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	this->Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	this->Cube->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ACubeSpawner::BeginPlay()
{
	Super::BeginPlay();


	this->Create_Cube();
}


// Called every frame
void ACubeSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ACubeSpawner::Create_Cube() {
	if (this->NbSpawn <= 0)
		return;

	//Spawn chunk
	FVector Loc = FVector(this->Cube->GetComponentLocation().X + (rand()%this->Range), this->Cube->GetComponentLocation().Y + (rand()%this->Range), 0.f);
	FRotator Rot = FRotator(0.0f, 0.0f, 0.0f);
	FTransform Tran = FTransform(Rot, Loc);

	UWorld* const World = GetWorld();

	if (World) {

		ACubeEntity* spawn = World->SpawnActorDeferred<ACubeEntity>(this->CubeClass, FTransform::Identity, this, NULL, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

		if (spawn) {
			spawn->Init(this->ThirdPersonCharacterBlueprint, this->Acceleration, this->Vitesse, this->Cube, this->HeightSpawn,this->Gravity);


			spawn->FinishSpawning(Tran);
		}

	}

	NbSpawn--;

	FTimerHandle TimerInfo;
	GetWorldTimerManager().SetTimer(TimerInfo, this, &ACubeSpawner::Create_Cube, 2.f);
}

