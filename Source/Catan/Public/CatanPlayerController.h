// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "Tile.h"
#include "CatanDefaultCharacter.h"
#include "HelperFunctions.h"
#include "CatanPlayerState.h"
#include "Road.h"
#include "CatanWidget.h"
#include "Enums/InputMode.h"
#include "Enums/TileEdge.h"
#include "CatanPlayerController.generated.h"



/**
 * 
 */
UCLASS()
class CATAN_API ACatanPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	ACatanPlayerController();

	void SetupInputComponent() override;

	UFUNCTION(BlueprintCallable, Category = "ClickFunctions")
	void clickPurchase();

	UFUNCTION(BlueprintCallable, Category = "ClickFunctions")
	void clickBuySettlement();

	UFUNCTION(BlueprintCallable, Category = "ClickFunctions")
	void clickBuyCity();

	UFUNCTION(BlueprintCallable, Category = "ClickFunctions")
	void clickBuyRoad();

	UFUNCTION(BlueprintCallable, Category = "ClickFunctions")
	void clickRoll();

	UFUNCTION(BlueprintCallable, Category = "ClickFunctions")
	void clickConfirmRoadPlacement();

	UFUNCTION(Client, Reliable, WithValidation, BlueprintCallable, Category = "HUDFunctions")
	void setHUD(TSubclassOf<class UCatanWidget> newHUD);

	void UpdateSelection();

	void RotateRoad();

	UFUNCTION(BlueprintCallable, Category = "GameModeFunctions", Reliable, Server, WithValidation)
	void EndTurnServer();

	UFUNCTION(Reliable, Server, WithValidation)
	void ConfirmRoadServer(uint8 row, uint8 col, EVertex vertex);

	UFUNCTION(Reliable, Server, WithValidation)
	void RotateRoadServer(uint8 row, uint8 col, EVertex vertex);

	UFUNCTION(Reliable, Server, WithValidation)
	void SpawnSettlement(uint8 row, uint8 col, EVertex vertex, ACatanPlayerState * player_state);

	UFUNCTION(Reliable, Server, WithValidation)
	void SpawnCity(uint8 row, uint8 col, EVertex vertex, ACatanPlayerState * player_state);

	UFUNCTION(Reliable, Server, WithValidation)
	void SpawnRoad(uint8 row, uint8 col, EVertex vertex, ACatanPlayerState * player_state);

	UFUNCTION(Reliable, Server, WithValidation)
	void RollServer(ACatanPlayerState * player_state);

private:


	TSubclassOf<class UCatanWidget> changeHUD;

	EInputMode inputMode;

	void highlightTiles();

	UPROPERTY()
	uint32 selectionRow;

	UPROPERTY()
	uint32 selectionCol;

	UPROPERTY()
	EVertex selectedVertex;

	// used for rotating road after placement
	ARoad * lastPlacedRoad;

	//index of last referenced placeablearea -- used to rotate road around
	uint8 lastPlaceRoadConnectionIndex;

	FVector getPlacementLocation(EVertex vertex, FVector tileLocation);
};
