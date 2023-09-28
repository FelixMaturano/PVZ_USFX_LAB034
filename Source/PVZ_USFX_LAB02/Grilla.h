// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grilla.generated.h"


class UStaticMeshComponent;

UENUM()
enum class EHexTileType : uint8
{
	INVALIDO,
	PASTO,
	AGUA,

	MAX UMETA(Hidden)
};

UCLASS()
class PVZ_USFX_LAB02_API AGrilla : public AActor
{
	GENERATED_BODY()


	//public:
	//	UPROPERTY(VisibleInstanceOnly, BluePrintReadOnly, Category = "Tile")
	//	FIntPoint TileIndex;


	//public:
	//	UPROPERTY(VisibleInstanceOnly, BluePrintReadOnly, Category = "Tile")
	//	FIntPoint GrillaIndex;

protected:
	UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, Category = "Grilla")
	EHexTileType TipoGrilla;


	UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, Category = "Grilla")
	class UStaticMeshComponent* MeshGrilla;

	class UMaterial* MaterialGrilla0 = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Basic_Wall.M_Basic_Wall'"));

	class UMaterial* MaterialGrilla1 = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));

	class UMaterial* MaterialGrilla2 = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Concrete_Tiles.M_Concrete_Tiles'"));


public:
	// Sets default values for this actor's properties
	AGrilla();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;




	void ManejoClick();
	void Highlight(bool bOn);

	bool bIsActive;

	UPROPERTY()
	class AGridaManager* OwningGrid;

};
