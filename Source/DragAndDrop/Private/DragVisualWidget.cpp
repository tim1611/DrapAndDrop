// Fill out your copyright notice in the Description page of Project Settings.


#include "DragVisualWidget.h"

#include "Components/Image.h"


UDragVisualWidget::UDragVisualWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{}

void UDragVisualWidget::SetTexture(UTexture2D* Texture2D)
{
	Image->SetBrushFromTexture(Texture2D);
}
