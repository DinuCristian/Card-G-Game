#include "CardDeck.h"

CardDeck::CardDeck()
{
	this->cards = gcnew List<Card^>();
}

void CardDeck::clearCards()
{
	this->cards->Clear();
}

void CardDeck::addCard(Card^ card)
{
	this->cards->Add(card);
}

void CardDeck::shuffle()
{
	RandomNumberGenerator^ randomNumberGenerator = RandomNumberGenerator::getInstance();

	// Fisher–Yates shuffle.
	for (int i = 0; i < this->cards->Count - 1; i++)
	{
		int j = randomNumberGenerator->getRandomInt(i, this->cards->Count);
		
		Card^ card = this->cards[i];
		this->cards[i] = this->cards[j];
		this->cards[j] = card;
	}
}

Card^ CardDeck::removeCardAt(int cardIndex)
{
	// If the given card index is not valid, return nullptr.
	if (cardIndex < 0 || cardIndex >= this->cards->Count)
	{
		return nullptr;
	}

	// Return the card at the given card index.
	Card^ card = this->cards[cardIndex];
	this->cards[cardIndex] = nullptr;
	return card;
}

int CardDeck::getMaxCardsCount()
{
	return this->cards->Count;
}
