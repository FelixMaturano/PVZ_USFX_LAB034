// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"

#include "Zombie.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API AZombie : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AZombie();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshZombie;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float Velocidad;

	UPROPERTY(VisibleAnywhere)
	int energia;


	FTimerHandle Temporizador;

	void morir();

	FString TagString;



	// Agrega estas variables a la clase AZombie para controlar el comportamiento del zombie mago.
	bool bEsMago = false;               // Indica si este zombie es un mago o no.
	bool bDesaparecido = false;         // Indica si el zombie está desaparecido en este momento.
	float TiempoDesaparecido = 0.0f;    // Cuánto tiempo ha estado desaparecido.
	float TiempoMaximoDesaparecido = 5.0f; // Cuánto tiempo permanece desaparecido antes de reaparecer.
	int32 CantidadDeCarriles = 3;       // Cantidad de carriles disponibles para el zombie mago.
	float AnchoDelCarril = 1000.0f;     // Ancho de cada carril.
	FVector LocalizacionObjetivo;       // Ubicación objetivo actual del zombie.

	void CambiarCarril();

	//FVector ObtenerNuevaLocalizacionObjetivo();
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal,
		FVector NormalImpulse, const FHitResult& Hit)override;//esta funcion nos notifica cada golpe que de la clase.

	//// Agrega estas variables a la clase AZombie para controlar el comportamiento del zombie mago.
	//bool bEsMago = false;               // Indica si este zombie es un mago o no.
	//bool bDesaparecido = false;         // Indica si el zombie está desaparecido en este momento.
	//float TiempoDesaparecido = 0.0f;    // Cuánto tiempo ha estado desaparecido.
	//float TiempoMaximoDesaparecido = 5.0f; // Cuánto tiempo permanece desaparecido antes de reaparecer.
	//int32 CantidadDeCarriles = 3;       // Cantidad de carriles disponibles para el zombie mago.
	//float AnchoDelCarril = 1000.0f;     // Ancho de cada carril.
	//FVector LocalizacionObjetivo;       // Ubicación objetivo actual del zombie.



};
