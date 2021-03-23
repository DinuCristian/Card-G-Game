#include "TestCases.h"

TestCases::TestCases(RichTextBox^ richTextBox)
{
	this->richTextBox = richTextBox;
}

void TestCases::Run()
{
	// Clear the output.
	this->richTextBox->Clear();

	// Init the test.
	Test::Init(this->richTextBox);

	// Run the tests for MinusCard.
	MinusCardTests^ minusCardTests = gcnew MinusCardTests();
	minusCardTests->Run();

	// Run the tests for PlusCard.
	PlusCardTests^ plusCardTests = gcnew PlusCardTests();
	plusCardTests->Run();

	// Run the tests for StealCard.
	StealCardTests^ stealCardTests = gcnew StealCardTests();
	stealCardTests->Run();

	// Run the tests for DoubleCard.
	DoubleCardTests^ doubleCardTests = gcnew DoubleCardTests();
	doubleCardTests->Run();

	// Run the tests for ChangeCard.
	ChangeCardTests^ changeCardTests = gcnew ChangeCardTests();
	changeCardTests->Run();

	// Run the tests for CardDeck.
	CardDeckTests^ cardDeckTests = gcnew CardDeckTests();
	cardDeckTests->Run();

	// Run the tests for BasePlayer.
	BasePlayerTests^ basePlayerTests = gcnew BasePlayerTests();
	basePlayerTests->Run();

	// Run the tests for VirtualPlayer.
	VirtualPlayerTests^ virtualPlayerTests = gcnew VirtualPlayerTests();
	virtualPlayerTests->Run();

	// Run the tests for GameSettings.
	GameSettingsTests^ gameSettingsTests = gcnew GameSettingsTests();
	gameSettingsTests->Run();

	// Run the tests for RandomNumberGenerator.
	RandomNumberGeneratorTests^ randomNumberGeneratorTests = gcnew RandomNumberGeneratorTests();
	randomNumberGeneratorTests->Run();

	// Display the test status.
	Test::DisplayStatus();

	// Scroll to the end of the rich text box control.
	this->richTextBox->ScrollToCaret();
}
