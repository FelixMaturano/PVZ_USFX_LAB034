// Fill out your copyright notice in the Description page of Project Settings.


#include "Lanza_Guisantes.h"

ALanza_Guisantes::ALanza_Guisantes()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlantaMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	MeshPlanta->SetStaticMesh(PlantaMesh.Object);
	MeshPlanta->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));

	CantidadDisparos = 5;
}
