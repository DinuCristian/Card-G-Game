#include "VirtualPlayer.h"

VirtualPlayer::VirtualPlayer(String^ name, int maxCardsCount) : BasePlayer(name, maxCardsCount)
{
}

int VirtualPlayer::selectCardIndex(int minCardIndex, int maxCardIndex)
{
	RandomNumberGenerator^ randomNumberGenerator = RandomNumberGenerator::getInstance();
	return randomNumberGenerator->getRandomInt(minCardIndex, maxCardIndex);
}

array<bool>^ VirtualPlayer::shuffleCards()
{
	RandomNumberGenerator^ randomNumberGenerator = RandomNumberGenerator::getInstance();

	// Fisher–Yates shuffle.
	for (int i = 0; i < this->maxCardsCount - 1; i++)
	{
		int j = randomNumberGenerator->getRandomInt(i, this->maxCardsCount);

		Card^ card = this->cards[i];
		this->cards[i] = this->cards[j];
		this->cards[j] = card;
	}

	array<bool>^ result = gcnew array<bool>(this->maxCardsCount);

	// Loop through all cards in the player set.
	for (int i = 0; i < this->maxCardsCount; i++)
	{
		// Indicate wheter the card at index i is played.
		result[i] = this->cards[i] != nullptr;
	}

	return result;
}
