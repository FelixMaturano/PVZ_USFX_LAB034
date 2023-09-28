// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"

#include "Plant.generated.h"


UCLASS()
class PVZ_USFX_LAB02_API APlant : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlant();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshPlanta;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	UPROPERTY(VisibleAnywhere)
	int energia;

	UFUNCTION()
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal,
		FVector NormalImpulse, const FHitResult& Hit)override;//esta funcion nos notifica cada golpe que de la clase.


};
