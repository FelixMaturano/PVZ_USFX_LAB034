// Fill out your copyright notice in the Description page of Project Settings.


#include "Girasol.h"
#include "Sol.h"

AGirasol::AGirasol()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshGirasol(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim.Shape_Trim'"));


	MeshPlanta->SetStaticMesh(MeshGirasol.Object);
	MeshPlanta->SetRelativeScale3D(FVector(3, 1, 3));
	energia = 150;

}

void AGirasol::BeginPlay()
{
	Super::BeginPlay();

	int Tiempo = FMath::RandRange(3, 6);

	UWorld* const World = GetWorld();

	World->GetTimerManager().SetTimer(Temporizador, this, &AGirasol::SpawnSoles, Tiempo, true);
}


void AGirasol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AGirasol::SpawnSoles()
{
	UWorld* const World = GetWorld();

	FVector Ubicacion = GetActorLocation();

	World->SpawnActor<ASol>(ASol::StaticClass(), FVector(Ubicacion.X, Ubicacion.Y, 100), FRotator::ZeroRotator);


}
