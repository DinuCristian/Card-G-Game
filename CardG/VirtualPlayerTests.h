#pragma once

#include "Test.h"
#include "VirtualPlayer.h"
#include "MinusCard.h"
#include "PlusCard.h"
#include "StealCard.h"

ref class VirtualPlayerTests :
	public Test
{
public:
	static void TestSelectCardIndexFixedValue();
	static void TestSelectCardIndexRange();

	static void TestShuffleCardsNoCards();
	static void TestShuffleCardsOneCard();
	static void TestShuffleCardsThreeCards();
	static void TestShuffleCardsFiveCards();
};

