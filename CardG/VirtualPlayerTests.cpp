#include "VirtualPlayerTests.h"

void VirtualPlayerTests::TestSelectCardIndexFixedValue()
{
	VirtualPlayer^ virtualPlayer = gcnew VirtualPlayer("Virtual Player", 5);
	Assert(virtualPlayer->selectCardIndex(3, 3) == 3);
}

void VirtualPlayerTests::TestSelectCardIndexRange()
{
	VirtualPlayer^ virtualPlayer = gcnew VirtualPlayer("Virtual Player", 5);
	Assert(0 <= virtualPlayer->selectCardIndex(0, 5) < 10);
}

void VirtualPlayerTests::TestShuffleCardsNoCards()
{
	VirtualPlayer^ virtualPlayer = gcnew VirtualPlayer("Virtual Player", 5);
	virtualPlayer->shuffleCards();
	Assert(virtualPlayer->getCardAt(0) == nullptr && virtualPlayer->getCardAt(1) == nullptr && virtualPlayer->getCardAt(2) == nullptr && virtualPlayer->getCardAt(3) == nullptr && virtualPlayer->getCardAt(4) == nullptr);
}

void VirtualPlayerTests::TestShuffleCardsOneCard()
{
	VirtualPlayer^ virtualPlayer = gcnew VirtualPlayer("Virtual Player", 5);
	Card^ card = gcnew PlusCard(1);
	virtualPlayer->addCard(card);
	
	virtualPlayer->shuffleCards();
	bool firstShuffleTest = !(virtualPlayer->getCardAt(0) == card && virtualPlayer->getCardAt(1) == nullptr && virtualPlayer->getCardAt(2) == nullptr && virtualPlayer->getCardAt(3) == nullptr && virtualPlayer->getCardAt(4) == nullptr);
	
	virtualPlayer->shuffleCards();
	bool secondShuffleTest = !(virtualPlayer->getCardAt(0) == card && virtualPlayer->getCardAt(1) == nullptr && virtualPlayer->getCardAt(2) == nullptr && virtualPlayer->getCardAt(3) == nullptr && virtualPlayer->getCardAt(4) == nullptr);

	virtualPlayer->shuffleCards();
	bool thirdShuffleTest = !(virtualPlayer->getCardAt(0) == card && virtualPlayer->getCardAt(1) == nullptr && virtualPlayer->getCardAt(2) == nullptr && virtualPlayer->getCardAt(3) == nullptr && virtualPlayer->getCardAt(4) == nullptr);

	// shuffle is probabilistic; test three shuffles to rule out with very high probability a false positive outcome
	bool shuffleTest = firstShuffleTest || secondShuffleTest || thirdShuffleTest;

	Assert(shuffleTest);
}

void VirtualPlayerTests::TestShuffleCardsThreeCards()
{
	VirtualPlayer^ virtualPlayer = gcnew VirtualPlayer("Virtual Player", 5);
	Card^ firstCard = gcnew PlusCard(1);
	Card^ secondCard = gcnew MinusCard(2);
	Card^ thirdCard = gcnew StealCard();
	virtualPlayer->addCard(firstCard);
	virtualPlayer->addCard(secondCard);
	virtualPlayer->addCard(thirdCard);

	virtualPlayer->shuffleCards();
	bool firstShuffleTest = !(virtualPlayer->getCardAt(0) == firstCard && virtualPlayer->getCardAt(1) == secondCard && virtualPlayer->getCardAt(2) == thirdCard && virtualPlayer->getCardAt(3) == nullptr && virtualPlayer->getCardAt(4) == nullptr);

	virtualPlayer->shuffleCards();
	bool secondShuffleTest = !(virtualPlayer->getCardAt(0) == firstCard && virtualPlayer->getCardAt(1) == secondCard && virtualPlayer->getCardAt(2) == thirdCard && virtualPlayer->getCardAt(3) == nullptr && virtualPlayer->getCardAt(4) == nullptr);

	virtualPlayer->shuffleCards();
	bool thirdShuffleTest = !(virtualPlayer->getCardAt(0) == firstCard && virtualPlayer->getCardAt(1) == secondCard && virtualPlayer->getCardAt(2) == thirdCard && virtualPlayer->getCardAt(3) == nullptr && virtualPlayer->getCardAt(4) == nullptr);

	// shuffle is probabilistic; test three shuffles to rule out with very high probability a false positive outcome
	bool shuffleTest = firstShuffleTest || secondShuffleTest || thirdShuffleTest;

	Assert(shuffleTest);
}

void VirtualPlayerTests::TestShuffleCardsFiveCards()
{
	VirtualPlayer^ virtualPlayer = gcnew VirtualPlayer("Virtual Player", 5);
	Card^ firstCard = gcnew PlusCard(1);
	Card^ secondCard = gcnew MinusCard(2);
	Card^ thirdCard = gcnew StealCard();
	Card^ fourthCard = gcnew PlusCard(4);
	Card^ fifthCard = gcnew MinusCard(5);
	virtualPlayer->addCard(firstCard);
	virtualPlayer->addCard(secondCard);
	virtualPlayer->addCard(thirdCard);
	virtualPlayer->addCard(fourthCard);
	virtualPlayer->addCard(fifthCard);

	virtualPlayer->shuffleCards();
	bool firstShuffleTest = !(virtualPlayer->getCardAt(0) == firstCard && virtualPlayer->getCardAt(1) == secondCard && virtualPlayer->getCardAt(2) == thirdCard && virtualPlayer->getCardAt(3) == fourthCard && virtualPlayer->getCardAt(4) == fifthCard);

	virtualPlayer->shuffleCards();
	bool secondShuffleTest = !(virtualPlayer->getCardAt(0) == firstCard && virtualPlayer->getCardAt(1) == secondCard && virtualPlayer->getCardAt(2) == thirdCard && virtualPlayer->getCardAt(3) == fourthCard && virtualPlayer->getCardAt(4) == fifthCard);

	virtualPlayer->shuffleCards();
	bool thirdShuffleTest = !(virtualPlayer->getCardAt(0) == firstCard && virtualPlayer->getCardAt(1) == secondCard && virtualPlayer->getCardAt(2) == thirdCard && virtualPlayer->getCardAt(3) == fourthCard && virtualPlayer->getCardAt(4) == fifthCard);

	// shuffle is probabilistic; test three shuffles to rule out with very high probability a false positive outcome
	bool shuffleTest = firstShuffleTest || secondShuffleTest || thirdShuffleTest;

	Assert(shuffleTest);
}
