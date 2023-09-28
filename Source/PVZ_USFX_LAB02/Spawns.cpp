// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawns.h"
#include "Zombie.h"
#include "Plant.h"
#include "Jugador.h"

// Sets default values
ASpawns::ASpawns()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawns::BeginPlay()
{
	Super::BeginPlay();


	//AZombie* Zombie1 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), FVector(400.0, 200.0, 100.0), FRotator::ZeroRotator);




	//float RandomX = FMath::RandRange(-1000, 1000);
	//float RandomY = FMath::RandRange(-1000, 1000);
	//float Z = 200; // Altura en Z

	//FVector SpawnLocation = FVector(RandomX, RandomY, Z);

	//APlant* Planta1 = GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), FVector(RandomX, RandomY, Z), FRotator(150,253,180));
	//


	////AJugador* Jugador = GetWorld()->SpawnActor<AJugador>(AJugador::StaticClass(), FVector(RandomX, RandomY, Z), FRotator(150, 253, 180));


	//UWorld* const World = GetWorld();
	//World->GetTimerManager().SetTimer(Temporizador, this, &ASpawns::spawnplanta, 2, false);


}

// Called every frame
void ASpawns::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawns::spawnplanta()
{

	//Se crean las plantas dinamicamente
	FVector SpawnLocationPlant = FVector(-800.0f, -600.0f, 160.0f);
	FVector SpawnLocationPlantTemp = SpawnLocationPlant;


	for (int i = 0; i < 5; i++) {
		SpawnLocationPlantTemp.X += 100;
		for (int j = 0; j < 2; j++) {
			SpawnLocationPlantTemp.Y += 80;
			APlant* NuevoPlant = GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), SpawnLocationPlantTemp, FRotator::ZeroRotator);
			vectorPlants.Add(NuevoPlant);
			//	SpawnLocationPlant = SpawnLocationPlantTemp;
		}
		SpawnLocationPlantTemp.Y = SpawnLocationPlant.Y;
	}

}

