#pragma once

#include "GameState.h"
#include "DealVirtualPlayerState.h"
#include "GameEngine.h"

ref class DealPlayerState : 
	public GameState
{
public:
	// Represents a deal player state.
	//   gameEngine: The game engine.
	DealPlayerState(GameEngine^ gameEngine);

	// Represents a deal player state.
	//   gameState: The previous game state.
	DealPlayerState(GameState^ gameState);

	// Advances the game state if specific conditions are fulfilled.
	void nextState() override;
	
	// Gets the state description.
	String^ getStateDescription() override;
};

