// Fill out your copyright notice in the Description page of Project Settings.


#include "Jugador.h"
#include "Zombie.h"
#include "Plant.h"
#include "Grilla.h"
#include "Sol.h"

#include "Kismet/GameplayStatics.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"


const FName AJugador::Spawns("MovimientoLateral");

//Sets default values
AJugador::AJugador()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	AJugador* GetViewTarget();
	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm


	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	CameraComponent->SetupAttachment(RootComponent);
	contador = 0;
	Localizacion = FVector(400.0, 400.0, 100.0);

}


//AJugador::AJugador(const FObjectInitializer& ObjectInitializer)
//	: Super(ObjectInitializer)
//{
//	AutoPossessPlayer = EAutoReceiveInput::Player0;
//}
//void AJugador::CalcCamera(float DeltaTime, FMinimalViewInfo& OutResult)
//{
//	Super::CalcCamera(DeltaTime, OutResult);
//
//	OutResult.Rotation = FRotator(-90.0f, -90.0f, 0.0f);
//}


// Called when the game starts or when spawned
void AJugador::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AJugador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Obtén el jugador que controla la cámara
	//PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0); // 0 para el primer jugador



	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
		{
			if (UCameraComponent* OurCamera = PC->GetViewTarget()->FindComponentByClass<UCameraComponent>())
			{

				FVector Start = OurCamera->GetComponentLocation();
				FVector End = Start + (OurCamera->GetComponentRotation().Vector() * 8000.0f);

				SeguimientoGrilla(Start, End, true);
				SeguimientoSol(Start, End, true);

			}
		}
		else
		{
			FVector Start, Dir, End;
			PC->DeprojectMousePositionToWorld(Start, Dir);

			End = Start + (Dir * 8000.0f);

			SeguimientoGrilla(Start, End, false);
			SeguimientoSol(Start, End, false);

		}

	}

}
// Called to bind functionality to input
void AJugador::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//PlayerInputComponent->BindAxis(MovimientoLateral);


	PlayerInputComponent->BindAxis(Spawns); //No funciona ya que esto es con valores y no es lo mismo que llamar a la función

	PlayerInputComponent->BindAction("Accion1", IE_Pressed, this, &AJugador::SpawnZombie); //Aquí sólo se llama a la función

	PlayerInputComponent->BindAction("Prueba click", EInputEvent::IE_Pressed, this, &AJugador::TriggerClick);


}


void AJugador::TriggerClick()
{
	if (GrillaActual)
	{
		GrillaActual->ManejoClick();
	}
	else if (SolActual)
	{
		SolActual->ManejoClick();
	}


}


void AJugador::SeguimientoGrilla(const FVector& Start, const FVector& End, bool bDrawDebugHelpers)
{
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility);
	if (bDrawDebugHelpers)
	{
		DrawDebugLine(GetWorld(), Start, HitResult.Location, FColor::Red);
		DrawDebugSolidBox(GetWorld(), HitResult.Location, FVector(20.0f), FColor::Red);
	}
	if (HitResult.Actor.IsValid())
	{
		AGrilla* Grilla = Cast<AGrilla>(HitResult.Actor.Get());
		if (GrillaActual != Grilla)
		{
			if (GrillaActual)
			{
				GrillaActual->Highlight(false);
			}
			if (Grilla)
			{
				Grilla->Highlight(true);
			}
			GrillaActual = Grilla;
		}
	}
	else if (GrillaActual)
	{
		GrillaActual->Highlight(false);
		GrillaActual = nullptr;
	}
}

void AJugador::SeguimientoSol(const FVector& Start, const FVector& End, bool bDrawDebugHelpers)
{
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility);
	if (bDrawDebugHelpers)
	{
		DrawDebugLine(GetWorld(), Start, HitResult.Location, FColor::Red);
		DrawDebugSolidBox(GetWorld(), HitResult.Location, FVector(20.0f), FColor::Red);
	}
	if (HitResult.Actor.IsValid())
	{
		ASol* Sol = Cast<ASol>(HitResult.Actor.Get());
		if (SolActual != Sol)
		{
			if (SolActual)
			{
				SolActual->Resaltado(false);
			}
			if (Sol)
			{
				Sol->Resaltado(true);
			}
			SolActual = Sol;
		}
	}
	else if (SolActual)
	{
		SolActual->Resaltado(false);
		SolActual = nullptr;
	}
}


void AJugador::SpawnZombie()
{
	//contador++;
	//AZombie* Zombie1 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), Localizacion, FRotator::ZeroRotator);


	//Localizacion.X = Localizacion.X - contador * 100;


	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Botón presionado")));


	if (PlayerController)
	{
		// Obtén la posición del cursor en el mundo
		PlayerController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

		// Puedes usar WorldLocation como la ubicación donde quieres colocar la planta
	}
	APlant* NewPlanta = GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), WorldLocation, FRotator::ZeroRotator);

}



