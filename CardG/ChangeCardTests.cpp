#include "ChangeCardTests.h"

void ChangeCardTests::TestGetType()
{
	ChangeCard^ card = gcnew ChangeCard();
	Assert(card->getType() == CardType::Change);
}

void ChangeCardTests::TestGetPower()
{
	ChangeCard^ card = gcnew ChangeCard();
	Assert(card->getPower() == 3);
}

void ChangeCardTests::TestGetName()
{
	ChangeCard^ card = gcnew ChangeCard();
	Assert(card->getName() == "CardChange");
}
