// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grilla.h"
#include "GridaManager.generated.h"

class AGrilla;

UCLASS()
class PVZ_USFX_LAB02_API AGridaManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGridaManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddScore();




protected:

	TArray<TArray<class AGrilla*>> Grilla2dArray;


	UPROPERTY(EditAnywhere, Category = "DisposicionGrilla")
	int32 TamanoX;

	UPROPERTY(EditAnywhere, Category = "DisposicionGrilla")
	int32 TamanoY;


	UPROPERTY(EditAnywhere, Category = "DisposicionGrilla")
	float EspaciadoGrillaX;


	UPROPERTY(EditAnywhere, Category = "DisposicionGrilla")
	float EspaciadoGrillaY;



	UPROPERTY(EditAnywhere, Category = "DisposicionGrilla")
	TSubclassOf<AGrilla> GrillaPasto;

	UPROPERTY(EditAnywhere, Category = "DisposicionGrilla")
	TSubclassOf<AGrilla> GrillaAgua;


	TSubclassOf<AGrilla> GrillaSpawneada;

	float PosInicialX;
	float PosInicialY;


};
