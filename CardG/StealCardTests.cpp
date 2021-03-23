#include "StealCardTests.h"

void StealCardTests::TestGetType()
{
	StealCard^ card = gcnew StealCard();
	Assert(card->getType() == CardType::Steal);
}

void StealCardTests::TestGetPower()
{
	StealCard^ card = gcnew StealCard();
	Assert(card->getPower() == 1);
}

void StealCardTests::TestGetName()
{
	StealCard^ card = gcnew StealCard();
	Assert(card->getName() == "CardSteal");
}
