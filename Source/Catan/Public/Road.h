// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Placeable.h"
#include "Road.generated.h"

/**
 * 
 */
UCLASS()
class CATAN_API ARoad : public APlaceable
{
	GENERATED_BODY()
	

public:
	// Sets default values for this actor's properties
	ARoad();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	
	
};
