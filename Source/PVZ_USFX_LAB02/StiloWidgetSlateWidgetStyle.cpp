// Fill out your copyright notice in the Description page of Project Settings.


#include "StiloWidgetSlateWidgetStyle.h"

FStiloWidgetSlateStyle::FStiloWidgetSlateStyle()
{
}

FStiloWidgetSlateStyle::~FStiloWidgetSlateStyle()
{
}

const FName FStiloWidgetSlateStyle::TypeName(TEXT("FStiloWidgetSlateStyle"));

const FStiloWidgetSlateStyle& FStiloWidgetSlateStyle::GetDefault()
{
	static FStiloWidgetSlateStyle Default;
	return Default;
}

void FStiloWidgetSlateStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

