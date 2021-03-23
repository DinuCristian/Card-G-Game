#pragma once

using namespace System;

[Serializable]
ref class GameSettings
{
private:
    // The game settings.
    GameSettings();


    // The game settings instance.
    [NonSerialized]
    static GameSettings^ instance;


    // The settings file path.
    static String^ settingsFilePath = "Card-G.settings";


    // The default virtual player speed.
    static int defaultVirtualPlayerSpeed = 1;
    
    // The virtual player speed.
    int virtualPlayerSpeed;


    // The default card theme colour.
    static String^ defaultThemeColour = "Black";

    // The card theme colour.
    String^ themeColour;



    // The default number of Minus cards in the card deck.
    static array<int>^ defaultMinusCardCount = {2, 2, 2, 2, 2};

    // The number of Minus cards in the card deck.
    array<int>^ minusCardCount;


    // The default number of Plus cards in the card deck.
    static array<int>^ defaultPlusCardCount = {2, 2, 2, 2, 2 };

    // The number of Plus cards in the card deck.
    array<int>^ plusCardCount;


    // The default number of Steal cards in the card deck.
    static int defaultStealCardCount = 2;

    // The number of Steal cards in the card deck.
    int stealCardCount;


    // The default number of Double cards in the card deck.
    static int defaultDoubleCardCount = 0;

    // The number of Double cards in the card deck.
    int doubleCardCount;


    // The default number of Change cards in the card deck.
    static int defaultChangeCardCount = 0;

    // The number of Change cards in the card deck.
    int changeCardCount;


    // Loads the default game settings.
    void loadDefaultSettings();

public:
    // Gets the game settings instance.
    static GameSettings^ getInstance();

    // Resets the game settings to the default game settings.
    void resetGameSettings();

    // Saves the game settings.
    void saveGameSettings();


    // Gets the virtual player speed.
    int getVirtualPlayerSpeed();

    // Sets the virtual player speed.
    //   virtualPlayerSpeed: The virtual player speed to set.
    void setVirtualPlayerSpeed(int virtualPlayerSpeed);


    // Gets the theme colour.
    String^ getThemeColour();

    // Sets the theme colour.
    //   themeColour: The theme colour to set.
    void setThemeColour(String^ themeColour);


    // Gets the number of Minus cards with the given power in the cards deck.
    //   power: The power of the Minus card.
    int getMinusCardCount(int power);

    // Sets the number of Minus cards with the given power in the card deck.
    //   power: The power of the Minus card.
    //   cardCount: The number of Minus cards with the given power to set.
    void setMinusCardCount(int power, int cardCount);


    // Gets the number of Plus cards with the given power in the card deck.
    //   power: The power of the Plus card. 
    int getPlusCardCount(int power);

    // Sets the number of Plus cards with the given power in the card deck.
    //   power: The power of the Plus card.
    //   cardCount: The number of Plus cards with the given power to set.
    void setPlusCardCount(int power, int cardCount);


    // Gets the number of Steal cards in the card deck.
    int getCardStealCount();

    // Sets the number of Steal cards in the card deck.
    //   cardCount: The number of Steal cards.
    void setCardStealCount(int cardCount);


    // Gets the number of Double cards in the card deck.
    int getCardDoubleCount();

    // Sets the number of Double cards in the card deck.
    //   cardCount: The number of Double cards.
    void setCardDoubleCount(int cardCount);
    

    // Gets the number of Change cards in the card deck.
    int getCardChangeCount();

    // Sets the number of Change cards in the card deck.
    //   cardCount: The number of Change cards.
    void setCardChangeCount(int cardCount);


    // Gets the virtual player speed bounds.
    //   lowerBound: The inclusive lower bound of the range.
    //   upperBound: The exclusive upper bound of the range.
    void getVirtualPlayerSpeedBounds(int* lowerBound, int* upperBound);
};

