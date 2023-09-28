// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Grilla.h"
#include "GrillaAgua.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API AGrillaAgua : public AGrilla
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	AGrillaAgua();
	
};
