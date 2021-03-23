#include "GameState.h"

GameState::GameState()
{
	this->gameUnderway = false;
}

GameState::GameState(GameState^ gameState)
{
	this->gameEngine = gameState->gameEngine;
}

String^ GameState::getStateDescription()
{
	return this->ToString();
}

bool GameState::isPlayerTurn()
{
	return false;
}

bool GameState::isVirtualPlayerTurn()
{
	return false;
}

bool GameState::isPlayerSteal()
{
	return false;
}

bool GameState::isGameUnderway()
{
	return this->gameUnderway;
}

bool GameState::isGameFinished()
{
	return false;
}
