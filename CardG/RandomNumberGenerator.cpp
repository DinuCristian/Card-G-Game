#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator()
{
    this->random = gcnew Random();
}

RandomNumberGenerator^ RandomNumberGenerator::getInstance()
{
    if (instance == nullptr)
    {
        instance = gcnew RandomNumberGenerator();
    }

    return instance;
}

int RandomNumberGenerator::getRandomInt(int minValue, int maxValue)
{
    
    return this->random->Next(minValue, maxValue);
}
