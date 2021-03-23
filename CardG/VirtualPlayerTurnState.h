#pragma once

#include "GameState.h"
#include "PlayerTurnState.h"
#include "VirtualPlayerStealState.h"
#include "GameEngine.h"

ref class VirtualPlayerTurnState :
	public GameState
{
private:
	// The virtual player plays a cards.
	void virtualPlayerPlaysCard(Object^ object);

	// The virtual player steals a card.
	void virtualPlayerStealsCard(Object^ object);

public:
	// Represents a virtual player turn state
	//   gameState: The previous game state.
	VirtualPlayerTurnState(GameState^ gameState);

	// Advances the game state if specific conditions are fulfilled.
	void nextState() override;

	// Gets the state description.
	String^ getStateDescription() override;

	// Indicates whether there is the virtual player turn.
	bool isVirtualPlayerTurn() override;
};

