#pragma once

#include "BasePlayer.h"

ref class Player : 
	public BasePlayer
{
private:

public:
	// Represents a player.
	//   name: The player name.
	//   maxCardsCount: The maximum number of cards in the player set of cards.
	Player(String^ name, int maxCardsCount);
};

