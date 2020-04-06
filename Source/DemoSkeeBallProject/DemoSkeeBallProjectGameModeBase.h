// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "System/EHandle.h"
#include "System/NLogger.h"
#include "DemoSkeeBallProjectGameModeBase.generated.h"


UCLASS()
class DEMOSKEEBALLPROJECT_API ADemoSkeeBallProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:
	int m_iScore;
public:
	ADemoSkeeBallProjectGameModeBase();

	// ball pool
	TArray<EHANDLE> m_aEBalls;

	// win score set to 100 in constructor
	int m_iWinScore;

	// Functions

	void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	int GetScore();

	UFUNCTION(BlueprintCallable)
	void SetScore(int newScore);

};

/*
* Global Preprocessor Defintions
*/

// maximum number of balls in a game
#define MAX_NUM_BALLS 10