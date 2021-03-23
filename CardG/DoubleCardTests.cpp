#include "DoubleCardTests.h"

void DoubleCardTests::TestGetType()
{
	DoubleCard^ card = gcnew DoubleCard();
	Assert(card->getType() == CardType::Double);
}

void DoubleCardTests::TestGetPower()
{
	DoubleCard^ card = gcnew DoubleCard();
	Assert(card->getPower() == 2);
}

void DoubleCardTests::TestGetName()
{
	DoubleCard^ card = gcnew DoubleCard();
	Assert(card->getName() == "CardDouble");
}
