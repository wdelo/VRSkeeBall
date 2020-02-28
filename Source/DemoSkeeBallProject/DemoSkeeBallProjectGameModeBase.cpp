// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoSkeeBallProjectGameModeBase.h"

ADemoSkeeBallProjectGameModeBase::ADemoSkeeBallProjectGameModeBase() : m_iWinScore(100) {}

void ADemoSkeeBallProjectGameModeBase::BeginPlay() {
	SetScore(0);
}

int ADemoSkeeBallProjectGameModeBase::GetScore() {
	return m_iScore;
}

void ADemoSkeeBallProjectGameModeBase::SetScore(int newScore) {
	m_iScore = newScore;
}




