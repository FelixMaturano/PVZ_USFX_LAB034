// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieCono.h"
#include "PVZ_USFX_LAB02GameModeBase.h"



AZombieCono::AZombieCono()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	MeshZombie->SetStaticMesh(ZombieMesh.Object);

	MeshZombie->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
}
