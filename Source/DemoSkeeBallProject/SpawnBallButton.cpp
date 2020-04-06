// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnBallButton.h"
#include "DemoSkeeBallProjectGameModeBase.h"

ASpawnBallButton::ASpawnBallButton() {

	UStaticMesh* mesh = FindMesh("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'");
	m_pMeshComponent->SetStaticMesh(mesh);

	// creating static mesh that will represent the spawn location of the skee balls
	m_pSpawnLocationMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Location Mesh");

	UStaticMesh* location = FindMesh("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'");
	m_pSpawnLocationMeshComponent->SetStaticMesh(location);

	// setting scale to static meshes
	float scaleFactor = 0.1f;
	FVector scale = FVector(scaleFactor);
	m_pMeshComponent->SetWorldScale3D(scale);
	m_pSpawnLocationMeshComponent->SetWorldScale3D(scale);

	// set skeeball tracking index
	m_iBallIndex = 0;

}

void ASpawnBallButton::OnPressed_Implementation(ABaseController* pController) {

	// get spawn location
	FVector loc = m_pSpawnLocationMeshComponent->GetComponentLocation();

	// spawn skee ball at location
	ADemoSkeeBallProjectGameModeBase* mode = Cast<ADemoSkeeBallProjectGameModeBase>(GetWorld()->GetAuthGameMode());
	if (mode) {
		// if current number of balls is less than max number (10)
		if (mode->m_aEBalls.Num() < MAX_NUM_BALLS) {
			ASkeeBall* newSkeeBall = (ASkeeBall*) GetWorld()->SpawnActor(ASkeeBall::StaticClass(), &loc);

			Msg("Ball added");
			mode->m_aEBalls.Add(newSkeeBall->GetEHandle());

		}
		// if current num = max number
		else {

			Msg("Ball removed");
			mode->m_aEBalls.RemoveAt(m_iBallIndex); // doesn't actually remove an actor, but thinks it did, so another press will spawn an 11th ball

			if (m_iBallIndex >= MAX_NUM_BALLS - 1) {
				m_iBallIndex = 0;
				Msg("Index reset");
			} else {
				m_iBallIndex++;
				Msg("Index++");
			}
		}

	}
}


