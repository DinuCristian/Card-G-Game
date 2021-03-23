#include "BasePlayerTests.h"

void BasePlayerTests::TestGetName()
{
	String^ playerName = "Player";
	BasePlayer^ player = gcnew BasePlayer(playerName, 5);
	Assert(player->getName() == playerName);
}

void BasePlayerTests::TestGetScoreNoCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	opponent->addCard(gcnew MinusCard(5));
	opponent->addCard(gcnew PlusCard(1));
	opponent->addCard(gcnew PlusCard(4));
	opponent->addCard(gcnew PlusCard(2));
	opponent->addCard(gcnew MinusCard(1));
	Assert(player->getScore() == 0 && opponent->getScore() == 0);
}

void BasePlayerTests::TestGetScoreOneCardPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	opponent->addCard(gcnew MinusCard(5));
	opponent->addCard(gcnew PlusCard(1));
	opponent->addCard(gcnew PlusCard(4));
	opponent->addCard(gcnew PlusCard(2));
	opponent->addCard(gcnew MinusCard(1));
	player->playCard(0);
	Assert(player->getScore() == 0 && opponent->getScore() == -1);
}

void BasePlayerTests::TestGetScoreTwoCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	opponent->addCard(gcnew MinusCard(5));
	opponent->addCard(gcnew PlusCard(1));
	opponent->addCard(gcnew PlusCard(4));
	opponent->addCard(gcnew PlusCard(2));
	opponent->addCard(gcnew MinusCard(1));
	player->playCard(0);
	opponent->playCard(0);
	Assert(player->getScore() == -5 && opponent->getScore() == -1);
}

void BasePlayerTests::TestGetScoreThreeCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	opponent->addCard(gcnew MinusCard(5));
	opponent->addCard(gcnew PlusCard(1));
	opponent->addCard(gcnew PlusCard(4));
	opponent->addCard(gcnew PlusCard(2));
	opponent->addCard(gcnew MinusCard(1));
	player->playCard(0);
	opponent->playCard(0);
	player->playCard(1);
	Assert(player->getScore() == -3 && opponent->getScore() == -1);
}

void BasePlayerTests::TestGetScoreFourCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	opponent->addCard(gcnew MinusCard(5));
	opponent->addCard(gcnew PlusCard(1));
	opponent->addCard(gcnew PlusCard(4));
	opponent->addCard(gcnew PlusCard(2));
	opponent->addCard(gcnew MinusCard(1));
	player->playCard(0);
	opponent->playCard(0);
	player->playCard(1);
	opponent->playCard(1);
	Assert(player->getScore() == -3 && opponent->getScore() == 0);
}

void BasePlayerTests::TestGetScoreFiveCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	opponent->addCard(gcnew MinusCard(5));
	opponent->addCard(gcnew PlusCard(1));
	opponent->addCard(gcnew PlusCard(4));
	opponent->addCard(gcnew PlusCard(2));
	opponent->addCard(gcnew MinusCard(1));
	player->playCard(0);
	opponent->playCard(0);
	player->playCard(1);
	opponent->playCard(1);
	player->playCard(2);
	Assert(player->getScore() == -3 && opponent->getScore() == -2);
}

void BasePlayerTests::TestGetScoreSixCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	opponent->addCard(gcnew MinusCard(5));
	opponent->addCard(gcnew PlusCard(1));
	opponent->addCard(gcnew PlusCard(4));
	opponent->addCard(gcnew PlusCard(2));
	opponent->addCard(gcnew MinusCard(1));
	player->playCard(0);
	opponent->playCard(0);
	player->playCard(1);
	opponent->playCard(1);
	player->playCard(2);
	opponent->playCard(2);
	Assert(player->getScore() == -3 && opponent->getScore() == 2);
}

void BasePlayerTests::TestGetScoreSevenCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	opponent->addCard(gcnew MinusCard(5));
	opponent->addCard(gcnew PlusCard(1));
	opponent->addCard(gcnew PlusCard(4));
	opponent->addCard(gcnew PlusCard(2));
	opponent->addCard(gcnew MinusCard(1));
	player->playCard(0);
	opponent->playCard(0);
	player->playCard(1);
	opponent->playCard(1);
	player->playCard(2);
	opponent->playCard(2);
	player->playCard(3);
	Assert(player->getScore() == 0 && opponent->getScore() == 2);
}

void BasePlayerTests::TestGetScoreEightCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	opponent->addCard(gcnew MinusCard(5));
	opponent->addCard(gcnew PlusCard(1));
	opponent->addCard(gcnew PlusCard(4));
	opponent->addCard(gcnew PlusCard(2));
	opponent->addCard(gcnew MinusCard(1));
	player->playCard(0);
	opponent->playCard(0);
	player->playCard(1);
	opponent->playCard(1);
	player->playCard(2);
	opponent->playCard(2);
	player->playCard(3);
	opponent->playCard(3);
	Assert(player->getScore() == 0 && opponent->getScore() == 4);
}

void BasePlayerTests::TestGetScoreNineCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	opponent->addCard(gcnew MinusCard(5));
	opponent->addCard(gcnew PlusCard(1));
	opponent->addCard(gcnew PlusCard(4));
	opponent->addCard(gcnew PlusCard(2));
	opponent->addCard(gcnew MinusCard(1));
	player->playCard(0);
	opponent->playCard(0);
	player->playCard(1);
	opponent->playCard(1);
	player->playCard(2);
	opponent->playCard(2);
	player->playCard(3);
	opponent->playCard(3);
	player->playCard(4);
	Assert(player->getScore() == 0 && opponent->getScore() == 0);
}

void BasePlayerTests::TestGetScoreTenCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	opponent->addCard(gcnew MinusCard(5));
	opponent->addCard(gcnew PlusCard(1));
	opponent->addCard(gcnew PlusCard(4));
	opponent->addCard(gcnew PlusCard(2));
	opponent->addCard(gcnew MinusCard(1));
	player->playCard(0);
	opponent->playCard(0);
	player->playCard(1);
	opponent->playCard(1);
	player->playCard(2);
	opponent->playCard(2);
	player->playCard(3);
	opponent->playCard(3);
	player->playCard(4);
	opponent->playCard(4);
	Assert(player->getScore() == -1 && opponent->getScore() == 0);
}

void BasePlayerTests::TestClearCardsNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->clearCards();
	Assert(player->getScore() == 0 && player->hasCards() == false && player->getCardAt(0) == nullptr && player->getCardAt(1) == nullptr && player->getCardAt(2) == nullptr && player->getCardAt(3) == nullptr && player->getCardAt(4) == nullptr);
}

void BasePlayerTests::TestClearCardsOneCardPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	player->playCard(0);
	player->clearCards();
	Assert(player->getScore() == 0 && player->hasCards() == false && player->getCardAt(0) == nullptr && player->getCardAt(1) == nullptr && player->getCardAt(2) == nullptr && player->getCardAt(3) == nullptr && player->getCardAt(4) == nullptr);
}

void BasePlayerTests::TestClearCardsTwoCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	player->playCard(0);
	player->playCard(1);
	player->clearCards();
	Assert(player->getScore() == 0 && player->hasCards() == false && player->getCardAt(0) == nullptr && player->getCardAt(1) == nullptr && player->getCardAt(2) == nullptr && player->getCardAt(3) == nullptr && player->getCardAt(4) == nullptr);
}

void BasePlayerTests::TestClearCardsThreeCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	player->playCard(0);
	player->playCard(1);
	player->playCard(2);
	player->clearCards();
	Assert(player->getScore() == 0 && player->hasCards() == false && player->getCardAt(0) == nullptr && player->getCardAt(1) == nullptr && player->getCardAt(2) == nullptr && player->getCardAt(3) == nullptr && player->getCardAt(4) == nullptr);
}

void BasePlayerTests::TestClearCardsFiveCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew MinusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew MinusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew MinusCard(4));
	player->playCard(0);
	player->playCard(1);
	player->playCard(2);
	player->playCard(3);
	player->playCard(4);
	player->clearCards();
	Assert(player->getScore() == 0 && player->hasCards() == false && player->getCardAt(0) == nullptr && player->getCardAt(1) == nullptr && player->getCardAt(2) == nullptr && player->getCardAt(3) == nullptr && player->getCardAt(4) == nullptr);
}

void BasePlayerTests::TestAddCardNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Card^ card = gcnew PlusCard(1);
	player->addCard(card);
	Assert(player->getCardAt(0) == card);
}

void BasePlayerTests::TestAddCardOneCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	Card^ card = gcnew MinusCard(1);
	player->addCard(card);
	Assert(player->getCardAt(1) == card);
}

void BasePlayerTests::TestAddCardThreeCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	Card^ card = gcnew MinusCard(1);
	player->addCard(card);
	Assert(player->getCardAt(3) == card);
}

void BasePlayerTests::TestAddCardFiveCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Card^ firstCard = gcnew PlusCard(1);
	player->addCard(firstCard);
	Card^ secondCard = gcnew PlusCard(2);
	player->addCard(secondCard);
	Card^ thirdCard = gcnew PlusCard(3);
	player->addCard(thirdCard);
	Card^ fourthCard = gcnew PlusCard(4);
	player->addCard(fourthCard);
	Card^ fifthCard = gcnew PlusCard(5);
	player->addCard(fifthCard);
	Card^ card = gcnew MinusCard(1);
	player->addCard(card);
	Assert(player->getCardAt(0) == firstCard && player->getCardAt(1) == secondCard && player->getCardAt(2) == thirdCard && player->getCardAt(3) == fourthCard && player->getCardAt(4) == fifthCard);
}

void BasePlayerTests::TestInsertCardNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Card^ card = gcnew PlusCard(1);
	int cardIndex = player->insertCard(card);
	Assert(cardIndex == 0);
}

void BasePlayerTests::TestInsertCardOneCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	Card^ card = gcnew PlusCard(2);
	int cardIndex = player->insertCard(card);
	Assert(cardIndex == 1);
}

void BasePlayerTests::TestInsertCardThreeCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	Card^ card = gcnew PlusCard(4);
	int cardIndex = player->insertCard(card);
	Assert(cardIndex == 3);
}

void BasePlayerTests::TestInsertCardFiveCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew PlusCard(4));
	Card^ card = gcnew PlusCard(5);
	int cardIndex = player->insertCard(card);
	Assert(cardIndex == 4);
}

void BasePlayerTests::TestGetCardAtIndexMinusTenNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Card^ card = player->getCardAt(-10);
	Assert(card == nullptr);
}

void BasePlayerTests::TestGetCardAtIndexZeroNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Card^ card = player->getCardAt(0);
	Assert(card == nullptr);
}

void BasePlayerTests::TestGetCardAtIndexTwoTenNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Card^ card = player->getCardAt(2);
	Assert(card == nullptr);
}

void BasePlayerTests::TestGetCardAtIndexTenTenNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Card^ card = player->getCardAt(10);
	Assert(card == nullptr);
}

void BasePlayerTests::TestGetCardAtIndexMinusTenOneCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	Card^ card = player->getCardAt(-10);
	Assert(card == nullptr);
}

void BasePlayerTests::TestGetCardAtIndexZeroOneCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Card^ firstCard = gcnew PlusCard(1);
	player->addCard(firstCard);
	Card^ card = player->getCardAt(0);
	Assert(card == firstCard);
}

void BasePlayerTests::TestGetCardAtIndexZeroOneCardCardAtIndexZeroRemoved()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->removeCardAt(0);
	Card^ card = player->getCardAt(0);
	Assert(card == nullptr);
}

void BasePlayerTests::TestGetCardAtIndexTwoOneCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	Card^ card = player->getCardAt(2);
	Assert(card == nullptr);
}

void BasePlayerTests::TestGetCardAtIndexTenOneCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	Card^ card = player->getCardAt(10);
	Assert(card == nullptr);
}

void BasePlayerTests::TestGetCardAtIndexMinusTenThreeCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	Card^ card = player->getCardAt(-10);
	Assert(card == nullptr);
}

void BasePlayerTests::TestGetCardAtIndexZeroThreeCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Card^ firstCard = gcnew PlusCard(1);
	player->addCard(firstCard);
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	Card^ card = player->getCardAt(0);
	Assert(card == firstCard);
}

void BasePlayerTests::TestGetCardAtIndexZeroThreeCardsCardAtIndexZeroRemoved()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->removeCardAt(0);
	Card^ card = player->getCardAt(0);
	Assert(card == nullptr);
}

void BasePlayerTests::TestGetCardAtIndexTwoThreeCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	Card^ thirdCard = gcnew PlusCard(3);
	player->addCard(thirdCard);
	Card^ card = player->getCardAt(2);
	Assert(card == thirdCard);
}

void BasePlayerTests::TestGetCardAtIndexTenThreeCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	Card^ card = player->getCardAt(10);
	Assert(card == nullptr);
}

void BasePlayerTests::TestGetCardAtIndexMinusTenFiveCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew PlusCard(4));
	player->addCard(gcnew PlusCard(5));
	Card^ card = player->getCardAt(-10);
	Assert(card == nullptr);
}

void BasePlayerTests::TestGetCardAtIndexZeroFiveCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Card^ firstCard = gcnew PlusCard(1);
	player->addCard(firstCard);
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew PlusCard(4));
	player->addCard(gcnew PlusCard(5));
	Card^ card = player->getCardAt(0);
	Assert(card == firstCard);
}

void BasePlayerTests::TestGetCardAtIndexZeroFiveCardsCardAtIndexZeroRemoved()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew PlusCard(4));
	player->addCard(gcnew PlusCard(5));
	player->removeCardAt(0);
	Card^ card = player->getCardAt(0);
	Assert(card == nullptr);
}

void BasePlayerTests::TestGetCardAtIndexTwoFiveCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	Card^ thirdCard = gcnew PlusCard(3);
	player->addCard(thirdCard);
	player->addCard(gcnew PlusCard(4));
	player->addCard(gcnew PlusCard(5));
	Card^ card = player->getCardAt(2);
	Assert(card == thirdCard);
}

void BasePlayerTests::TestGetCardAtIndexTenFiveCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew PlusCard(4));
	player->addCard(gcnew PlusCard(5));
	Card^ card = player->getCardAt(10);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexMinusTenNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	int index = -10;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexZeroNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	int index = 0;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexTwoNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	int index = 2;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexTenNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	int index = 10;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexMinusTenOneCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	int index = -10;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexZeroOneCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	int index = 0;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexZeroOneCardCardAtIndexZeroRemoved()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	int index = 0;
	player->removeCardAt(index);
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexTwoOneCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	int index = 2;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexTenOneCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	int index = 10;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexMinusTenThreeCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	int index = -10;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexZeroThreeCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	int index = 0;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexZeroThreeCardsCardAtIndexZeroRemoved()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	int index = 0;
	player->removeCardAt(index);
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexTwoThreeCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	int index = 2;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexTenThreeCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	int index = 10;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexMinusTenFiveCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew PlusCard(4));
	player->addCard(gcnew PlusCard(5));
	int index = -10;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexZeroFiveCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew PlusCard(4));
	player->addCard(gcnew PlusCard(5));
	int index = 0;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexZeroFiveCardsCardAtIndexZeroRemoved()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew PlusCard(4));
	player->addCard(gcnew PlusCard(5));
	int index = 0;
	player->removeCardAt(index);
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexTwoFiveCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew PlusCard(4));
	player->addCard(gcnew PlusCard(5));
	int index = 2;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestRemoveCardAtIndexTenFiveCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew PlusCard(4));
	player->addCard(gcnew PlusCard(5));
	int index = 10;
	player->removeCardAt(index);
	Card^ card = player->getCardAt(index);
	Assert(card == nullptr);
}

void BasePlayerTests::TestSelectedAllCardsNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Assert(player->selectedAllCards() == false);
}

void BasePlayerTests::TestSelectedAllCardsOneCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	Assert(player->selectedAllCards() == false);
}

void BasePlayerTests::TestSelectedAllCardsThreeCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	Assert(player->selectedAllCards() == false);
}

void BasePlayerTests::TestSelectedAllCardsFiveCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew PlusCard(4));
	player->addCard(gcnew PlusCard(5));
	Assert(player->selectedAllCards() == true);
}

void BasePlayerTests::TestHasCardsNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Assert(player->hasCards() == false);
}

void BasePlayerTests::TestHasCardsOneCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	Assert(player->hasCards() == true);
}

void BasePlayerTests::TestHasCardsThreeCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	Assert(player->hasCards() == true);
}

void BasePlayerTests::TestHasCardsFiveCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->addCard(gcnew PlusCard(2));
	player->addCard(gcnew PlusCard(3));
	player->addCard(gcnew PlusCard(4));
	player->addCard(gcnew PlusCard(5));
	Assert(player->hasCards() == true);
}

void BasePlayerTests::TestGetMaxCardsCountZero()
{
	int maxCardsCount = 0;
	BasePlayer^ player = gcnew BasePlayer("Player", maxCardsCount);
	Assert(player->getMaxCardsCount() == maxCardsCount);
}

void BasePlayerTests::TestGetMaxCardsCountOne()
{
	int maxCardsCount = 1;
	BasePlayer^ player = gcnew BasePlayer("Player", maxCardsCount);
	Assert(player->getMaxCardsCount() == maxCardsCount);
}

void BasePlayerTests::TestGetMaxCardsCountThree()
{
	int maxCardsCount = 3;
	BasePlayer^ player = gcnew BasePlayer("Player", maxCardsCount);
	Assert(player->getMaxCardsCount() == maxCardsCount);
}

void BasePlayerTests::TestPlayCardAtIndexMinusTenNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	player->playCard(-10);
	Assert(player->getScore() == 0 && opponent->getScore() == 0);
}

void BasePlayerTests::TestPlayCardAtIndexZeroNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	player->playCard(0);
	Assert(player->getScore() == 0 && opponent->getScore() == 0);
}

void BasePlayerTests::TestPlayCardAtIndexTenNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	player->playCard(10);
	Assert(player->getScore() == 0 && opponent->getScore() == 0);
}

void BasePlayerTests::TestPlayPlusCard1()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	int power = 1;
	player->addCard(gcnew PlusCard(power));
	player->playCard(0);
	Assert(player->getScore() == power && opponent->getScore() == 0);
}

void BasePlayerTests::TestPlayPlusCard2()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	int power = 2;
	player->addCard(gcnew PlusCard(power));
	player->playCard(0);
	Assert(player->getScore() == power && opponent->getScore() == 0);
}

void BasePlayerTests::TestPlayPlusCard3()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	int power = 3;
	player->addCard(gcnew PlusCard(power));
	player->playCard(0);
	Assert(player->getScore() == power && opponent->getScore() == 0);
}

void BasePlayerTests::TestPlayPlusCard4()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	int power = 4;
	player->addCard(gcnew PlusCard(power));
	player->playCard(0);
	Assert(player->getScore() == power && opponent->getScore() == 0);
}

void BasePlayerTests::TestPlayPlusCard5()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	int power = 5;
	player->addCard(gcnew PlusCard(power));
	player->playCard(0);
	Assert(player->getScore() == power && opponent->getScore() == 0);
}

void BasePlayerTests::TestPlayMinusCard1()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	int power = 1;
	player->addCard(gcnew MinusCard(power));
	player->playCard(0);
	Assert(player->getScore() == 0 && opponent->getScore() == -power);
}

void BasePlayerTests::TestPlayMinusCard2()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	int power = 2;
	player->addCard(gcnew MinusCard(power));
	player->playCard(0);
	Assert(player->getScore() == 0 && opponent->getScore() == -power);
}

void BasePlayerTests::TestPlayMinusCard3()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	int power = 3;
	player->addCard(gcnew MinusCard(power));
	player->playCard(0);
	Assert(player->getScore() == 0 && opponent->getScore() == -power);
}

void BasePlayerTests::TestPlayMinusCard4()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	int power = 4;
	player->addCard(gcnew MinusCard(power));
	player->playCard(0);
	Assert(player->getScore() == 0 && opponent->getScore() == -power);
}

void BasePlayerTests::TestPlayMinusCard5()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	int power = 5;
	player->addCard(gcnew MinusCard(power));
	player->playCard(0);
	Assert(player->getScore() == 0 && opponent->getScore() == -power);
}

void BasePlayerTests::TestPlayStealCardOpponentHasNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	player->addCard(gcnew StealCard());
	player->playCard(0);
	Assert(player->getScore() == 1 && opponent->getScore() == 0);
}

void BasePlayerTests::TestPlayStealCardOpponentHasCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	player->addCard(gcnew StealCard());
	opponent->addCard(gcnew PlusCard(1));
	player->playCard(0);
	Assert(player->getScore() == 0 && opponent->getScore() == 0);
}

void BasePlayerTests::TestPlayDoubleCardZeroScore()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	player->addCard(gcnew DoubleCard());
	player->playCard(0);
	Assert(player->getScore() == 0 && opponent->getScore() == 0);
}

void BasePlayerTests::TestPlayDoubleCardPositiveScore()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	int power = 3;
	player->addCard(gcnew PlusCard(power));
	player->addCard(gcnew DoubleCard());
	player->playCard(0);
	player->playCard(1);
	Assert(player->getScore() == 2 * power && opponent->getScore() == 0);
}

void BasePlayerTests::TestPlayDoubleCardNegativeScore()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	int power = 3;
	opponent->addCard(gcnew MinusCard(power));
	player->addCard(gcnew DoubleCard());
	opponent->playCard(0);
	player->playCard(0);
	Assert(player->getScore() == -2 * power && opponent->getScore() == 0);
}

void BasePlayerTests::TestPlayChangeCardOpponentDidNotPlayCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	player->addCard(gcnew ChangeCard());
	player->playCard(0);
	Assert(player->getScore() == 3 && opponent->getScore() == -3);
}

void BasePlayerTests::TestPlayChangeCardOpponentLastPlayedCardPlusCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew ChangeCard());
	int power = 1;
	opponent->addCard(gcnew PlusCard(power));
	opponent->playCard(0);
	player->playCard(0);
	Assert(player->getScore() == power && opponent->getScore() == 0);
}

void BasePlayerTests::TestPlayChangeCardOpponentLastPlayedCardMinusCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew ChangeCard());
	int power = 1;
	opponent->addCard(gcnew MinusCard(power));
	opponent->playCard(0);
	player->playCard(0);
	Assert(player->getScore() == 0 && opponent->getScore() == -power);
}

void BasePlayerTests::TestPlayChangeCardOpponentLastPlayedCardStealCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew ChangeCard());
	opponent->addCard(gcnew StealCard());
	opponent->playCard(0);
	player->playCard(0);
	Assert(player->getScore() == 3 && opponent->getScore() == -3);
}

void BasePlayerTests::TestPlayChangeCardOpponentLastPlayedCardDoubleCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	int playerPower = 5;
	player->addCard(gcnew PlusCard(playerPower));
	player->addCard(gcnew ChangeCard());
	int opponentPower = 1;
	opponent->addCard(gcnew PlusCard(opponentPower));
	opponent->addCard(gcnew DoubleCard());
	opponent->playCard(0);
	opponent->playCard(1);
	player->playCard(0);
	player->playCard(1);
	Assert(player->getScore() == 2 * playerPower && opponent->getScore() == opponentPower);
}

void BasePlayerTests::TestPlayChangeCardOpponentLastPlayedCardChangeCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew ChangeCard());
	opponent->addCard(gcnew ChangeCard());
	opponent->playCard(0);
	player->playCard(0);
	Assert(player->getScore() == 0 && opponent->getScore() == 0);
}

void BasePlayerTests::TestIsLastPlayedCardStealNoCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Assert(player->isLastPlayedCardSteal() == false);
}

void BasePlayerTests::TestIsLastPlayedCardStealStealCardPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	player->addCard(gcnew StealCard());
	player->playCard(0);
	Assert(player->isLastPlayedCardSteal() == true);
}

void BasePlayerTests::TestIsLastPlayedCardStealOtherThanStealCardPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	player->addCard(gcnew PlusCard(1));
	player->playCard(0);
	Assert(player->isLastPlayedCardSteal() == false);
}

void BasePlayerTests::TestGetCardsDescriptionNoCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Assert(player->getCardsDescription() == "");
}

void BasePlayerTests::TestGetCardsDescriptionOneCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Card^ card = gcnew PlusCard(1);
	player->addCard(card);
	Assert(player->getCardsDescription() == card->getName() + " ");
}

void BasePlayerTests::TestGetCardsDescriptionOneCardOneCardPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Card^ card = gcnew PlusCard(1);
	player->addCard(card);
	player->playCard(0);
	Assert(player->getCardsDescription() == "");
}

void BasePlayerTests::TestGetCardsDescriptionThreeCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Card^ firstCard = gcnew PlusCard(1);
	Card^ secondCard = gcnew MinusCard(2);
	Card^ thirdCard = gcnew StealCard();
	player->addCard(firstCard);
	player->addCard(secondCard);
	player->addCard(thirdCard);
	String^ cardsDescription = firstCard->getName() + " " + secondCard->getName() + " " + thirdCard->getName() + " ";
	Assert(player->getCardsDescription() == cardsDescription);
}

void BasePlayerTests::TestGetCardsDescriptionThreeCardsOneCardPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	Card^ firstCard = gcnew PlusCard(1);
	Card^ secondCard = gcnew MinusCard(2);
	Card^ thirdCard = gcnew StealCard();
	player->addCard(firstCard);
	player->addCard(secondCard);
	player->addCard(thirdCard);
	player->playCard(1);
	String^ cardsDescription = firstCard->getName() + " " + thirdCard->getName() + " ";
	Assert(player->getCardsDescription() == cardsDescription);
}

void BasePlayerTests::TestGetCardsDescriptionFiveCards()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Card^ firstCard = gcnew PlusCard(1);
	Card^ secondCard = gcnew MinusCard(2);
	Card^ thirdCard = gcnew StealCard();
	Card^ fourthCard = gcnew DoubleCard();
	Card^ fifthCard = gcnew ChangeCard();
	player->addCard(firstCard);
	player->addCard(secondCard);
	player->addCard(thirdCard);
	player->addCard(fourthCard);
	player->addCard(fifthCard);
	String^ cardsDescription = firstCard->getName() + " " + secondCard->getName() + " " + thirdCard->getName() + " " + fourthCard->getName() + " " + fifthCard->getName() + " ";
	Assert(player->getCardsDescription() == cardsDescription);
}

void BasePlayerTests::TestGetCardsDescriptionFiveCardsTwoCardsPlayed()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	Card^ firstCard = gcnew PlusCard(1);
	Card^ secondCard = gcnew MinusCard(2);
	Card^ thirdCard = gcnew StealCard();
	Card^ fourthCard = gcnew DoubleCard();
	Card^ fifthCard = gcnew ChangeCard();
	player->addCard(firstCard);
	player->addCard(secondCard);
	player->addCard(thirdCard);
	player->addCard(fourthCard);
	player->addCard(fifthCard);
	player->playCard(1);
	player->playCard(3);
	String^ cardsDescription = firstCard->getName() + " " + thirdCard->getName() + " " + fifthCard->getName() + " ";
	Assert(player->getCardsDescription() == cardsDescription);
}

void BasePlayerTests::TestGetLastPlayedCardDescriptionNoCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	Assert(player->getLastPlayedCardDescription() == "");
}

void BasePlayerTests::TestGetLastPlayedCardDescriptionPlusCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	Card^ card = gcnew PlusCard(1);
	player->addCard(card);
	player->playCard(0);
	Assert(player->getLastPlayedCardDescription() == card->getName());
}

void BasePlayerTests::TestGetLastPlayedCardDescriptionMinusCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	Card^ card = gcnew MinusCard(1);
	player->addCard(card);
	player->playCard(0);
	Assert(player->getLastPlayedCardDescription() == card->getName());
}

void BasePlayerTests::TestGetLastPlayedCardDescriptionStealCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	Card^ card = gcnew StealCard();
	player->addCard(card);
	player->playCard(0);
	Assert(player->getLastPlayedCardDescription() == card->getName());
}

void BasePlayerTests::TestGetLastPlayedCardDescriptionDoubleCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	Card^ card = gcnew DoubleCard();
	player->addCard(card);
	player->playCard(0);
	Assert(player->getLastPlayedCardDescription() == card->getName());
}

void BasePlayerTests::TestGetLastPlayedCardDescriptionChangeCard()
{
	BasePlayer^ player = gcnew BasePlayer("Player", 5);
	BasePlayer^ opponent = gcnew BasePlayer("Opponent", 5);
	player->setOpponent(opponent);
	opponent->setOpponent(player);
	Card^ card = gcnew ChangeCard();
	player->addCard(card);
	player->playCard(0);
	Assert(player->getLastPlayedCardDescription() == card->getName());
}
