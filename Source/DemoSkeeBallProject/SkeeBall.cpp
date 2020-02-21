// Fill out your copyright notice in the Description page of Project Settings.

#include "SkeeBall.h"

ASkeeBall::ASkeeBall() {

	m_pPickupMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("static mesh");
	RootComponent = m_pPickupMeshComponent;

	UStaticMesh* mesh = FindMesh("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'");
	m_pPickupMeshComponent->SetStaticMesh(mesh);

	float scaleFactor = 0.1f;
	FVector scale = FVector(scaleFactor);
	m_pPickupMeshComponent->SetWorldScale3D(scale);

}


