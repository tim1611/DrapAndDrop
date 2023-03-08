// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BoardSquareWidget.generated.h"

class UImage;
class UDragVisualWidget;

UCLASS()
class DRAGANDDROP_API UBoardSquareWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UBoardSquareWidget(const FObjectInitializer& ObjectInitializer);
	void SetTextureBlank();
	void SetTexture(UTexture2D* Texture2D);

protected:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

private:
	UPROPERTY(meta = (BindWidget))
	UImage* Image;

	UPROPERTY(EditAnywhere, Category = "Drag Visual")
	TSubclassOf<UDragVisualWidget> DragItemVisualClass;

	UPROPERTY(EditAnywhere)
	UTexture2D* BlankTexture;

	UPROPERTY(EditAnywhere)
	UTexture2D* CurrentTexture;

	bool IsTextureVisible;
};
