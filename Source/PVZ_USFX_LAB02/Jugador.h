
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Jugador.generated.h"

UCLASS(config = Game)
class PVZ_USFX_LAB02_API AJugador : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AJugador();

protected:
	//AJugador(const FObjectInitializer& ObjectInitializer);

	//virtual void CalcCamera(float DeltaTime, struct FMinimalViewInfo& OutResult) override;



	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	static const FName Spawns;

	void SpawnZombie();

	int contador;

	FVector Localizacion;




	//*******************************************************
	//Camara

	/** The camera */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }


	FVector WorldLocation, WorldDirection;
	APlayerController* PlayerController;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	class AGrilla* GrillaActual;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	class ASol* SolActual;



	void TriggerClick();

	void SeguimientoGrilla(const FVector& Start, const FVector& End, bool bDrawDebugHelpers);

	void SeguimientoSol(const FVector& Start, const FVector& End, bool bDrawDebugHelpers);

};
