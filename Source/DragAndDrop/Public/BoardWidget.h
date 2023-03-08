// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BoardWidget.generated.h"

class UBoardSquareWidget;
class UGridPanel;


UCLASS()
class DRAGANDDROP_API UBoardWidget : public UUserWidget
{
	GENERATED_BODY()

	UBoardWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeOnInitialized() override;

private:
	UPROPERTY(EditAnywhere, Category = "Board Properties")
	TSubclassOf<UBoardSquareWidget> BoardSquareClass;

	UPROPERTY(EditAnywhere, Category = "Board Properties", meta = (BindWidget))
	UGridPanel* BoardGrid;

	UPROPERTY(EditAnywhere, Category = "Board Properties", meta = (BindWidget))
	UGridPanel* PieceContainerGrid;

	UPROPERTY(EditAnywhere, Category = "Board Properties")
	int32 Row;

	UPROPERTY(EditAnywhere, Category = "Board Properties")
	int32 Column;

	UPROPERTY(EditAnywhere, Category = "Board Properties")
	TMap<FString, UTexture2D*> Pieces;
	
};
