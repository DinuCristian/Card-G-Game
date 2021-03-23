#include "FinishedGameState.h"

FinishedGameState::FinishedGameState(GameState^ gameState) : GameState(gameState)
{
	this->gameUnderway = false;
}

void FinishedGameState::nextState()
{

}

String^ FinishedGameState::getStateDescription()
{
	return "Game finished";
}

bool FinishedGameState::isGameFinished()
{
	return true;
}
