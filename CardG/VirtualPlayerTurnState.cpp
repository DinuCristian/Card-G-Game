#include "VirtualPlayerTurnState.h"

void VirtualPlayerTurnState::virtualPlayerPlaysCard(Object^ object)
{
	this->gameEngine->virtualPlayerPlayCard();
}

void VirtualPlayerTurnState::virtualPlayerStealsCard(Object^ object)
{
	this->gameEngine->virtualPlayerStealCard();
}

VirtualPlayerTurnState::VirtualPlayerTurnState(GameState^ gameState) : GameState(gameState)
{
	this->gameUnderway = true;
}

String^ VirtualPlayerTurnState::getStateDescription()
{
	return this->gameEngine->getVirtualPlayerName();
}

void VirtualPlayerTurnState::nextState()
{
	// The last played card by the virtual player is a Steal card.
	if (this->gameEngine->isLastVirtualPlayerPlayedCardSteal())
	{
		// If the player has cards, advance to the virtual player steal state.
		if (this->gameEngine->playerHasCards())
		{
			this->gameEngine->setState(gcnew VirtualPlayerStealState(this));

			// Start a new thread for the virtual player to steal a card.
			Thread^ thread = gcnew Thread(gcnew ParameterizedThreadStart(this, &VirtualPlayerTurnState::virtualPlayerStealsCard));
			thread->Start();
		}
		else
		{
			// If the virtual player has cards, advance to the virtual player turn state.
			if (this->gameEngine->virtualPlayerHasCards()) {
				this->gameEngine->setState(gcnew VirtualPlayerTurnState(this));

				// Start a new thread for the virtual player to play a card.
				Thread^ thread = gcnew Thread(gcnew ParameterizedThreadStart(this, &VirtualPlayerTurnState::virtualPlayerPlaysCard));
				thread->Start();
			}
			// Else, advance to the finished game state.
			else
			{
				this->gameEngine->setState(gcnew FinishedGameState(this));
				this->gameEngine->raiseGameFinished();
			}
		}
	}
	// The last played card by the virtual player is not a Steal card. 
	else
	{
		// If all the cards are played, advance to the game finished state.
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
		else
		{
			// If the virtual player has cards, advance to the virtual player turn state.
			if (this->gameEngine->virtualPlayerHasCards())
			{
				this->gameEngine->setState(gcnew VirtualPlayerTurnState(this));

				// Start a new thread for the virtual player to play a card.
				Thread^ thread = gcnew Thread(gcnew ParameterizedThreadStart(this, &VirtualPlayerTurnState::virtualPlayerPlaysCard));
				thread->Start();
			}
		}
	}
}

bool VirtualPlayerTurnState::isVirtualPlayerTurn()
{
	return true;
}
