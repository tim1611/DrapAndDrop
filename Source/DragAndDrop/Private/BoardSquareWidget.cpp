// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardSquareWidget.h"
#include "DragVisualWidget.h"
#include "Blueprint/DragDropOperation.h"
#include "Components/Image.h"


UBoardSquareWidget::UBoardSquareWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), IsTextureVisible(false)
{}

void UBoardSquareWidget::SetTextureBlank()
{
	Image->SetBrushFromTexture(BlankTexture);
	IsTextureVisible = false;
}

void UBoardSquareWidget::SetTexture(UTexture2D* Texture2D)
{
	Image->SetBrushFromTexture(Texture2D);
	IsTextureVisible = true;
	CurrentTexture = Texture2D;
}

FReply UBoardSquareWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

	if(InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		Reply.DetectDrag(TakeWidget(), EKeys::LeftMouseButton);
		return Reply;
	}

	return Reply;
}

void UBoardSquareWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent,
	UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);

	if(DragItemVisualClass)
	{
		if(IsTextureVisible)
		{
			SetTextureBlank();
			UDragVisualWidget* DragVisualWidget = CreateWidget<UDragVisualWidget>(this, DragItemVisualClass);
			DragVisualWidget->SetTexture(CurrentTexture);

			UDragDropOperation* DragDropOperation = NewObject<UDragDropOperation>();
			DragDropOperation->Payload = CurrentTexture;

			DragDropOperation->DefaultDragVisual = DragVisualWidget;
			DragDropOperation->Pivot = EDragPivot::CenterCenter;

			OutOperation = DragDropOperation;
		}
	}
}

bool UBoardSquareWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);

	UTexture2D* NewTexture =  Cast<UTexture2D>(InOperation->Payload);
	SetTexture(NewTexture);

	return true;
}
