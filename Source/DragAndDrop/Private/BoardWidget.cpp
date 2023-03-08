// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardWidget.h"
#include "Components/GridPanel.h"
#include "BoardSquareWidget.h"
#include "Components/Image.h"

UBoardWidget::UBoardWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), Row(4), Column(4)
{}

void UBoardWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if(BoardSquareClass)
	{
		for(int i = 0; i < Row; ++i)
		{
			for(int j = 0; j < Column; ++j)
			{
				if(const auto BoardSquare = CreateWidget<UBoardSquareWidget>(this, BoardSquareClass))
				{
					BoardSquare->SetTextureBlank();
					BoardGrid->AddChildToGrid(BoardSquare, i, j);
				}
			}
		}
	}

	int32 PieceCol = 0;
	for(const auto& Piece: Pieces)
	{
		if(const auto BoardSquare = CreateWidget<UBoardSquareWidget>(this, BoardSquareClass))
		{
			BoardSquare->SetTexture(Piece.Value);
			PieceContainerGrid->AddChildToGrid(BoardSquare, 0,PieceCol);
			++PieceCol;
		}
	}
}
