// Fill out your copyright notice in the Description page of Project Settings.


#include "LODSystemActor.h"

// Sets default values
ALODSystemActor::ALODSystemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Box"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> box_mesh(TEXT("/Game/Box.Box"));

	meshComponent->SetStaticMesh(box_mesh.Object);
}

// Called when the game starts or when spawned
void ALODSystemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALODSystemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

