#include "NoGameState.h"

NoGameState::NoGameState(GameEngine^ gameEngine)
{
	this->gameEngine = gameEngine;
}

void NoGameState::nextState()
{
	// Advance to the deal player state.
	this->gameEngine->setState(gcnew DealPlayerState(this));
}

String^ NoGameState::getStateDescription()
{
	return "No game";
}
