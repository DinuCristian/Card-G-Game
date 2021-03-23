#include "CardDeckTests.h"

void CardDeckTests::TestClearCardsForEmptyCardDeck()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->clearCards();
	Assert(cardDeck->getMaxCardsCount() == 0);
}

void CardDeckTests::TestClearCardsForCardDeckWithOneCard()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->addCard(gcnew StealCard());
	cardDeck->clearCards();
	Assert(cardDeck->getMaxCardsCount() == 0);
}

void CardDeckTests::TestClearCardsForCardDeckWithThreeCards()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->addCard(gcnew StealCard());
	cardDeck->addCard(gcnew PlusCard(1));
	cardDeck->addCard(gcnew MinusCard(2));
	cardDeck->clearCards();
	Assert(cardDeck->getMaxCardsCount() == 0);
}

void CardDeckTests::TestAddOneCard()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->addCard(gcnew StealCard());
	Assert(cardDeck->getMaxCardsCount() == 1);
}

void CardDeckTests::TestAddThreeCards()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->addCard(gcnew StealCard());
	cardDeck->addCard(gcnew PlusCard(1));
	cardDeck->addCard(gcnew MinusCard(2));
	Assert(cardDeck->getMaxCardsCount() == 3);
}

void CardDeckTests::TestShuffleEmptyCardDeck()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->shuffle();
	Assert(cardDeck->getMaxCardsCount() == 0);
}

void CardDeckTests::TestShuffleCardDeckWithOneCard()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->addCard(gcnew StealCard());
	cardDeck->shuffle();
	Assert(cardDeck->getMaxCardsCount() == 1);
}

void CardDeckTests::TestShuffleCardDeckWithThreeCards()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	Card^ firstCard = gcnew StealCard();
	Card^ secondCard = gcnew PlusCard(1);
	Card^ thirdCard = gcnew MinusCard(2);
	cardDeck->addCard(firstCard);
	cardDeck->addCard(secondCard);
	cardDeck->addCard(thirdCard);

	cardDeck->shuffle();
	Card^ firstCardFromDeck = cardDeck->removeCardAt(0);
	Card^ secondCardFromDeck = cardDeck->removeCardAt(1);
	Card^ thirdCardFromDeck = cardDeck->removeCardAt(2);
	bool firstShuffleTest = firstCard != firstCardFromDeck || secondCard != secondCardFromDeck || thirdCard != thirdCardFromDeck;

	cardDeck->shuffle();
	firstCardFromDeck = cardDeck->removeCardAt(0);
	secondCardFromDeck = cardDeck->removeCardAt(1);
	thirdCardFromDeck = cardDeck->removeCardAt(2);
	bool secondShuffleTest = firstCard != firstCardFromDeck || secondCard != secondCardFromDeck || thirdCard != thirdCardFromDeck;

	cardDeck->shuffle();
	firstCardFromDeck = cardDeck->removeCardAt(0);
	secondCardFromDeck = cardDeck->removeCardAt(1);
	thirdCardFromDeck = cardDeck->removeCardAt(2);
	bool thirdShuffleTest = firstCard != firstCardFromDeck || secondCard != secondCardFromDeck || thirdCard != thirdCardFromDeck;

	// shuffle is probabilistic; test three shuffles to rule out with very high probability a false positive outcome
	bool shuffleTest = firstShuffleTest || secondShuffleTest || thirdShuffleTest;

	Assert(cardDeck->getMaxCardsCount() == 3 && shuffleTest);
}

void CardDeckTests::TestRemoveCardAtIndexZeroFromEmptyCardDeck()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	Card^ card = cardDeck->removeCardAt(0);
	Assert(card == nullptr);
}

void CardDeckTests::TestRemoveCardAtIndexTwoFromEmptyCardDeck()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	Card^ card = cardDeck->removeCardAt(2);
	Assert(card == nullptr);
}

void CardDeckTests::TestRemoveCardAtIndexZeroFromCardDeckWithOneCard()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	Card^ card = gcnew StealCard();
	cardDeck->addCard(card);
	Card^ cardFromDeck = cardDeck->removeCardAt(0);
	Assert(card == cardFromDeck);
}

void CardDeckTests::TestRemoveCardAtIndexTwoFromCardDeckWithOneCard()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->addCard(gcnew StealCard());
	Card^ card = cardDeck->removeCardAt(2);
	Assert(card == nullptr);
}

void CardDeckTests::TestRemoveCardAtIndexZeroFromCardDeckWithThreeCards()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	Card^ card = gcnew StealCard();
	cardDeck->addCard(card);
	cardDeck->addCard(gcnew PlusCard(1));
	cardDeck->addCard(gcnew MinusCard(2));
	Card^ cardFromDeck = cardDeck->removeCardAt(0);
	Assert(card == cardFromDeck);
}

void CardDeckTests::TestRemoveCardAtIndexTwoFromCardDeckWithThreeCards()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->addCard(gcnew StealCard());
	cardDeck->addCard(gcnew PlusCard(1));
	Card^ card = gcnew MinusCard(2);
	cardDeck->addCard(card);
	Card^ cardFromDeck = cardDeck->removeCardAt(2);
	Assert(card == cardFromDeck);
}

void CardDeckTests::TestRemoveCardAtIndexZeroFromCardDeckWithThreeCardsAndFirstCardRemoved()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->addCard(gcnew StealCard());
	cardDeck->addCard(gcnew PlusCard(1));
	cardDeck->addCard(gcnew MinusCard(2));
	cardDeck->removeCardAt(0);
	Card^ card = cardDeck->removeCardAt(0);
	Assert(card == nullptr);
}

void CardDeckTests::TestRemoveCardAtIndexTwoFromCardDeckWithThreeCardsAndThirdCardRemoved()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->addCard(gcnew StealCard());
	cardDeck->addCard(gcnew PlusCard(1));
	cardDeck->addCard(gcnew MinusCard(2));
	cardDeck->removeCardAt(2);
	Card^ card = cardDeck->removeCardAt(2);
	Assert(card == nullptr);
}

void CardDeckTests::TestGetMaxCardsCountForEmptyCardDeck()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	Assert(cardDeck->getMaxCardsCount() == 0);
}

void CardDeckTests::TestGetMaxCardsCountForCardDeckWithOneCard()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->addCard(gcnew StealCard());
	Assert(cardDeck->getMaxCardsCount() == 1);
}

void CardDeckTests::TestGetMaxCardsCountForCardDeckWithThreeCards()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->addCard(gcnew StealCard());
	cardDeck->addCard(gcnew PlusCard(1));
	cardDeck->addCard(gcnew MinusCard(2));
	Assert(cardDeck->getMaxCardsCount() == 3);
}

void CardDeckTests::TestGetMaxCardsCountForCardDeckWithThreeCardsAndFirstCardRemoved()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->addCard(gcnew StealCard());
	cardDeck->addCard(gcnew PlusCard(1));
	cardDeck->addCard(gcnew MinusCard(2));
	cardDeck->removeCardAt(0);
	Assert(cardDeck->getMaxCardsCount() == 3); 
}

void CardDeckTests::TestGetMaxCardsCountForCardDeckWithThreeCardsAndThirdCardRemoved()
{
	CardDeck^ cardDeck = gcnew CardDeck();
	cardDeck->addCard(gcnew StealCard());
	cardDeck->addCard(gcnew PlusCard(1));
	cardDeck->addCard(gcnew MinusCard(2));
	cardDeck->removeCardAt(2);
	Assert(cardDeck->getMaxCardsCount() == 3);
}
