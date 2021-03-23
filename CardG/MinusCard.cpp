#include "MinusCard.h"

MinusCard::MinusCard(int power) : Card(CardType::Minus, power)
{
	this->name = "CardMinus" + power.ToString();
}
