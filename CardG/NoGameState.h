#pragma once

#include "GameState.h"
#include "DealPlayerState.h"
#include "GameEngine.h"

ref class NoGameState :
	public GameState
{
public:
	// Represents a no game state.
	//   gameEngine: The game engine.
	NoGameState(GameEngine^ gameEngine);

	// Advances the game state if specific conditions are fulfilled.
	void nextState() override;

	// Gets the state description.
	String^ getStateDescription() override;
};

