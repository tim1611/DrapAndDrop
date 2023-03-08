// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DragDropController.generated.h"

class UBoardWidget;

UCLASS()
class DRAGANDDROP_API ADragDropController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UBoardWidget> BoardClass;
};
