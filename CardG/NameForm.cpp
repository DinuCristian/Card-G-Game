#include "NameForm.h"

namespace CardG {
	void NameForm::startGame()
	{
		// Gets the player name.
		String^ playerName = this->textBoxPlayerName->Text;
		// Return if the player name is empty or does not have at least one letter.
		if (String::IsNullOrEmpty(playerName) || !Regex::IsMatch(playerName, "[a-zA-Z]"))
		{
			return;
		}

		// Hide the current form.
		this->Hide();
		// Create a game form.
		CardG::GameForm^ form = (gcnew CardG::GameForm(playerName));
		// Show the game form.
		form->Show();
	}
}
