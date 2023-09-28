// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectil_Fuego.h"

AProyectil_Fuego::AProyectil_Fuego()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FuegoMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));

	MeshBala->SetStaticMesh(FuegoMesh.Object);

}
