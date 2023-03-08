// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DragVisualWidget.generated.h"

class UImage;

UCLASS()
class DRAGANDDROP_API UDragVisualWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UDragVisualWidget(const FObjectInitializer& ObjectInitializer);
	void SetTexture(UTexture2D* Texture2D);

private:
	UPROPERTY(EditAnywhere, Category = "Visual", meta = (BindWidget))
	UImage* Image;
};
