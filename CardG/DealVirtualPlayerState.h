#pragma once

#include "GameState.h"
#include "VirtualPlayerTurnState.h"
#include "GameEngine.h"

using namespace System::Threading;

ref class DealVirtualPlayerState :
	public GameState
{
private:
	// The virtual player plays a card.
	void virtualPlayerPlaysCard(Object^ object);

public:
	// Represents a deal virtual player state.
	//   gameState: The previous game state.
	DealVirtualPlayerState(GameState^ gameState);

	// Advances the game state if specific conditions are fulfilled.
	void nextState() override;

	// Gets the state description.
	String^ getStateDescription() override;
};

