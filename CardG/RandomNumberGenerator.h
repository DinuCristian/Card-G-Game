#pragma once

using namespace System;

ref class RandomNumberGenerator
{
private:
    // The pseudo-random number generator.
    Random^ random;

    // Represents a random number generator.
    RandomNumberGenerator();

    // The random number generator instance.
    static RandomNumberGenerator^ instance;

public:
    // Gets the random number generator instance.
    static RandomNumberGenerator^ getInstance();

    // Gets a random integer that is within the given range.
    //   minValue: The inclusive lower bound of the given range.
    //   maxValue: The exclusive upper bound of the given range.
    int getRandomInt(int minValue, int maxValue);
};

