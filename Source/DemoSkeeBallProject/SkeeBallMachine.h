// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRBase/ABaseEntity/ABaseEntity.h"
#include "Components/StaticMeshComponent.h"
#include "DemoSkeeBallProjectGameModeBase.h"
#include "SkeeBallMachine.generated.h"

UCLASS()
class DEMOSKEEBALLPROJECT_API ASkeeBallMachine : public ABaseEntity
{
	GENERATED_BODY()

public:
	ASkeeBallMachine();

	virtual void DefaultThink() override;

	UFUNCTION(BlueprintCallable)
	void AddToScore(int points);
	
	UFUNCTION(BlueprintCallable)
	int GetTheScore();

	UStaticMeshComponent* m_pStaticMeshComponent;
	bool m_bHasPlayerWon;
};
