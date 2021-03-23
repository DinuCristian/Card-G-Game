#pragma once

#include "GameState.h"

ref class FinishedGameState :
	public GameState
{
public:
	// Represents a finished game state.
	//   gameState: The previous game state.
	FinishedGameState(GameState^ gameState);

	// Advances the game state if specific conditions are fulfilled.
	void nextState() override;
	
	// Gets the state description.
	String^ getStateDescription() override;

	// Indicates whether the game is finished.
	bool isGameFinished() override;
};

