// Fill out your copyright notice in the Description page of Project Settings.


#include "GrillaAgua.h"

void AGrillaAgua::BeginPlay()
{
	Super::BeginPlay();
}

AGrillaAgua::AGrillaAgua()
{
	TipoGrilla = EHexTileType::AGUA;

	MeshGrilla->SetMaterial(0, MaterialGrilla2);

}
