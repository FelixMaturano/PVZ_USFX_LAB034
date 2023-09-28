// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieCubo.h"

AZombieCubo::AZombieCubo()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim_90_Out.Shape_Trim_90_Out'"));
	MeshZombie->SetStaticMesh(ZombieMesh.Object);
}

