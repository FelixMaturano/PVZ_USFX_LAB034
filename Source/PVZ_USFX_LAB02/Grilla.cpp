// Fill out your copyright notice in the Description page of Project Settings.


#include "Grilla.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"
#include "Girasol.h"




// Sets default values
AGrilla::AGrilla()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	MeshGrilla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	MeshGrilla->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ModeloGrilla0(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Plane.Shape_Plane'"));
	MeshGrilla->SetStaticMesh(ModeloGrilla0.Object);

	MeshGrilla->SetMaterial(0, MaterialGrilla0);// Assign newly defined material to mesh component


	TipoGrilla = EHexTileType::INVALIDO;

}

// Called when the game starts or when spawned
void AGrilla::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGrilla::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGrilla::ManejoClick()
{
	// Check we are not already active
	if (!bIsActive)
	{
		bIsActive = true;

		//localizacion actual del actor
		FVector Localizacion = GetActorLocation();

		// Spawn del actor
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Grilla ocupada: %s"), *GetName()));
		AGirasol* Girasol = GetWorld()->SpawnActor<AGirasol>(AGirasol::StaticClass(), FVector(Localizacion.X, Localizacion.Y, Localizacion.Z + 5), FRotator::ZeroRotator);

		// Tell the Grid
		if (OwningGrid != nullptr)
		{
			//OwningGrid->AddScore();

		}
	}
}


void AGrilla::Highlight(bool bOn)
{
	// Do not highlight if the block has already been activated.
	if (bIsActive)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("1Grilla a usar: %s"), *GetName()));
		return;
	}

	if (bOn)
	{
		//BlockMesh->SetMaterial(0, BaseMaterial);
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Grilla sin ocupar: %s"), *GetName()));

	}
	else
	{
		//BlockMesh->SetMaterial(0, BlueMaterial);
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Nose xd")));

	}
}

