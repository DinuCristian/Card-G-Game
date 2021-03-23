#include "DealPlayerState.h"

DealPlayerState::DealPlayerState(GameEngine^ gameEngine)
{
	this->gameEngine = gameEngine;
	this->gameUnderway = true;
}

DealPlayerState::DealPlayerState(GameState^ gameState) : GameState(gameState)
{
	this->gameUnderway = true;
}

void DealPlayerState::nextState()
{
	// If the player selected all cards, advance to the deal virtual player state.
	if (this->gameEngine->playerSelectedAllCards())
	{
		this->gameEngine->setState(gcnew DealVirtualPlayerState(this));
	}
}

String^ DealPlayerState::getStateDescription()
{
	return "Deal " + this->gameEngine->getPlayerName();
}
