#pragma once

#include "MinusCardTests.h"
#include "PlusCardTests.h"
#include "StealCardTests.h"
#include "DoubleCardTests.h"
#include "ChangeCardTests.h"
#include "CardDeckTests.h"
#include "BasePlayerTests.h"
#include "VirtualPlayerTests.h"
#include "GameSettingsTests.h"
#include "RandomNumberGeneratorTests.h"

ref class TestCases
{
private:
	// The rich text box control used to display test information.
	RichTextBox^ richTextBox;

public:
	// Represents the test cases.
	//   richTextBox: The rich text box control used to display test information.
	TestCases(RichTextBox^ richTextBox);

	// Run all the test cases.
	void Run();
};

