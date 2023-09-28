// Fill out your copyright notice in the Description page of Project Settings.


#include "Grilla_Pasto.h"

void AGrilla_Pasto::BeginPlay()
{
	Super::BeginPlay();



}

AGrilla_Pasto::AGrilla_Pasto()
{
	TipoGrilla = EHexTileType::PASTO;

	MeshGrilla->SetMaterial(0, MaterialGrilla1);
}



