// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieComun.h"
#include "PVZ_USFX_LAB02GameModeBase.h"

AZombieComun::AZombieComun()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	MeshZombie->SetStaticMesh(ZombieMesh.Object);
	energia = 150;


}
