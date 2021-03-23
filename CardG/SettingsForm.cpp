#include "SettingsForm.h"

namespace CardG {
	void SettingsForm::loadGameSettings()
	{
		// Get the virtual player speed.
		int virtualPlayerSpeed = this->gameEngine->getVirtualPlayerSpeed();

		// Display the virtual player speed.
		if (virtualPlayerSpeed == 0)
		{
			this->radioButtonSlow->Checked = true;
		}
		if (virtualPlayerSpeed == 1)
		{
			this->radioButtonNormal->Checked = true;
		}
		if (virtualPlayerSpeed == 2)
		{
			this->radioButtonFast->Checked = true;
		}

		// Get the theme colour.
		String^ themeColour = this->gameEngine->getThemeColour();

		// Display the theme colour.
		if (themeColour == "Black")
		{
			this->radioButtonBlack->Checked = true;
		}
		if (themeColour == "Red")
		{
			this->radioButtonRed->Checked = true;
		}
		if (themeColour == "Green")
		{
			this->radioButtonGreen->Checked = true;
		}
		if (themeColour == "Blue")
		{
			this->radioButtonBlue->Checked = true;
		}

		// Display the number of cards in the card deck for each card type.
		this->numericUpDownCardMinus1->Value = this->gameEngine->getMinusCardCount(1);
		this->numericUpDownCardMinus2->Value = this->gameEngine->getMinusCardCount(2);
		this->numericUpDownCardMinus3->Value = this->gameEngine->getMinusCardCount(3);
		this->numericUpDownCardMinus4->Value = this->gameEngine->getMinusCardCount(4);
		this->numericUpDownCardMinus5->Value = this->gameEngine->getMinusCardCount(5);

		this->numericUpDownCardPlus1->Value = this->gameEngine->getPlusCardCount(1);
		this->numericUpDownCardPlus2->Value = this->gameEngine->getPlusCardCount(2);
		this->numericUpDownCardPlus3->Value = this->gameEngine->getPlusCardCount(3);
		this->numericUpDownCardPlus4->Value = this->gameEngine->getPlusCardCount(4);
		this->numericUpDownCardPlus5->Value = this->gameEngine->getPlusCardCount(5);

		this->numericUpDownCardSteal->Value = this->gameEngine->getCardStealCount();

		this->numericUpDownCardDouble->Value = this->gameEngine->getCardDoubleCount();
		this->numericUpDownCardChange->Value = this->gameEngine->getCardChangeCount();
	}

	void SettingsForm::resetGameSettings()
	{
		// Reset the game settings.
		this->gameEngine->resetGameSettings();
		this->loadGameSettings();

		// Display message.
		MessageBox::Show("Settings were reset!", "Game Settings", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	void SettingsForm::saveGameSettings()
	{
		// Set the virtual player speed.
		if (this->radioButtonSlow->Checked)
		{
			this->gameEngine->setVirtualPlayerSpeed(0);
		}
		if (this->radioButtonNormal->Checked)
		{
			this->gameEngine->setVirtualPlayerSpeed(1);
		}
		if (this->radioButtonFast->Checked)
		{
			this->gameEngine->setVirtualPlayerSpeed(2);
		}

		// Set the theme colour.
		if (this->radioButtonBlack->Checked)
		{
			this->gameEngine->setThemeColour("Black");
		}
		if (this->radioButtonRed->Checked)
		{
			this->gameEngine->setThemeColour("Red");
		}
		if (this->radioButtonGreen->Checked)
		{
			this->gameEngine->setThemeColour("Green");
		}
		if (this->radioButtonBlue->Checked)
		{
			this->gameEngine->setThemeColour("Blue");
		}

		// Set the number of cards in the card deck for each card type.
		this->gameEngine->setMinusCardCount(1, int(this->numericUpDownCardMinus1->Value));
		this->gameEngine->setMinusCardCount(2, int(this->numericUpDownCardMinus2->Value));
		this->gameEngine->setMinusCardCount(3, int(this->numericUpDownCardMinus3->Value));
		this->gameEngine->setMinusCardCount(4, int(this->numericUpDownCardMinus4->Value));
		this->gameEngine->setMinusCardCount(5, int(this->numericUpDownCardMinus5->Value));

		this->gameEngine->setPlusCardCount(1, int(this->numericUpDownCardPlus1->Value));
		this->gameEngine->setPlusCardCount(2, int(this->numericUpDownCardPlus2->Value));
		this->gameEngine->setPlusCardCount(3, int(this->numericUpDownCardPlus3->Value));
		this->gameEngine->setPlusCardCount(4, int(this->numericUpDownCardPlus4->Value));
		this->gameEngine->setPlusCardCount(5, int(this->numericUpDownCardPlus5->Value));

		this->gameEngine->setCardStealCount(int(this->numericUpDownCardSteal->Value));

		this->gameEngine->setCardDoubleCount(int(this->numericUpDownCardDouble->Value));
		this->gameEngine->setCardChangeCount(int(this->numericUpDownCardChange->Value));

		// Save the game settings.
		this->gameEngine->saveGameSettings();

		// Display message.
		MessageBox::Show("Settings were saved!", "Game Settings", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
