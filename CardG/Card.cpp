#include "Card.h"

Card::Card(CardType type, int power)
{
	this->type = type;
	this->power = power;
	this->name = "";
}

CardType Card::getType()
{
	return this->type;
}

int Card::getPower()
{
	return this->power;
}

String^ Card::getName()
{
	return this->name;
}
