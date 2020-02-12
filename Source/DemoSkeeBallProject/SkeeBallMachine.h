// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRBase/ABaseEntity/ABaseEntity.h"
#include "SkeeBallMachine.generated.h"
#include "Components/StaticMeshComponent.h"

UCLASS()
class DEMOSKEEBALLPROJECT_API ASkeeBallMachine : public ABaseEntity
{
	GENERATED_BODY()
public:
	ASkeeBallMachine();
	
	UStaticMshComponent* m_pStaticMeshComponent;
	
	
};
