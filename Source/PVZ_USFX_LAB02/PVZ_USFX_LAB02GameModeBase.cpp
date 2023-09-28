// Copyright Epic Games, Inc. All Rights Reserved.


#include "PVZ_USFX_LAB02GameModeBase.h"
#include "Spawns.h"
#include "Zombie.h"
#include "Plant.h"
//#include "Sol.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/Engine.h"
#include "TimerManager.h"

#include "Jugador.h"
#include "Controlador.h"
#include "HUDPlantas.h"


#include "Planta_Ataque.h"
#include "Lanza_Guisantes.h"

#include "ZombieComun.h"
#include "ZombieCono.h"
#include "ZombieCubo.h"

APVZ_USFX_LAB02GameModeBase::APVZ_USFX_LAB02GameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;

	//Definiendo el Pawn o Peon
	DefaultPawnClass = AJugador::StaticClass();
	//Definiendo el Controlador
	PlayerControllerClass = AControlador::StaticClass();
	//Definiendo el HUD
	HUDClass = AHUDPlantas::StaticClass();



	contador = FVector(0, 0, 0);
	localizacion = FVector(400.0, 200.0, 100.0);
	contador2 = 0;

	TiempoTranscurrido = 0.0f;


	FilaActual = 1;
	ColumnaActual = 1;

}

void APVZ_USFX_LAB02GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// Definición de un objeto de tipo World
	UWorld* const World = GetWorld();

	//ASpawns* Spawn1 = GetWorld()->SpawnActor<ASpawns>(ASpawns::StaticClass(), FVector(0,0,0), FRotator::ZeroRotator);
	// 
	//AZombie* Zombie1 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), FVector(400.0, 200.0, 100.0), FRotator::ZeroRotator);



	//World->GetTimerManager().SetTimer(Temporizador, this, &APVZ_USFX_LAB02GameModeBase::Spawn, 2, true);

	//Aparición de los soles
	//ASol* Sol1 = GetWorld()->SpawnActor<ASol>(ASol::StaticClass(), FVector(-400,-50,160), FRotator::ZeroRotator);
	//ASol* Sol2 = GetWorld()->SpawnActor<ASol>(ASol::StaticClass(), FVector(-450, -50, 160), FRotator::ZeroRotator);

	////Definiendo la posición de los zombies
	//FVector SpawnLocationZombie = FVector(-920.0f, 400.0f, 22.0f);

	//// Genera 5 zombies
	//for (int i = 0; i < 7; i++) {
	//	// Define una posición temporal para el zombie en X
	//	SpawnLocationZombie.X += 100;
	//	// Aparicion de los zombies


	//	NuevoZombie = GetWorld()->SpawnActor<AZombieComun>(AZombieComun::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

	//	NuevoZombie->Velocidad = FMath::FRandRange(0.1, 0.5);

	//	Zombies.Add(NuevoZombie);

	//}


	APVZ_USFX_LAB02GameModeBase::GenerarHordaDeZombies();


	//Definiendo la posición de las plantas
	FVector SpawnLocationPlant = FVector(-920.0f, -600.0f, 22.0f);
	FVector SpawnLocationPlantTemp = SpawnLocationPlant;

	// Genera 5 plantas
	for (int i = 0; i < 7; i++)
	{
		//Define una posicion temporal para la planta en X
		SpawnLocationPlantTemp.X += 100;



		for (int j = 0; j < 2; j++)
		{

			// Define una posición temporal para la planta en Y
			SpawnLocationPlantTemp.Y += 100;

			// Genera un nombre para la planta
			NombrePlanta = FString::Printf(TEXT("Planta %d_%d"), i + 1, j + 1); // Cambio en la generación del nombre

			// Crea una nueva instancia de APlant en el mundo
			NuevaPlantaGuisante = GetWorld()->SpawnActor<ALanza_Guisantes>(ALanza_Guisantes::StaticClass(), SpawnLocationPlantTemp, FRotator::ZeroRotator);

			// Asigna un valor aleatorio a la energía de la planta
			NuevaPlantaGuisante->energia = FMath::FRandRange(0.0, 10.0);

			// Muestra un mensaje en la consola
			//UE_LOG(LogTemp, Warning, TEXT("Energía de %s: %i"), *NombrePlanta, NuevaPlanta->energia);

			// Muestra un mensaje en la pantalla
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Energía de %s: %i"), *NombrePlanta, NuevaPlantaGuisante->energia));
			// Muestra un mensaje en el registro de errores
			UE_LOG(LogTemp, Warning, TEXT("Energía de %s: %i"), *NombrePlanta, NuevaPlantaGuisante->energia);

			// Agrega la planta al contenedor de plantas
			Plantas.Add(NombrePlanta, NuevaPlantaGuisante);


			Plantas2.Add(NuevaPlantaGuisante);


			// Coloca la planta en una posición diferente
			//NuevaPlanta->SetActorLocation(FVector(i * 100, 0, 0));


		}
		// Define una posición temporal para la planta en Y
		SpawnLocationPlantTemp.Y = SpawnLocationPlant.Y;

	}

	//FString Mensaje = FString::Printf(TEXT("Encontrada planta: %s"), *NombrePlanta);
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, Mensaje);


	//World->GetTimerManager().SetTimer(Temporizador, this, &APVZ_USFX_LAB02GameModeBase::aumentovelocidad, 1, true);

	World->GetTimerManager().SetTimer(Temporizador2, this, &APVZ_USFX_LAB02GameModeBase::MostrarEnergiaDePlantas, 1.f, true);


}




void APVZ_USFX_LAB02GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TiempoTranscurrido += DeltaTime;

	//if (TiempoTranscurrido > 2.0f) {
	//	// Iterar sobre el vector de objetos
	//	for (int i = 0; i < Zombies.Num(); i++) {
	//		Zombies[i]->Velocidad = FMath::FRand() * 2.0f;

	//		//Zombies[i]->MovementSpeed += i * 1.0f;
	//	}
	//	TiempoTranscurrido = 0.0f;
	// 
	//}

	//if (TiempoTranscurrido > 5.0f) {
	//	// Iterar sobre el vector de objetos
	//	for (int i = 0; i < Plantas2.Num(); i++) {
	//		int vtemp= Plantas2[i]->energia;
	//		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Energía de %s: %i"), *NombrePlanta, vtemp));

	//		
	//	}
	//	TiempoTranscurrido = 0.0f;
	//}



}

void APVZ_USFX_LAB02GameModeBase::Spawn()
{
	contador2++;

	contador = contador + FVector(100, 0, 0);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje")));


	AZombie* Zombie1 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), localizacion, FRotator::ZeroRotator);



	localizacion.X = localizacion.X + contador2 * 100;
	localizacion.Y = localizacion.Y + contador2 * 100;
	//localizacion = localizacion + contador;




}

void APVZ_USFX_LAB02GameModeBase::aumentovelocidad()
{

	for (int i = 0; i < Zombies.Num(); i++)
	{
		Zombies[i]->Velocidad = +FMath::FRandRange(0, 0.2);
	}

}

void APVZ_USFX_LAB02GameModeBase::MostrarEnergiaDePlantas()
{

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje")));

	NombrePlanta = FString::Printf(TEXT("Planta %d_%d"), FilaActual, ColumnaActual);

	APlant* Planta = Plantas.FindRef(NombrePlanta);

	if (Planta)
	{
		FString Mensaje = FString::Printf(TEXT("%s: Energia %i"), *NombrePlanta, Planta->energia);

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, Mensaje);

		UE_LOG(LogTemp, Warning, TEXT("%s"), *Mensaje);

	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("No se encontró la planta")));
	}

	ColumnaActual++;

	if (ColumnaActual > 2) // Ajusta este valor al número total de columnas
	{
		ColumnaActual = 1;
		FilaActual++;

		if (FilaActual > 5) // Ajusta este valor al número total de filas
		{
			FilaActual = 1;
		}
	}

}


void APVZ_USFX_LAB02GameModeBase::GenerarHordaDeZombies()
{
	// Limpiar cualquier zombie existente en la TArray
	Zombies.Empty();
	FVector SpawnLocationZombie = FVector(-920.0f, 400.0f, 22.0f);
	const float SeparacionEntreZombies = 100.0f; // Separación fija de 100 unidades

	// Generar dos zombies cono
	for (int32 i = 0; i < 2; i++) {
		 NuevoZombieCono = GetWorld()->SpawnActor<AZombieCono>(AZombieCono::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

		if (NuevoZombieCono)
		{
			Zombies.Add(NuevoZombieCono);
		}

		// Aumenta la posición X para la siguiente generación
		SpawnLocationZombie.X += SeparacionEntreZombies;
	}

	// Generar dos zombies cubo
	SpawnLocationZombie = FVector(-920.0f + SeparacionEntreZombies, 400.0f, 22.0f); // Reinicia la posición con separación
	for (int32 i = 0; i < 2; i++) {
		 NuevoZombieCubo = GetWorld()->SpawnActor<AZombieCubo>(AZombieCubo::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

		if (NuevoZombieCubo)
		{
			Zombies.Add(NuevoZombieCubo);
		}

		// Aumenta la posición X para la siguiente generación
		SpawnLocationZombie.X += SeparacionEntreZombies;
	}

	// Generar Zombies Comunes
	SpawnLocationZombie = FVector(-920.0f + SeparacionEntreZombies, 400.0f, 22.0f); // Reinicia la posición con separación
	for (int32 i = 0; i < 8; i++) {
		NuevoZombie = GetWorld()->SpawnActor<AZombieComun>(AZombieComun::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

		if (NuevoZombie)
		{
			Zombies.Add(NuevoZombie);
		}

		// Aumenta la posición X para la siguiente generación
		SpawnLocationZombie.X += SeparacionEntreZombies;
	}
}