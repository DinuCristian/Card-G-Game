#pragma once

#include "Test.h"
#include "BasePlayer.h"
#include "MinusCard.h"
#include "PlusCard.h"
#include "StealCard.h"
#include "DoubleCard.h"
#include "ChangeCard.h"

ref class BasePlayerTests :
	public Test
{
public:
	static void TestGetName();


	static void TestGetScoreNoCardsPlayed();
	static void TestGetScoreOneCardPlayed();
	static void TestGetScoreTwoCardsPlayed();
	static void TestGetScoreThreeCardsPlayed();
	static void TestGetScoreFourCardsPlayed();
	static void TestGetScoreFiveCardsPlayed();
	static void TestGetScoreSixCardsPlayed();
	static void TestGetScoreSevenCardsPlayed();
	static void TestGetScoreEightCardsPlayed();
	static void TestGetScoreNineCardsPlayed();
	static void TestGetScoreTenCardsPlayed();


	static void TestClearCardsNoCards();
	static void TestClearCardsOneCardPlayed();
	static void TestClearCardsTwoCardsPlayed();
	static void TestClearCardsThreeCardsPlayed();
	static void TestClearCardsFiveCardsPlayed();


	static void TestAddCardNoCards();
	static void TestAddCardOneCard();
	static void TestAddCardThreeCards();
	static void TestAddCardFiveCards();


	static void TestInsertCardNoCards();
	static void TestInsertCardOneCard();
	static void TestInsertCardThreeCards();
	static void TestInsertCardFiveCards();


	static void TestGetCardAtIndexMinusTenNoCards();
	static void TestGetCardAtIndexZeroNoCards();
	static void TestGetCardAtIndexTwoTenNoCards();
	static void TestGetCardAtIndexTenTenNoCards();

	static void TestGetCardAtIndexMinusTenOneCard();
	static void TestGetCardAtIndexZeroOneCard();
	static void TestGetCardAtIndexZeroOneCardCardAtIndexZeroRemoved();
	static void TestGetCardAtIndexTwoOneCard();
	static void TestGetCardAtIndexTenOneCard();

	static void TestGetCardAtIndexMinusTenThreeCards();
	static void TestGetCardAtIndexZeroThreeCards();
	static void TestGetCardAtIndexZeroThreeCardsCardAtIndexZeroRemoved();
	static void TestGetCardAtIndexTwoThreeCards();
	static void TestGetCardAtIndexTenThreeCards();

	static void TestGetCardAtIndexMinusTenFiveCards();
	static void TestGetCardAtIndexZeroFiveCards();
	static void TestGetCardAtIndexZeroFiveCardsCardAtIndexZeroRemoved();
	static void TestGetCardAtIndexTwoFiveCards();
	static void TestGetCardAtIndexTenFiveCards();


	static void TestRemoveCardAtIndexMinusTenNoCards();
	static void TestRemoveCardAtIndexZeroNoCards();
	static void TestRemoveCardAtIndexTwoNoCards();
	static void TestRemoveCardAtIndexTenNoCards();

	static void TestRemoveCardAtIndexMinusTenOneCard();
	static void TestRemoveCardAtIndexZeroOneCard();
	static void TestRemoveCardAtIndexZeroOneCardCardAtIndexZeroRemoved();
	static void TestRemoveCardAtIndexTwoOneCard();
	static void TestRemoveCardAtIndexTenOneCard();

	static void TestRemoveCardAtIndexMinusTenThreeCards();
	static void TestRemoveCardAtIndexZeroThreeCards();
	static void TestRemoveCardAtIndexZeroThreeCardsCardAtIndexZeroRemoved();
	static void TestRemoveCardAtIndexTwoThreeCards();
	static void TestRemoveCardAtIndexTenThreeCards();

	static void TestRemoveCardAtIndexMinusTenFiveCards();
	static void TestRemoveCardAtIndexZeroFiveCards();
	static void TestRemoveCardAtIndexZeroFiveCardsCardAtIndexZeroRemoved();
	static void TestRemoveCardAtIndexTwoFiveCards();
	static void TestRemoveCardAtIndexTenFiveCards();


	static void TestSelectedAllCardsNoCards();
	static void TestSelectedAllCardsOneCard();
	static void TestSelectedAllCardsThreeCards();
	static void TestSelectedAllCardsFiveCards();


	static void TestHasCardsNoCards();
	static void TestHasCardsOneCard();
	static void TestHasCardsThreeCards();
	static void TestHasCardsFiveCards();


	static void TestGetMaxCardsCountZero();
	static void TestGetMaxCardsCountOne();
	static void TestGetMaxCardsCountThree();


	static void TestPlayCardAtIndexMinusTenNoCards();
	static void TestPlayCardAtIndexZeroNoCards();
	static void TestPlayCardAtIndexTenNoCards();

	static void TestPlayPlusCard1();
	static void TestPlayPlusCard2();
	static void TestPlayPlusCard3();
	static void TestPlayPlusCard4();
	static void TestPlayPlusCard5();

	static void TestPlayMinusCard1();
	static void TestPlayMinusCard2();
	static void TestPlayMinusCard3();
	static void TestPlayMinusCard4();
	static void TestPlayMinusCard5();

	static void TestPlayStealCardOpponentHasNoCards();
	static void TestPlayStealCardOpponentHasCards();

	static void TestPlayDoubleCardZeroScore();
	static void TestPlayDoubleCardNegativeScore();
	static void TestPlayDoubleCardPositiveScore();

	static void TestPlayChangeCardOpponentDidNotPlayCards();
	static void TestPlayChangeCardOpponentLastPlayedCardPlusCard();
	static void TestPlayChangeCardOpponentLastPlayedCardMinusCard();
	static void TestPlayChangeCardOpponentLastPlayedCardStealCard();
	static void TestPlayChangeCardOpponentLastPlayedCardDoubleCard();
	static void TestPlayChangeCardOpponentLastPlayedCardChangeCard();


	static void TestIsLastPlayedCardStealNoCardsPlayed();
	static void TestIsLastPlayedCardStealStealCardPlayed();
	static void TestIsLastPlayedCardStealOtherThanStealCardPlayed();


	static void TestGetCardsDescriptionNoCards();
	static void TestGetCardsDescriptionOneCard();
	static void TestGetCardsDescriptionOneCardOneCardPlayed();
	static void TestGetCardsDescriptionThreeCards();
	static void TestGetCardsDescriptionThreeCardsOneCardPlayed();
	static void TestGetCardsDescriptionFiveCards();
	static void TestGetCardsDescriptionFiveCardsTwoCardsPlayed();


	static void TestGetLastPlayedCardDescriptionNoCard();
	static void TestGetLastPlayedCardDescriptionPlusCard();
	static void TestGetLastPlayedCardDescriptionMinusCard();
	static void TestGetLastPlayedCardDescriptionStealCard();
	static void TestGetLastPlayedCardDescriptionDoubleCard();
	static void TestGetLastPlayedCardDescriptionChangeCard();

};

