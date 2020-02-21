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

	UFUNCTION(BlueprintCallable)
	void AddToScore(int points);

	UStaticMeshComponent* m_pStaticMeshComponent;
};
