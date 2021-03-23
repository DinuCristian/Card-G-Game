#pragma once

#include "Test.h"
#include "RandomNumberGenerator.h"

ref class RandomNumberGeneratorTests :
	public Test
{
public:
	static void TestSingleton();
	static void TestGetIntFixedValue();
	static void TestGetIntInRange();
};

