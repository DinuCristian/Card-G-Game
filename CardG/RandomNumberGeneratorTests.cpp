#include "RandomNumberGeneratorTests.h"

void RandomNumberGeneratorTests::TestSingleton()
{
	RandomNumberGenerator^ rng1 = RandomNumberGenerator::getInstance();
	RandomNumberGenerator^ rng2 = RandomNumberGenerator::getInstance();
	Assert(rng1 == rng2);
}

void RandomNumberGeneratorTests::TestGetIntFixedValue()
{
	RandomNumberGenerator^ rng = RandomNumberGenerator::getInstance();
	Assert(rng->getRandomInt(10, 10) == 10);
}

void RandomNumberGeneratorTests::TestGetIntInRange()
{
	RandomNumberGenerator^ rng = RandomNumberGenerator::getInstance();
	Assert(0 <= rng->getRandomInt(0, 10) < 10);
}
