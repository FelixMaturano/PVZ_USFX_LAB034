#include "SSeleccion_plantas.h"
#include "SlateOptMacros.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SBorder.h"
#include "HUDPlantas.h"

void SSeleccion_plantas::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;
	OwningHUD = InArgs._OwningHUD;

	FMargin ContentPadding = FMargin(30, 20);

	FMargin ButtonPadding = FMargin(200, 20, 10, 5);


	const FText TitleText = FText::FromString("Seleccion \n de \nplantas");
	const FText ButtonText = FText::FromString("Cerrar HUD");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 25.f;

	FSlateFontInfo TitleTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	TitleTextStyle.Size = 30.f;

	ChildSlot
		[
			// Agrega el fondo
			SNew(SOverlay)

				+ SOverlay::Slot()
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Top)
				.Padding(ButtonPadding) // Ajusta el relleno según sea necesario

				[
					// Caja horizontal
					SNew(SBox)
						.WidthOverride(1000) // Ancho del fondo
						.HeightOverride(100) // Altura del fondo
						.HAlign(HAlign_Fill)
						.VAlign(VAlign_Fill)

						[
							SNew(SBorder)
								.BorderBackgroundColor(FColor::Blue)// Color del borde
								[
									SNew(SOverlay)
										+ SOverlay::Slot()
										[
											// Imagen de fondo
											SNew(SImage)
												.ColorAndOpacity(FColor::Black)
										]
										+ SOverlay::Slot()
										[
											SNew(SHorizontalBox)
												//Boton 1
												+ SHorizontalBox::Slot()
												[
													SNew(SButton)
														//Llamando a la funcion OnClicked
														.OnClicked(this, &SSeleccion_plantas::OnClicked)
														[
															SNew(STextBlock)
																.Font(ButtonTextStyle)
																.Text(FText::FromString("Planta 1"))
																.Justification(ETextJustify::Center)
														]
												]
												//Boton 2
												+ SHorizontalBox::Slot()
												[
													SNew(SButton)
														//Llamando a la funcion OnClicked
														.OnClicked(this, &SSeleccion_plantas::OnClicked)
														[
															SNew(STextBlock)
																.Font(ButtonTextStyle)
																.Text(FText::FromString("Planta 2"))
																.Justification(ETextJustify::Center)
														]
												]
												//Boton 3
												+ SHorizontalBox::Slot()
												[
													SNew(SButton)
														//Llamando a la funcion SpawnPlanta
														.OnClicked(this, &SSeleccion_plantas::SpawnPLanta)
														[
															SNew(STextBlock)
																.Font(ButtonTextStyle)
																.Text(FText::FromString("Spawn planta"))
																.Justification(ETextJustify::Center)
														]
												]
												//Boton quitar menu
												+ SHorizontalBox::Slot()
												[
													SNew(SButton)
														.OnClicked(this, &SSeleccion_plantas::QuitarMenu)
														[
															SNew(STextBlock)
																.Font(ButtonTextStyle)
																.Text(ButtonText)
																.Justification(ETextJustify::Center)
														]
												]
										]
								]
						]
				]
				//Titulo
				+ SOverlay::Slot()
				.HAlign(HAlign_Left)
				.VAlign(VAlign_Top)
				[
					SNew(SBox)
						.WidthOverride(200)
						.HeightOverride(200)
						.HAlign(HAlign_Fill)
						.VAlign(VAlign_Fill)
						[
							SNew(SHorizontalBox)
								+ SHorizontalBox::Slot()
								[
									SNew(STextBlock)
										.Justification(ETextJustify::Center)
										.Font(TitleTextStyle)
										.Text(TitleText)
								]

						]
				]

		];

	//ChildSlot[
	//	SNew(SOverlay)
	//		+ SOverlay::Slot()
	//		.HAlign(HAlign_Right)
	//		.VAlign(VAlign_Bottom)
	//		[
	//			SNew(SImage)
	//				.ColorAndOpacity(FColor::Black)
	//		]

	//];







}

//FReply SSeleccion_plantas::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
//{
//	return FReply::Handled();
//}

FReply SSeleccion_plantas::OnClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Boton 1"));
	return FReply::Handled();
}


FReply SSeleccion_plantas::QuitarMenu()
{
	if (OwningHUD.IsValid())
	{
		OwningHUD->QuitarHud();
	}

	return FReply::Handled();

}

FReply SSeleccion_plantas::SpawnPLanta()
{

	if (OwningHUD.IsValid())
	{
		OwningHUD->SpawnPlanta();

	}

	return FReply::Handled();
}


