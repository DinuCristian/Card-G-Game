#pragma once

#include "GameState.h"
#include "PlayerStealState.h"
#include "VirtualPlayerTurnState.h"
#include "FinishedGameState.h"
#include "GameEngine.h"

ref class PlayerTurnState :
	public GameState
{
private:
	// The virtual player plays a card.
	void virtualPlayerPlaysCard(Object^ object);

public:
	// Represents a player turn state.
	//   gameState: The previous game state.
	PlayerTurnState(GameState^ gameState);

	// Advances the game state if specific conditions are fulfilled.
	void nextState() override;

	// Gets the state description.
	String^ getStateDescription() override;

	// Indicates whether there is the player turn.
	bool isPlayerTurn() override;
};

