#include "PlusCardTests.h"

void PlusCardTests::TestGetType()
{
	PlusCard^ card = gcnew PlusCard(0);
	Assert(card->getType() == CardType::Plus);
}

void PlusCardTests::TestGetPower1()
{
	int power = 1;
	PlusCard^ card = gcnew PlusCard(power);
	Assert(card->getPower() == power);
}

void PlusCardTests::TestGetPower2()
{
	int power = 2;
	PlusCard^ card = gcnew PlusCard(power);
	Assert(card->getPower() == power);
}

void PlusCardTests::TestGetPower3()
{
	int power = 3;
	PlusCard^ card = gcnew PlusCard(power);
	Assert(card->getPower() == power);
}

void PlusCardTests::TestGetPower4()
{
	int power = 4;
	PlusCard^ card = gcnew PlusCard(power);
	Assert(card->getPower() == power);
}

void PlusCardTests::TestGetPower5()
{
	int power = 5;
	PlusCard^ card = gcnew PlusCard(power);
	Assert(card->getPower() == power);
}

void PlusCardTests::TestGetName1()
{
	int power = 1;
	PlusCard^ card = gcnew PlusCard(power);
	Assert(card->getName() == "CardPlus" + power.ToString());
}

void PlusCardTests::TestGetName2()
{
	int power = 2;
	PlusCard^ card = gcnew PlusCard(power);
	Assert(card->getName() == "CardPlus" + power.ToString());
}

void PlusCardTests::TestGetName3()
{
	int power = 3;
	PlusCard^ card = gcnew PlusCard(power);
	Assert(card->getName() == "CardPlus" + power.ToString());
}

void PlusCardTests::TestGetName4()
{
	int power = 4;
	PlusCard^ card = gcnew PlusCard(power);
	Assert(card->getName() == "CardPlus" + power.ToString());
}

void PlusCardTests::TestGetName5()
{
	int power = 5;
	PlusCard^ card = gcnew PlusCard(power);
	Assert(card->getName() == "CardPlus" + power.ToString());
}
