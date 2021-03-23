#pragma once

#include "BasePlayer.h"
#include "RandomNumberGenerator.h"

ref class VirtualPlayer : 
	public BasePlayer
{
public:
	// Represents a virtual player.
    //   name: The player name.
    //   maxCardsCount: The maximum number of cards in the player set of cards.
	VirtualPlayer(String^ name, int maxCardsCount);

	// Gets a card index that is within the given range.
    //   minCardIndex: The inclusive lower bound of the given range.
    //   maxCardIndex: The exclusive upper bound of the given range.
	int selectCardIndex(int minCardIndex, int maxCardIndex);

	// Shuffles the cards in the player set of cards. Return an array indicating whether there is a card in the player set at the corresponding index.
	array<bool>^ shuffleCards();
};

