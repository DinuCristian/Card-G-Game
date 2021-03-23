#pragma once

using namespace System;
using namespace System::Reflection;
using namespace System::Diagnostics;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class Test
{
private:
	// The number of tests.
	static int testCount = 0;

	// The number of passed tests.
	static int passedTestCount = 0;
	
	// The rich text box control used to display test information.
	static RichTextBox^ richTextBox;

public:
	// Represents a test.
	Test();

	// Inits the test.
	//   richTextBox: The rich text box control used to display test information.
	static void Init(RichTextBox^ richTextBox);

	// Asserts the given condition.
	//   condition: the condition to assert.
	static void Assert(bool condition);

	// Displays the test status.
	static void DisplayStatus();

	// Runs the test.
	virtual void Run();
};

