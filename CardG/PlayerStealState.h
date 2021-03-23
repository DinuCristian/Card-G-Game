#pragma once

#include "GameState.h"
#include "VirtualPlayerTurnState.h"
#include "FinishedGameState.h"

ref class PlayerStealState :
	public GameState
{
private:
	// The virtual player plays a card.
	void virtualPlayerPlaysCard(Object^ object);

public:
	// Represents a player steal state.
	//   gameState: The previous game state.
	PlayerStealState(GameState^ gameState);

	// Advances the game state if specific conditions are fulfilled.
	void nextState() override;

	// Gets the state description.
	String^ getStateDescription() override;

	// Indicates whether there is the player can steal a card.
	bool isPlayerSteal() override;
};

