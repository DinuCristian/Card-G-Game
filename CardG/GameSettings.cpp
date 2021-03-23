#include "GameSettings.h"

GameSettings::GameSettings()
{
    this->loadDefaultSettings();
}

void GameSettings::loadDefaultSettings()
{
    // Overwrite current game settings with the default game settings.
    this->virtualPlayerSpeed = this->defaultVirtualPlayerSpeed;

    this->themeColour = this->defaultThemeColour;

    this->minusCardCount = gcnew array<int>(this->defaultMinusCardCount->Length);
    this->defaultMinusCardCount->CopyTo(this->minusCardCount, 0);
    this->plusCardCount = gcnew array<int>(this->defaultPlusCardCount->Length);
    this->defaultPlusCardCount->CopyTo(this->plusCardCount, 0);
    this->stealCardCount = this->defaultStealCardCount;

    this->doubleCardCount = this->defaultDoubleCardCount;
    this->changeCardCount = this->defaultChangeCardCount;
}

GameSettings^ GameSettings::getInstance()
{
    if (instance == nullptr)
    {
        try
        {
            // Check if the game settings file exists.
            System::IO::FileStream^ fileStream = gcnew System::IO::FileStream(settingsFilePath, System::IO::FileMode::Open, System::IO::FileAccess::ReadWrite);
            System::Runtime::Serialization::Formatters::Binary::BinaryFormatter^ formatter = gcnew System::Runtime::Serialization::Formatters::Binary::BinaryFormatter();
            instance = static_cast<GameSettings^>(formatter->Deserialize(fileStream));
            fileStream->Close();
        }
        catch (Exception^ e)
        {
            instance = gcnew GameSettings();

            // Save the default game settings to file.
            System::IO::FileStream^ fileStream = gcnew System::IO::FileStream(settingsFilePath, System::IO::FileMode::Create);
            System::Runtime::Serialization::Formatters::Binary::BinaryFormatter^ formatter = gcnew System::Runtime::Serialization::Formatters::Binary::BinaryFormatter();
            formatter->Serialize(fileStream, instance);
            fileStream->Close();
        }
    }

    return instance;
}

void GameSettings::resetGameSettings()
{
    this->loadDefaultSettings();
    this->saveGameSettings();
}

void GameSettings::saveGameSettings()
{
    System::IO::FileStream^ fileStream = gcnew System::IO::FileStream(settingsFilePath, System::IO::FileMode::Create);
    System::Runtime::Serialization::Formatters::Binary::BinaryFormatter^ formatter = gcnew System::Runtime::Serialization::Formatters::Binary::BinaryFormatter();
    formatter->Serialize(fileStream, instance);
    fileStream->Close();
}

int GameSettings::getVirtualPlayerSpeed()
{
    return this->virtualPlayerSpeed;
}

void GameSettings::setVirtualPlayerSpeed(int virtualPlayerSpeed)
{
    this->virtualPlayerSpeed = virtualPlayerSpeed;
}

String^ GameSettings::getThemeColour()
{
    return this->themeColour;
}

void GameSettings::setThemeColour(String^ themeColour)
{
    this->themeColour = themeColour;
}

int GameSettings::getMinusCardCount(int power)
{
    return this->minusCardCount[power - 1];
}

void GameSettings::setMinusCardCount(int power, int cardCount)
{
    this->minusCardCount[power - 1] = cardCount;
}

int GameSettings::getPlusCardCount(int power)
{
    return this->plusCardCount[power - 1];
}

void GameSettings::setPlusCardCount(int power, int cardCount)
{
    this->plusCardCount[power - 1] = cardCount;
}

int GameSettings::getCardStealCount()
{
    return this->stealCardCount;
}

void GameSettings::setCardStealCount(int cardCount)
{
    this->stealCardCount = cardCount;
}

int GameSettings::getCardDoubleCount()
{
    return this->doubleCardCount;
}

void GameSettings::setCardDoubleCount(int cardCount)
{
    this->doubleCardCount = cardCount;
}

int GameSettings::getCardChangeCount()
{
    return this->changeCardCount;
}

void GameSettings::setCardChangeCount(int cardCount)
{
    this->changeCardCount = cardCount;
}

void GameSettings::getVirtualPlayerSpeedBounds(int* lowerBound, int* upperBound)
{
    // Set intitial virtual player speed bounds.
    *lowerBound = 0;
    *upperBound = 0;

    // Update the virtual player speed bounds depending on the virtual player speed.
    switch (this->virtualPlayerSpeed)
    {
    case 0:
        *lowerBound = 3000;
        *upperBound = 5000;
        break;
    case 1:
        *lowerBound = 1000;
        *upperBound = 3000;
        break;
    case 2:
        *lowerBound = 0;
        *upperBound = 1000;
        break;
    default:
        break;
    }
}
