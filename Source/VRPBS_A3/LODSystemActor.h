// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LODSystemActor.generated.h"

UCLASS(Blueprintable)
class VRPBS_A3_API ALODSystemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent *meshComponent;

	//LODs

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom LOD System")
	UStaticMesh *meshLow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom LOD System")
	UStaticMesh *meshMid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom LOD System")
	UStaticMesh *meshHigh;

	//Thresholds

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom LOD System")
	float lowThr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom LOD System")
	float highThr;

	// Sets default values for this actor's properties
	ALODSystemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
