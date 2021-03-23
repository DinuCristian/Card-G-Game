#pragma once

#include "Test.h"
#include "GameSettings.h"

ref class GameSettingsTests :
	public Test
{
public:
    static void TestSingleton();

    static void TestSaveGameSettings();

    static void TestDefaultVirtualPlayerSpeed();
    static void TestVirtualPlayerSpeed();

    static void TestDefaultThemeColour();
    static void TestThemeColour();

    static void TestDefaultMinusCardCount1();
    static void TestMinusCardCount1();

    static void TestDefaultMinusCardCount2();
    static void TestMinusCardCount2();

    static void TestDefaultMinusCardCount3();
    static void TestMinusCardCount3();

    static void TestDefaultMinusCardCount4();
    static void TestMinusCardCount4();

    static void TestDefaultMinusCardCount5();
    static void TestMinusCardCount5();

    static void TestDefaultPlusCardCount1();
    static void TestPlusCardCount1();

    static void TestDefaultPlusCardCount2();
    static void TestPlusCardCount2();

    static void TestDefaultPlusCardCount3();
    static void TestPlusCardCount3();

    static void TestDefaultPlusCardCount4();
    static void TestPlusCardCount4();

    static void TestDefaultPlusCardCount5();
    static void TestPlusCardCount5();

    static void TestDefaultStealCardCount();
    static void TestStealCardCount();

    static void TestDefaultDoubleCardCount();
    static void TestDoubleCardCount();

    static void TestDefaultChangeCardCount();
    static void TestChangeCardCount();

    static void TestDefaultVirtualPlayerSpeedBounds();
    static void TestVirtualPlayerSpeedBounds();

    static void TestResetGameSettings();
};

