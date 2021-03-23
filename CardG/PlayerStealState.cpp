#include "PlayerStealState.h"

void PlayerStealState::virtualPlayerPlaysCard(Object^ object)
{
	this->gameEngine->virtualPlayerPlayCard();
}

PlayerStealState::PlayerStealState(GameState^ gameState) : GameState(gameState)
{
	this->gameUnderway = true;
}

void PlayerStealState::nextState()
{
	// If both players played all cards, advance to the finished game state.
	if (this->gameEngine->areAllCardsPlayed())
	{
		this->gameEngine->setState(gcnew FinishedGameState(this));
		this->gameEngine->raiseGameFinished();
	}

	// If the virtual player has cards, advance to the virtual player turn state.
	if (this->gameEngine->virtualPlayerHasCards())
	{
		this->gameEngine->setState(gcnew VirtualPlayerTurnState(this));
		
		// Start a new thread for the virtual player to play a card.
		Thread^ thread = gcnew Thread(gcnew ParameterizedThreadStart(this, &PlayerStealState::virtualPlayerPlaysCard));
		thread->Start();
	}
	// Else, advance to the player turn state.
	else
	{
		this->gameEngine->setState(gcnew PlayerTurnState(this));
	}
}

String^ PlayerStealState::getStateDescription()
{
	return this->gameEngine->getPlayerName() + " steal card";
}

bool PlayerStealState::isPlayerSteal()
{
	return true;
}
