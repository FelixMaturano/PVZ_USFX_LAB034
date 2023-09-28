// Fill out your copyright notice in the Description page of Project Settings.

#include "Zombie.h"
#include "PVZ_USFX_LAB02GameModeBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"

#include "Plant.h"
#include "Proyectil.h"
// Sets default values
AZombie::AZombie()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshZombie = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Zombie Mesh"));

	MeshZombie->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//MeshZombie->SetSimulatePhysics(true);
	MeshZombie->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);

	MeshZombie->SetCollisionProfileName(UCollisionProfile::BlockAllDynamic_ProfileName);
	MeshZombie->SetupAttachment(RootComponent);

	RootComponent = MeshZombie;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));


	//Mesh o aspecto alternativo
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset2(TEXT("StaticMesh'/Game/StarterContent/Architecture/Pillar_50x500.Pillar_50x500'"));


	//Definición del mesh
	MeshZombie->SetStaticMesh(ZombieMeshAsset.Object);

	MeshZombie->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));


	energia = 200;
	Velocidad = 0.2f;

	Tags.Add(TEXT("Zombie"));

	//InitialLifeSpan = 5; //Para que el actor se destruya




}

// Called when the game starts or when spawned
void AZombie::BeginPlay()
{
	Super::BeginPlay();


	UWorld* const World = GetWorld();

	//Otra forma para que el actor se destruya
	//World->GetTimerManager().SetTimer(Temporizador, this, &AZombie::morir, 2, false);

}



// Called every frame
void AZombie::Tick(float DeltaTime)
{

	//if (Health <= 0)
	//{
	//	Destroy();
	//}

	//// Disparar continuamente hacia la izquierda
	//FireShot(FVector(0.0f, -1.0f, 0.0f));/*
	//if (Health <= 0)
	//{
	//	Destroy();
	//}
	//TiempoTranscurrido += DeltaTime;
	//if (TiempoTranscurrido >= TiempoEntreDisparos) {

	//	FireShot(FVector(0.0f, -1.0f, 0.0f));
	//	TiempoTranscurrido = 0.0f;
	//}*/
	//FVector LocalizacionObjetivo = FVector(-800.0f, -600.0f, 160.0f); // Cambia la ubicación objetivo según tus necesidades
	//// Calcula la dirección y distancia al objetivo
	//FVector Direccion = LocalizacionObjetivo - FVector(-800.0f, 400.0f, 160.0f);
	//// Calcula la distancia de al objetivo
	//float DistanciaAlObjetivo = FVector::Dist(LocalizacionObjetivo, this->GetActorLocation());


	Super::Tick(DeltaTime);

	//FVector LocalizacionObjetivo = FVector(-800.0f, -600.0f, 160.0f); // Cambia la ubicación objetivo según tus necesidades
	// Calcula la dirección y distancia al objetivo
	FVector Direccion = LocalizacionObjetivo - FVector(-800.0f,-600.0f, 160.0f);
	// Calcula la distancia de al objetivo
	float DistanciaAlObjetivo = FVector::Dist(LocalizacionObjetivo, this->GetActorLocation());




	// Calcula el desplazamiento en este frame
	float DeltaMove = Velocidad * GetWorld()->DeltaTimeSeconds;

	if (DeltaMove > DistanciaAlObjetivo)
	{
		// Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
		this->SetActorLocation(LocalizacionObjetivo);
		//this->SetActorRotation(NewRotation);
	}
	else
	{
		// Mueve el objeto en la dirección calculada
		this->AddActorWorldOffset(Direccion * DeltaMove);

	}


	//// Calcula el desplazamiento en este frame
	//float DeltaMove = Velocidad * GetWorld()->DeltaTimeSeconds;

	//if (DeltaMove > DistanciaAlObjetivo)
	//{
	//	// Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
	//	this->SetActorLocation(LocalizacionObjetivo);
	//	//this->SetActorRotation(NewRotation);
	//}
	//else
	//{
	//	// Mueve el objeto en la dirección calculada
	//	this->AddActorWorldOffset(Direccion * DeltaMove);

	//}

	////Super::Tick(DeltaTime);

	////FVector LocalizacionObjetivo = FVector(-800.0f, -600.0f, 160.0f); // Cambia la ubicación objetivo según tus necesidades
	////// Calcula la dirección y distancia al objetivo
	////FVector Direccion = LocalizacionObjetivo - FVector(-800.0f, 400.0f, 160.0f);
	////// Calcula la distancia de al objetivo
	////float DistanciaAlObjetivo = FVector::Dist(LocalizacionObjetivo, this->GetActorLocation());




	////// Calcula el desplazamiento en este frame
	////float DeltaMove = Velocidad * GetWorld()->DeltaTimeSeconds;

	////if (DeltaMove > DistanciaAlObjetivo)
	////{
	////	// Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
	////	this->SetActorLocation(LocalizacionObjetivo);
	////	//this->SetActorRotation(NewRotation);
	////}
	////else
	////{
	////	// Mueve el objeto en la dirección calculada
	////	this->AddActorWorldOffset(Direccion * DeltaMove);

	////}



	//////GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje")));

	//if (bEsMago)
	//{
	//	// Comportamiento del zombie mago
	//	if (bDesaparecido)
	//	{
	//		// El zombie está desaparecido, puedes controlar cuánto tiempo permanece así
	//		TiempoDesaparecido += DeltaTime;

	//		if (TiempoDesaparecido >= TiempoMaximoDesaparecido)
	//		{
	//			// El tiempo de desaparición ha terminado, haz que el zombie aparezca
	//			bDesaparecido = false;
	//			TiempoDesaparecido = 0.0f;

	//			// Cambia el carril en el que aparecerá el zombie mago
	//			CambiarCarril();
	//		}
	//	}
	//	else
	//	{
	//		// El zombie está aparecido, sigue un comportamiento normal hacia el objetivo
	//		FVector LocalizacionObjetivo = ObtenerNuevaLocalizacionObjetivo(); // Define tu propia lógica para obtener la ubicación objetivo
	//		// Resto del código para mover al zombie hacia LocalizacionObjetivo...
	//	}
	//}
	//else
	//{
	//	// Comportamiento del zombie normal
	//	FVector LocalizacionObjetivo = FVector(-800.0f, -600.0f, 160.0f); // Cambia la ubicación objetivo según tus necesidades
	//	// Resto del código para mover al zombie hacia LocalizacionObjetivo...
	//}

}


void AZombie::morir()
{
	Destroy();			//El actor se destruye
	this->Destroy();		//El actor también se destruye
	SetActorHiddenInGame(true);	//El actor sólo desaparece
}



void AZombie::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	//Destroy();
	AProyectil* proyectil = Cast<AProyectil>(Other);

	if (Other != proyectil) {
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje")));
		Other->Destroy();
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Nombre del otro actor: %s"), *Other->GetName()));

	}
	//Destroy();
	/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje")));
	Other->Destroy();*/
}

void AZombie::CambiarCarril()
{
	// Genera un número aleatorio para seleccionar un carril diferente
	int32 CarrilSeleccionado = FMath::RandRange(1, CantidadDeCarriles); // Asume que tienes una variable CantidadDeCarriles que indica cuántos carriles hay

	// Calcula la nueva ubicación X basada en el carril seleccionado
	float NuevaUbicacionX = CarrilSeleccionado * AnchoDelCarril; // Asume que tienes una variable AnchoDelCarril que indica el ancho de cada carril

	// Establece la nueva ubicación objetivo
	LocalizacionObjetivo.X = NuevaUbicacionX;
}

//FVector AZombie::ObtenerNuevaLocalizacionObjetivo()
//{
//	// En esta función, puedes calcular la ubicación de una planta cercana como objetivo.
//	// Aquí, asumimos que tienes un TArray llamado Plantas que contiene referencias a todas las plantas en el nivel.
//
//	//FVector MejorUbicacionObjetivo = FVector::ZeroVector;
//	//float MejorDistancia = MAX_FLT; // Valor inicial grande
//
//	//for (APlant* Planta )
//	//{
//	//	// Calcula la distancia entre el zombie y la planta
//	//	float Distancia = FVector::Dist(this->GetActorLocation(), Planta->GetActorLocation());
//
//	//	// Si la distancia es menor que la mejor distancia actual, actualiza el objetivo
//	//	if (Distancia < MejorDistancia)
//	//	{
//	//		MejorDistancia = Distancia;
//	//		MejorUbicacionObjetivo = Planta->GetActorLocation();
//	//	}
//	//}
//
//	//return MejorUbicacionObjetivo;
//}
//



