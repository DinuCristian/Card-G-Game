#include "GameSettingsTests.h"

void GameSettingsTests::TestSingleton()
{
	GameSettings^ gameSettings1 = GameSettings::getInstance();
	GameSettings^ gameSettings2 = GameSettings::getInstance();
	Assert(gameSettings1 == gameSettings2);
}

void GameSettingsTests::TestSaveGameSettings()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setVirtualPlayerSpeed(3);
	gameSettings->saveGameSettings();
	Assert(gameSettings->getVirtualPlayerSpeed() == 3);
}

void GameSettingsTests::TestDefaultVirtualPlayerSpeed()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getVirtualPlayerSpeed() == 1);
}

void GameSettingsTests::TestVirtualPlayerSpeed()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setVirtualPlayerSpeed(3);
	Assert(gameSettings->getVirtualPlayerSpeed() == 3);
}

void GameSettingsTests::TestDefaultThemeColour()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getThemeColour() == "Black");

}

void GameSettingsTests::TestThemeColour()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setThemeColour("Red");
	Assert(gameSettings->getThemeColour() == "Red");
}

void GameSettingsTests::TestDefaultMinusCardCount1()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getMinusCardCount(1) == 2);
}

void GameSettingsTests::TestMinusCardCount1()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setMinusCardCount(1, 4);
	Assert(gameSettings->getMinusCardCount(1) == 4);
}

void GameSettingsTests::TestDefaultMinusCardCount2()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getMinusCardCount(2) == 2);
}

void GameSettingsTests::TestMinusCardCount2()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setMinusCardCount(2, 4);
	Assert(gameSettings->getMinusCardCount(2) == 4);
}

void GameSettingsTests::TestDefaultMinusCardCount3()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getMinusCardCount(3) == 2);
}

void GameSettingsTests::TestMinusCardCount3()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setMinusCardCount(3, 4);
	Assert(gameSettings->getMinusCardCount(3) == 4);
}

void GameSettingsTests::TestDefaultMinusCardCount4()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getMinusCardCount(4) == 2);
}

void GameSettingsTests::TestMinusCardCount4()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setMinusCardCount(4, 4);
	Assert(gameSettings->getMinusCardCount(4) == 4);
}

void GameSettingsTests::TestDefaultMinusCardCount5()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getMinusCardCount(5) == 2);
}

void GameSettingsTests::TestMinusCardCount5()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setMinusCardCount(5, 4);
	Assert(gameSettings->getMinusCardCount(5) == 4);
}

void GameSettingsTests::TestDefaultPlusCardCount1()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getPlusCardCount(1) == 2);
}

void GameSettingsTests::TestPlusCardCount1()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setPlusCardCount(1, 4);
	Assert(gameSettings->getPlusCardCount(1) == 4);
}

void GameSettingsTests::TestDefaultPlusCardCount2()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getPlusCardCount(2) == 2);
}

void GameSettingsTests::TestPlusCardCount2()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setPlusCardCount(2, 4);
	Assert(gameSettings->getPlusCardCount(2) == 4);
}

void GameSettingsTests::TestDefaultPlusCardCount3()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getPlusCardCount(3) == 2);
}

void GameSettingsTests::TestPlusCardCount3()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setPlusCardCount(3, 4);
	Assert(gameSettings->getPlusCardCount(3) == 4);
}

void GameSettingsTests::TestDefaultPlusCardCount4()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getPlusCardCount(4) == 2);
}

void GameSettingsTests::TestPlusCardCount4()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setPlusCardCount(4, 4);
	Assert(gameSettings->getPlusCardCount(4) == 4);
}

void GameSettingsTests::TestDefaultPlusCardCount5()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getPlusCardCount(5) == 2);
}

void GameSettingsTests::TestPlusCardCount5()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setPlusCardCount(5, 4);
	Assert(gameSettings->getPlusCardCount(5) == 4);
}

void GameSettingsTests::TestDefaultStealCardCount()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getCardStealCount() == 2);
}

void GameSettingsTests::TestStealCardCount()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setCardStealCount(4);
	Assert(gameSettings->getCardStealCount() == 4);
}

void GameSettingsTests::TestDefaultDoubleCardCount()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getCardDoubleCount() == 0);
}

void GameSettingsTests::TestDoubleCardCount()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setCardDoubleCount(4);
	Assert(gameSettings->getCardDoubleCount() == 4);
}

void GameSettingsTests::TestDefaultChangeCardCount()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	Assert(gameSettings->getCardChangeCount() == 0);
}

void GameSettingsTests::TestChangeCardCount()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setCardChangeCount(4);
	Assert(gameSettings->getCardChangeCount() == 4);
}

void GameSettingsTests::TestDefaultVirtualPlayerSpeedBounds()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->resetGameSettings();
	int lowerBound, upperBound;
	gameSettings->getVirtualPlayerSpeedBounds(&lowerBound, &upperBound);
	Assert(lowerBound == 1000 && upperBound == 3000);
}

void GameSettingsTests::TestVirtualPlayerSpeedBounds()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setVirtualPlayerSpeed(0);
	int lowerBound, upperBound;
	gameSettings->getVirtualPlayerSpeedBounds(&lowerBound, &upperBound);
	Assert(lowerBound == 3000 && upperBound == 5000);
}

void GameSettingsTests::TestResetGameSettings()
{
	GameSettings^ gameSettings = GameSettings::getInstance();
	gameSettings->setVirtualPlayerSpeed(3);
	gameSettings->resetGameSettings();
	Assert(gameSettings->getVirtualPlayerSpeed() == 1);
}
