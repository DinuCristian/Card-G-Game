#include "MinusCardTests.h"

void MinusCardTests::TestGetType()
{
	MinusCard^ card = gcnew MinusCard(0);
	Assert(card->getType() == CardType::Minus);
}

void MinusCardTests::TestGetPower1()
{
	int power = 1;
	MinusCard^ card = gcnew MinusCard(power);
	Assert(card->getPower() == power);
}

void MinusCardTests::TestGetPower2()
{
	int power = 2;
	MinusCard^ card = gcnew MinusCard(power);
	Assert(card->getPower() == power);
}

void MinusCardTests::TestGetPower3()
{
	int power = 3;
	MinusCard^ card = gcnew MinusCard(power);
	Assert(card->getPower() == power);
}

void MinusCardTests::TestGetPower4()
{
	int power = 4;
	MinusCard^ card = gcnew MinusCard(power);
	Assert(card->getPower() == power);
}

void MinusCardTests::TestGetPower5()
{
	int power = 5;
	MinusCard^ card = gcnew MinusCard(power);
	Assert(card->getPower() == power);
}

void MinusCardTests::TestGetName1()
{
	int power = 1;
	MinusCard^ card = gcnew MinusCard(power);
	Assert(card->getName() == "CardMinus" + power.ToString());
}

void MinusCardTests::TestGetName2()
{
	int power = 2;
	MinusCard^ card = gcnew MinusCard(power);
	Assert(card->getName() == "CardMinus" + power.ToString());
}

void MinusCardTests::TestGetName3()
{
	int power = 3;
	MinusCard^ card = gcnew MinusCard(power);
	Assert(card->getName() == "CardMinus" + power.ToString());
}

void MinusCardTests::TestGetName4()
{
	int power = 4;
	MinusCard^ card = gcnew MinusCard(power);
	Assert(card->getName() == "CardMinus" + power.ToString());
}

void MinusCardTests::TestGetName5()
{
	int power = 5;
	MinusCard^ card = gcnew MinusCard(power);
	Assert(card->getName() == "CardMinus" + power.ToString());
}
