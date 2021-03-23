#include "DealVirtualPlayerState.h"

void DealVirtualPlayerState::virtualPlayerPlaysCard(Object^ object)
{
	this->gameEngine->virtualPlayerPlayCard();
}

DealVirtualPlayerState::DealVirtualPlayerState(GameState^ gameState) : GameState(gameState)
{

}

void DealVirtualPlayerState::nextState()
{
	// If the virtual player selected all cards, advance to the virtual player turn state.
	if (this->gameEngine->virtualPlayerSelectedAllCards())
	{
		this->gameEngine->setState(gcnew VirtualPlayerTurnState(this));

		// Start a new thread for the virtual player to play a card.
		Thread^ thread = gcnew Thread(gcnew ParameterizedThreadStart(this, &DealVirtualPlayerState::virtualPlayerPlaysCard));
		thread->Start();
	}
}

String^ DealVirtualPlayerState::getStateDescription()
{
	return "Deal " + this->gameEngine->getVirtualPlayerName();
}
