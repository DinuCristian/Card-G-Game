#include "Test.h"

Test::Test()
{
	// Get the type of the current test instance.
	Type^ type = GetType();

	// Display the name of the current tests.
	richTextBox->SelectionFont = gcnew System::Drawing::Font(richTextBox->Font, FontStyle::Bold);
	richTextBox->SelectionColor = System::Drawing::Color::Gray;
	richTextBox->SelectedText += type->Name + Environment::NewLine;
}

void Test::Init(RichTextBox^ r)
{
	richTextBox = r;
	testCount = 0;
	passedTestCount = 0;
}

void Test::Assert(bool condition)
{
	// Increment the number of tests.
	testCount += 1;

	// Get the call stack.
	StackTrace^ stackTrace = gcnew StackTrace();
	// Get the test method name.
	String^ testMethodName = stackTrace->GetFrame(1)->GetMethod()->Name;

	if (condition)
	{
		// Display passed test infromation.
		richTextBox->SelectionFont = gcnew System::Drawing::Font(richTextBox->Font, FontStyle::Bold);
		richTextBox->SelectionColor = System::Drawing::Color::Green;
		richTextBox->SelectedText += "  " + testMethodName + ": passed" + Environment::NewLine;

		// Increment the number of passed tests.
		passedTestCount += 1;
	}
	else
	{
		// Display failed test information.
		richTextBox->SelectionFont = gcnew System::Drawing::Font(richTextBox->Font, FontStyle::Bold);
		richTextBox->SelectionColor = System::Drawing::Color::Red;
		richTextBox->SelectedText += "  " + testMethodName + ": failed" + Environment::NewLine;
	}
}

void Test::DisplayStatus()
{
	// Displays the number of passed tests and the total number of tests.
	richTextBox->SelectionFont = gcnew System::Drawing::Font(richTextBox->Font, FontStyle::Bold);
	richTextBox->SelectionColor = System::Drawing::Color::Gray;
	richTextBox->SelectedText += "Passed/Total: " + passedTestCount.ToString() + "/" + testCount.ToString() + Environment::NewLine;
}

void Test::Run()
{
	// Get the class name.
	Type^ type = this->GetType();

	// Get all the methods.
	array<MethodInfo^>^ methodInfo = type->GetMethods();

	// Loop thorugh all the methods.
	for (int i = 0; i < methodInfo->Length; i++)
	{
		// Get the method name.
		String^ methodName = methodInfo[i]->Name;

		// If the method name does not start with "Test" skip it.
		if (!methodName->StartsWith("Test"))
		{
			continue;
		}

		// Call the test method.
		type->InvokeMember(methodName, BindingFlags::InvokeMethod | BindingFlags::Public | BindingFlags::Static, nullptr, nullptr, nullptr);
	}
}
