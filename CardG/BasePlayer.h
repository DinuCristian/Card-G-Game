#pragma once

#include "Card.h"

using namespace System;

ref class BasePlayer
{
protected:
	// The player name.
	String^ name;

	// The player score.
	int score;


	// The maximum number of cards in the player set of cards.
	int maxCardsCount;


	// The player set of cards.
	array<Card^>^ cards;

	// The number of cards in the player set of cards.
	int cardsCount;


	// The set of cards played by the player.
	array<Card^>^ playedCards;

	// The number of cards played by the player.
	int playedCardsCount;


	// The opponent of the player.
	BasePlayer^ opponent;

public:
	// Represents a base player.
	//   name: The player name.
	//   maxCardsCount: The maximum number of cards in the player set of cards.
	BasePlayer(String^ name, int maxCardsCount);

	// Sets the opponent of the player.
	//   opponent: The opponent of the player.
	void setOpponent(BasePlayer^ opponent);

	// Gets the name of the player.
	String^ getName();

	// Gets the score of the player.
	int getScore();

	// Clears the player score, set of cards, and set of played cards.
	void clearCards();

	// Adds the given card to the player set of cards.
	//   card: The card to add to the player set of cards.
	void addCard(Card^ card);

	// Inserts the given card on the first empty slot of the player set of cards. Returns the index at which the card was inserted and -1 if the card could not be inserted in the player set. 
	//   card: The card to insert to the player set of cards.
	int insertCard(Card^ card);

	// Gets the card with the given index from the player set of cards.
	//   cardIndex: The index of the card to get from the player set of cards.
	Card^ getCardAt(int cardIndex);
	
	// Removes the card with the given index from the player set of cards.
	//   cardIndex: The index of the card to remove from the player set of cards.
	void removeCardAt(int cardIndex);

	// Indicates whether the player selected all cards.
	bool selectedAllCards();

	// Indicates whether the player has cards in their set of cards.
	bool hasCards();
	
	// Gets the maximum number of cards in the player set of cards.
	int getMaxCardsCount();

	// Plays the card with the given index from the player set of cards.
	//   cardIndex: The index of the card to play from the player set of cards.
	void playCard(int cardIndex);

	// Indicates whether the last card played by the player is a Steal card.
	bool isLastPlayedCardSteal();
	
	// Gets the descrption of the cards in the player set of cards.
	String^ getCardsDescription();

	// Gets the description of the last card played by the player.
	String^ getLastPlayedCardDescription();
};

