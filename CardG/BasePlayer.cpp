#include "BasePlayer.h"

BasePlayer::BasePlayer(String^ name, int maxCardsCount)
{
	this->name = name;
	this->score = 0;

	this->maxCardsCount = maxCardsCount;

	this->cards = gcnew array<Card^>(this->maxCardsCount);
	this->cardsCount = 0;

	this->playedCards = gcnew array<Card^>(2 * this->maxCardsCount);
	this->playedCardsCount = 0;
}

void BasePlayer::setOpponent(BasePlayer^ opponent)
{
	this->opponent = opponent;
}

String^ BasePlayer::getName()
{
	return this->name;
}

int BasePlayer::getScore()
{
	return this->score;
}

void BasePlayer::clearCards()
{
	// Set score to 0.
	this->score = 0;
	// Set the number of cards in the player set to 0.
	this->cardsCount = 0;
	// Set the number of cards in the set of cards played by the player to 0.
	this->playedCardsCount = 0;

	// Set all the cards in the player set of cards to nullptr.
	for (int i = 0; i < this->maxCardsCount; i++)
	{
		this->cards[i] = nullptr;
	}

	// Set all the cards in the player set of played cards to nullptr.
	for (int i = 0; i < 2 * this->maxCardsCount; i++)
	{
		this->playedCards[i] = nullptr;
	}
}

void BasePlayer::addCard(Card^ card)
{
	// Return if the player set of cards is full.
	if (this->cardsCount >= this->maxCardsCount)
	{
		return;
	}

	// Add the card to the player set of cards.
	this->cards[this->cardsCount] = card;
	this->cardsCount += 1;
}

int BasePlayer::insertCard(Card^ card)
{
	// Loop through all cards in the player set of cards.
	for (int i = 0; i < this->maxCardsCount; i++)
	{
		// If there is no card at index i, insert the card at this index.
		if (this->cards[i] == nullptr)
		{
			this->cards[i] = card;
			this->cardsCount += 1;
			return i;
		}
	}
	// Return -1 if the card could not be inserted in the player set.
	return -1;
}

Card^ BasePlayer::getCardAt(int cardIndex)
{
	// Return nullptr if the given card index is outside the bounds of the player set of cards.
	if (cardIndex < 0 || cardIndex >= this->maxCardsCount)
	{
		return nullptr;
	}

	// Return the card at the given card index.
	return this->cards[cardIndex];
}

void BasePlayer::removeCardAt(int cardIndex)
{
	// Return if the given card index is outside the bounds of the player set of cards.
	if (cardIndex < 0 || cardIndex >= this->maxCardsCount)
	{
		return;
	}

	// Remove the card at the given card index
	this->cards[cardIndex] = nullptr;
	this->cardsCount -= 1;
}

bool BasePlayer::selectedAllCards()
{
	return this->cardsCount == this->maxCardsCount;
}

bool BasePlayer::hasCards()
{
	return this->cardsCount > 0;
}

int BasePlayer::getMaxCardsCount()
{
	return this->maxCardsCount;
}

void BasePlayer::playCard(int cardIndex)
{
	// Return if the given card index is outside the bounds of the player set of cards.
	if (cardIndex < 0 || cardIndex >= this->maxCardsCount)
	{
		return;
	}

	Card^ card = this->cards[cardIndex];
	// Return if the card at the given index is played.
	if (card == nullptr)
	{
		return;
	}

	// Handle the card played by the player by its type. Update the player and opponent score accordingly.
	switch (card->getType())
	{
	case CardType::Plus:
		this->score += card->getPower();
		break;
	case CardType::Minus:
		this->opponent->score -= card->getPower();
		break;
	case CardType::Steal:
		// If the opponent has no cards in their set of cards, this card is equivalent to a Plus card with a power value of 1.
		if (!this->opponent->hasCards())
		{
			this->score += card->getPower();
		}
		break;
	case CardType::Double:
		this->score *= card->getPower();
		break;
	case CardType::Change:
		// If the opponent played no card, this card has the same effect as when the last card played by the opponent is a Plus card with a power value of 3.
		if (this->opponent->playedCardsCount == 0)
		{
			this->score += card->getPower();
			this->opponent->score -= card->getPower();
		}
		// The opponent played at least one card.
		else
		{
			// Get the last card played by the opponent.
			Card^ opponentLastPlayedCard = this->opponent->playedCards[this->opponent->playedCardsCount - 1];
			
			// Handle the last card played by the opponent by its type. Update the player and opponent score accordingly.
			switch (opponentLastPlayedCard->getType())
			{
			case CardType::Plus:
				this->score += opponentLastPlayedCard->getPower();
				this->opponent->score -= opponentLastPlayedCard->getPower();
				break;
			case CardType::Minus:
				this->score += opponentLastPlayedCard->getPower();
				this->opponent->score -= opponentLastPlayedCard->getPower();
				break;
			case CardType::Steal:
				this->score += card->getPower();
				this->opponent->score -= card->getPower();
			case CardType::Double:
				this->score *= opponentLastPlayedCard->getPower();
				this->opponent->score /= opponentLastPlayedCard->getPower();
				break;
			case CardType::Change:
				this->score += card->getPower();
				this->opponent->score -= card->getPower();
				break;
			default:
				break;
			}
		}
		break;
	default:
		break;
	}

	// Remove the card form the player set of cards.
	this->cards[cardIndex] = nullptr;
	this->cardsCount -= 1;

	// Add the card to the set of cards played by the player.
	this->playedCards[this->playedCardsCount] = card;
	this->playedCardsCount += 1;
}

bool BasePlayer::isLastPlayedCardSteal()
{
	// Return false if the player played no card.
	if (this->playedCardsCount <= 0)
	{
		return false;
	}

	// Return whether the last played card type is Steal.
	return this->playedCards[this->playedCardsCount - 1]->getType() == CardType::Steal;
}

String^ BasePlayer::getCardsDescription()
{
	String^ description = "";
	// Loop through all cards in the player set.
	for (int i = 0; i < this->maxCardsCount; i++)
	{
		// If there is a card in the player set at index i, add the card name to the description.
		if (cards[i] != nullptr)
		{
			description += this->cards[i]->getName() + " ";
		}
	}
	return description;
}

String^ BasePlayer::getLastPlayedCardDescription()
{
	// If the player played at least on card, return its name.
	if (this->playedCardsCount > 0)
	{
		return this->playedCards[this->playedCardsCount - 1]->getName();
	}
	// If the player played no card, return an empty string.
	return "";
}
