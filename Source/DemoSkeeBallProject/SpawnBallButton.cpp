// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnBallButton.h"

ASpawnBallButton::ASpawnBallButton() {

	// creating static mesh that will represent the spawn location of the skee balls
	m_pSpawnLocationMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Ball Spawn Location");

	UStaticMesh* location = FindMesh("StaticMesh'/Game/Meshes/Cube.Cube'");
	m_pSpawnLocationMeshComponent->SetStaticMesh(location);

	// setting scale to static meshes
	float scaleFactor = 0.05f;
	FVector scale = FVector(scaleFactor);
	m_pMeshComponent->SetWorldScale3D(scale);
	m_pSpawnLocationMeshComponent->SetWorldScale3D(scale);

}

void ASpawnBallButton::OnPressed_Implementation(ABaseController* pController) {

	// get spawn location
	FVector loc = m_pSpawnLocationMeshComponent->GetComponentLocation();

	// spawn skee ball at location
	ASkeeBall* skeeBall = (ASkeeBall*)
	GetWorld()->SpawnActor(ASkeeBall::StaticClass(), &loc);

}


