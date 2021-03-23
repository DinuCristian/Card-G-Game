#include "VirtualPlayerStealState.h"

void VirtualPlayerStealState::virtualPlayerPlaysCard(Object^ object)
{
	this->gameEngine->virtualPlayerPlayCard();
}


VirtualPlayerStealState::VirtualPlayerStealState(GameState^ gameState) : GameState(gameState)
{

}

void VirtualPlayerStealState::nextState()
{
	// If all the cards are played, advance to the finished game state.
	if (this->gameEngine->areAllCardsPlayed())
	{
		this->gameEngine->setState(gcnew FinishedGameState(this));
		this->gameEngine->raiseGameFinished();
	}

	// If the player has cards, advance to the player turn state.
	if (this->gameEngine->playerHasCards())
	{
		this->gameEngine->setState(gcnew PlayerTurnState(this));
	}
	// Else, advance to the virtual player turn state.
	else
	{
		this->gameEngine->setState(gcnew VirtualPlayerTurnState(this));

		// Start a new thread for the virtual player to play a card.
		Thread^ thread = gcnew Thread(gcnew ParameterizedThreadStart(this, &VirtualPlayerStealState::virtualPlayerPlaysCard));
		thread->Start();
	}
}

String^ VirtualPlayerStealState::getStateDescription()
{
	return this->gameEngine->getVirtualPlayerName() + " steal card";
}
