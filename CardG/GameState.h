#pragma once

using namespace System;

ref class GameEngine;

ref class GameState abstract
{
protected:
	// The game engine.
	GameEngine^ gameEngine;

	// Indicates whether a game is underway.
	bool gameUnderway;

public:
	// Represents a game state.
	GameState();

	// Represents a game state.
	//   gameState: The previous game state.
	GameState(GameState^ gameState);

	// Advances the game state if specific conditions are fulfilled.
	virtual void nextState() = 0;
	
	// Gets the state description.
	virtual String^ getStateDescription();
	
	// Indicates whether there is the player turn.
	virtual bool isPlayerTurn();

	// Indicates whether there is the virtual player turn.
	virtual bool isVirtualPlayerTurn();

	// Indicates whether there is the player can steal a card.
	virtual bool isPlayerSteal();

	// Indicates whether the game is underway.
	bool isGameUnderway();

	// Indicates whether the game is finished.
	virtual bool isGameFinished();
};

