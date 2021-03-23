#pragma once

#include "GameState.h"
#include "PlayerTurnState.h"
#include "FinishedGameState.h"

ref class VirtualPlayerStealState :
	public GameState
{
private:
	// The virtual player plays a card.
	void virtualPlayerPlaysCard(Object^ object);

public:
	// Represents a virtual player steal state.
	//   gameState: The previous game state.
	VirtualPlayerStealState(GameState^ gameState);

	// Advances the game state if specific conditions are fulfilled.
	void nextState() override;

	// Gets the state description.
	String^ getStateDescription() override;
};

