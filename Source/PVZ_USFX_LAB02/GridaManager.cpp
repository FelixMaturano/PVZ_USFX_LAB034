// Fill out your copyright notice in the Description page of Project Settings.


#include "GridaManager.h"
#include "Grilla.h"
#include "GrillaAgua.h"
#include "Grilla_Pasto.h"

// Sets default values
AGridaManager::AGridaManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TamanoX = 10;
	TamanoY = 15;

	EspaciadoGrillaX = 100;
	EspaciadoGrillaY = 100;

	GrillaPasto = AGrilla_Pasto::StaticClass();

	GrillaAgua = AGrillaAgua::StaticClass();


}

// Called when the game starts or when spawned
void AGridaManager::BeginPlay()
{
	Super::BeginPlay();

	Grilla2dArray.SetNumZeroed(TamanoX);

	for (int32 i = 0; i < Grilla2dArray.Num(); i++)
	{
		Grilla2dArray[i].SetNumZeroed(TamanoY);
	}

	PosInicialX = -920;
	PosInicialY = -700;

	for (int32 y = 0; y < TamanoY; y++)
	{


		for (int32 x = 0; x < TamanoX; x++)
		{

			const float xPos = PosInicialX + x * EspaciadoGrillaX;
			const float yPos = PosInicialY + y * EspaciadoGrillaY;


			GrillaSpawneada = GrillaPasto;




			// Intercalado horizontal
			if (x % 2 == 0)
			{
				GrillaSpawneada = GrillaAgua;
			}
			else
			{
				GrillaSpawneada = GrillaPasto;
			}


			////Intercalado vertical
			//if (y % 2 == 0)
			//{
			//	GrillaSpawneada = GrillaAgua;
			//}
			//else
			//{
			//	GrillaSpawneada = GrillaPasto;
			//}


			// Formato de ajedrez
			//if ((x + y) % 2 == 0)
			//{
			//	GrillaSpawneada = GrillaAgua;
			//}
			//else
			//{
			//	GrillaSpawneada = GrillaPasto;
			//}


			AGrilla* nuevagrilla = GetWorld()->SpawnActor<AGrilla>(GrillaSpawneada, FVector(FIntPoint(xPos, yPos), 20), FRotator::ZeroRotator);


			//nuevagrilla->GrillaIndex = FIntPoint(x, y);
			//nuevagrilla->SetActorLabel(FString::Printf(TEXT("Tile_%d_%d"), x, y));
			//Grilla2dArray[x][y] = nuevagrilla;


		}
	}
}

// Called every frame
void AGridaManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGridaManager::AddScore()
{
	// Increment score
	//Score++;

	// Update text
	//ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(Score)));
}

