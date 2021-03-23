#include "PlayerTurnState.h"

void PlayerTurnState::virtualPlayerPlaysCard(Object^ object)
{
	this->gameEngine->virtualPlayerPlayCard();
}

PlayerTurnState::PlayerTurnState(GameState^ gameState) : GameState(gameState)
{
	this->gameUnderway = true;
}

void PlayerTurnState::nextState()
{
	// The last played card by the player is a Steal card.
	if (this->gameEngine->isLastPlayerPlayedCardSteal())
	{
		// If the virtual player has cards, advance to the player steal state.
		if (this->gameEngine->virtualPlayerHasCards())
		{
			this->gameEngine->setState(gcnew PlayerStealState(this));
		}
		else
		{
			// If the player has cards, advance to the player turn state.
			if (this->gameEngine->playerHasCards()) {
				this->gameEngine->setState(gcnew PlayerTurnState(this));
			}
			// Else, advance to the finished game state.
			else
			{
				this->gameEngine->setState(gcnew FinishedGameState(this));
				this->gameEngine->raiseGameFinished();
			}
		}
	}
	// The last played card by the player is not a Steal card. 
	else
	{
		// If all the cards are played, advance to the game finished state.
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
			Thread^ thread = gcnew Thread(gcnew ParameterizedThreadStart(this, &PlayerTurnState::virtualPlayerPlaysCard));
			thread->Start();
		}
		else
		{
			// If the player has cards, advance to the player turn state.
			if (this->gameEngine->playerHasCards())
			{
				this->gameEngine->setState(gcnew PlayerTurnState(this));
			}
		}
	}
}

String^ PlayerTurnState::getStateDescription()
{
	return this->gameEngine->getPlayerName();
}

bool PlayerTurnState::isPlayerTurn()
{
	return true;
}
