// Fill out your copyright notice in the Description page of Project Settings.


#include "DragDropController.h"
#include "BoardWidget.h"

void ADragDropController::BeginPlay()
{
	Super::BeginPlay();
	
	FInputModeGameAndUI InputMode;

	InputMode.SetHideCursorDuringCapture(false);
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);

	SetInputMode(InputMode);
	

	if(UBoardWidget* Board = CreateWidget<UBoardWidget>(this, BoardClass))
	{
		Board->AddToViewport();
		Board->SetVisibility(ESlateVisibility::Visible);
	}
}
