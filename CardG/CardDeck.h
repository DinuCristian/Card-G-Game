#pragma once

#include "Card.h"
#include "RandomNumberGenerator.h"

using namespace System::Collections::Generic;

ref class CardDeck
{
private:
	// The list of cards in the deck.
	List<Card^>^ cards;

public:
	// Represents a card deck.
	CardDeck();

	// Clears the cards in the card deck.
	void clearCards();
	
	// Adds the given card to the card deck.
	//   card: The card to add to the card deck.
	void addCard(Card^ card);
	
	// Shuffles the cards in the card deck.
	void shuffle();
	
	// Removed the card with the given index from the card deck. Returns the removed card or null if a card could not be removed.
	//   cardIndex: The index of the card to get from the card deck.
	Card^ removeCardAt(int cardIndex);
	
	// Gets the maximum number of cards in the card deck.
	int getMaxCardsCount();
};

