// Fill out your copyright notice in the Description page of Project Settings.

#include "SkeeBallMachine.h"


ASkeeBallMachine::ASkeeBallMachine() {

	m_pStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("static mesh");
	RootComponent = m_pStaticMeshComponent;

	UStaticMesh* mesh = FindMesh("StaticMesh'/Game/Meshes/SkeeBallMachine.SkeeBallMachine'");
	m_pStaticMeshComponent->SetStaticMesh(mesh);

	float scaleFactor = 1.5f;
	FVector scale = FVector(scaleFactor);
	m_pStaticMeshComponent->SetWorldScale3D(scale);

}

void ASkeeBallMachine::AddToScore(int points) {
	ADemoSkeeBallProjectGameModeBase* mode = 
		Cast<ADemoSkeeBallProjectGameModeBase>(GetWorld()->GetAuthGameMode());
	if (mode) {
		// get current score
		int currScore = mode->GetScore();
		// add to score
		mode->SetScore(currScore + points);
	}
}

