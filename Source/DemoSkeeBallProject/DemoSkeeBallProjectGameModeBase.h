// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DemoSkeeBallProjectGameModeBase.generated.h"

UCLASS()
class DEMOSKEEBALLPROJECT_API ADemoSkeeBallProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:
	int m_iScore;
public:
	ADemoSkeeBallProjectGameModeBase();

	void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	int GetScore();

	UFUNCTION(BlueprintCallable)
	void SetScore(int newScore);

	int m_iWinScore;
};
