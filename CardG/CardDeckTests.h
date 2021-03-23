#pragma once

#include "Test.h"
#include "CardDeck.h"
#include "MinusCard.h"
#include "PlusCard.h"
#include "StealCard.h"

ref class CardDeckTests :
	public Test
{
public:
	static void TestClearCardsForEmptyCardDeck();
	static void TestClearCardsForCardDeckWithOneCard();
	static void TestClearCardsForCardDeckWithThreeCards();

	static void TestAddOneCard();
	static void TestAddThreeCards();

	static void TestShuffleEmptyCardDeck();
	static void TestShuffleCardDeckWithOneCard();
	static void TestShuffleCardDeckWithThreeCards();

	static void TestRemoveCardAtIndexZeroFromEmptyCardDeck();
	static void TestRemoveCardAtIndexTwoFromEmptyCardDeck();
	static void TestRemoveCardAtIndexZeroFromCardDeckWithOneCard();
	static void TestRemoveCardAtIndexTwoFromCardDeckWithOneCard();
	static void TestRemoveCardAtIndexZeroFromCardDeckWithThreeCards();
	static void TestRemoveCardAtIndexTwoFromCardDeckWithThreeCards();
	static void TestRemoveCardAtIndexZeroFromCardDeckWithThreeCardsAndFirstCardRemoved();
	static void TestRemoveCardAtIndexTwoFromCardDeckWithThreeCardsAndThirdCardRemoved();

	static void TestGetMaxCardsCountForEmptyCardDeck();
	static void TestGetMaxCardsCountForCardDeckWithOneCard();
	static void TestGetMaxCardsCountForCardDeckWithThreeCards();
	static void TestGetMaxCardsCountForCardDeckWithThreeCardsAndFirstCardRemoved();
	static void TestGetMaxCardsCountForCardDeckWithThreeCardsAndThirdCardRemoved();
};

