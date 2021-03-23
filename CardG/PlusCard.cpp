#include "PlusCard.h"

PlusCard::PlusCard(int power) : Card(CardType::Plus, power)
{
	this->name = "CardPlus" + power.ToString();
}
