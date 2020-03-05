// Fill out your copyright notice in the Description page of Project Settings.

#include "SkeeBallMachine.h"
#include "DemoSkeeBallProjectGameModeBase.h"
#include "System/NLogger.h"

ASkeeBallMachine::ASkeeBallMachine() {

	m_pStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("static mesh");
	RootComponent = m_pStaticMeshComponent;

	UStaticMesh* mesh = FindMesh("StaticMesh'/Game/Meshes/SkeeBallMachine.SkeeBallMachine'");
	m_pStaticMeshComponent->SetStaticMesh(mesh);

	float scaleFactor = 1.5f;
	FVector scale = FVector(scaleFactor);
	m_pStaticMeshComponent->SetWorldScale3D(scale);

}

void ASkeeBallMachine::DefaultThink() {
	if (m_bHasPlayerWon) {
		Msg("You won!");
	}
}


void ASkeeBallMachine::AddToScore(int points) {
	ADemoSkeeBallProjectGameModeBase* mode = 
		Cast<ADemoSkeeBallProjectGameModeBase>(GetWorld()->GetAuthGameMode());
	if (mode) {
		// get current score
		int currScore = mode->GetScore();
		// add to score
		mode->SetScore(currScore + points);

		m_bHasPlayerWon = (mode->GetScore() >= mode->m_iWinScore);
	}
}

int ASkeeBallMachine::GetTheScore()
{
	ADemoSkeeBallProjectGameModeBase* mode = Cast<ADemoSkeeBallProjectGameModeBase>(GetWorld()->GetAuthGameMode());
	int score = -1;

	if (mode) score = mode->GetScore();

	return score;
}

