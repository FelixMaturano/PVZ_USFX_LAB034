// Fill out your copyright notice in the Description page of Project Settings.

#include "HUDPlantas.h"
#include "SSeleccion_plantas.h"
#include "Widgets/SWeakWidget.h"
#include "GameFramework/PlayerController.h"

#include "Girasol.h"

#include "Engine.h"


void AHUDPlantas::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine && GEngine->GameViewport)
	{

		WidgetSeleccion = SNew(SSeleccion_plantas).OwningHUD(this);

		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(WidgetActivo, SWeakWidget).PossiblyNullContent(WidgetSeleccion.ToSharedRef()));

	}

}

void AHUDPlantas::QuitarHud()
{
	if (GEngine && GEngine->GameViewport && WidgetActivo.IsValid())
	{

		GEngine->GameViewport->RemoveViewportWidgetContent(WidgetActivo.ToSharedRef());

		if (PlayerOwner) {
			//PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}

}

void AHUDPlantas::SpawnPlanta()
{

	float localizacionX = FMath::RandRange(-800, -200);
	float localizacionY = FMath::RandRange(-520, 400);

	AGirasol* Girasol = GetWorld()->SpawnActor<AGirasol>(AGirasol::StaticClass(), FVector(localizacionX, localizacionY, 20), FRotator::ZeroRotator);

}

void AHUDPlantas::CambioPlanta1()
{

}

void AHUDPlantas::CambioPlanta2()
{

}
