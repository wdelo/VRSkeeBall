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
	void BeginPlay() override;
	int GetScore();
	void SetScore(int newScore);
	
};
