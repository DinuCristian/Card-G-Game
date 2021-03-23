#include "RulesForm.h"

namespace CardG {
	void RulesForm::displayRules()
	{
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
		this->pictureBoxMinusCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(this->gameEngine->getThemeColour() + "CardMinus1")));
		this->pictureBoxPlusCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(this->gameEngine->getThemeColour() + "CardPlus1")));
		this->pictureBoxStealCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(this->gameEngine->getThemeColour() + "CardSteal")));
		this->pictureBoxDoubleCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(this->gameEngine->getThemeColour() + "CardDouble")));
		this->pictureBoxChangeCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(this->gameEngine->getThemeColour() + "CardChange")));


		// Description
		this->richTextBoxDescription->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxDescription->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxDescription->SelectedText = "Description: ";

		this->richTextBoxDescription->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxDescription->SelectedText = "This is a turn-based card game that you can play against a virtual player (Neo). "
			"It consists of two phases:" + Environment::NewLine;

		this->richTextBoxDescription->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxDescription->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxDescription->SelectedText = "    1. Card selection. ";

		this->richTextBoxDescription->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxDescription->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxDescription->SelectedText = "First, you select 5 cards from the card deck. "
			"Then, the virtual player (Neo) selects 5 cards from the deck." + Environment::NewLine;

		this->richTextBoxDescription->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxDescription->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxDescription->SelectedText = "    2. Game play. ";

		this->richTextBoxDescription->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxDescription->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxDescription->SelectedText = "The virtual player (Neo) starts the game by playing a card. "
			"Then, you can play a card from your set. The power score is updated according to the card played. "
			"The game continues until you and the virtual player (Neo) have no more cards to play." + Environment::NewLine;

		this->richTextBoxDescription->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxDescription->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxDescription->SelectedText = "Goal: ";

		this->richTextBoxDescription->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxDescription->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxDescription->SelectedText = "The player with the highest power score wins.";


		// Card Minus
		this->richTextBoxCardMinus->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardMinus->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardMinus->SelectedText = "Card Type: ";

		this->richTextBoxCardMinus->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardMinus->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardMinus->SelectedText = "Power-" + Environment::NewLine;

		this->richTextBoxCardMinus->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardMinus->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardMinus->SelectedText = "Power Value: ";

		this->richTextBoxCardMinus->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardMinus->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardMinus->SelectedText = "1 to 5" + Environment::NewLine;

		this->richTextBoxCardMinus->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardMinus->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardMinus->SelectedText = "Effect: ";

		this->richTextBoxCardMinus->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardMinus->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardMinus->SelectedText = "The power score of the opponent is decreased by the power value of the card.";


		// Card Plus
		this->richTextBoxCardPlus->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardPlus->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardPlus->SelectedText = "Card Type: ";

		this->richTextBoxCardPlus->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardPlus->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardPlus->SelectedText = "Power+" + Environment::NewLine;

		this->richTextBoxCardPlus->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardPlus->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardPlus->SelectedText = "Power Value: ";

		this->richTextBoxCardPlus->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardPlus->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardPlus->SelectedText = "1 to 5" + Environment::NewLine;

		this->richTextBoxCardPlus->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardPlus->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardPlus->SelectedText = "Effect: ";

		this->richTextBoxCardPlus->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardPlus->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardPlus->SelectedText = "The power score of the player is increased by the power value of the card.";


		// Card Steal
		this->richTextBoxCardSteal->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardSteal->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardSteal->SelectedText = "Card Type: ";

		this->richTextBoxCardSteal->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardSteal->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardSteal->SelectedText = "Steal" + Environment::NewLine;

		this->richTextBoxCardSteal->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardSteal->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardSteal->SelectedText = "Power Value: ";

		this->richTextBoxCardSteal->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardSteal->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardSteal->SelectedText = "1" + Environment::NewLine;

		this->richTextBoxCardSteal->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardSteal->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardSteal->SelectedText = "Effect: ";

		this->richTextBoxCardSteal->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardSteal->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardSteal->SelectedText = "The player can select a card to get from the opponent's set. "
			"If the opponent's set is empty, this card is equivalent to a Power+ card with a power value of 1.";


		// Card Double
		this->richTextBoxCardDouble->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardDouble->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardDouble->SelectedText = "Card Type: ";

		this->richTextBoxCardDouble->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardDouble->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardDouble->SelectedText = "Double" + Environment::NewLine;

		this->richTextBoxCardDouble->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardDouble->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardDouble->SelectedText = "Power Value: ";

		this->richTextBoxCardDouble->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardDouble->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardDouble->SelectedText = "2" + Environment::NewLine;

		this->richTextBoxCardDouble->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardDouble->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardDouble->SelectedText = "Effect: ";

		this->richTextBoxCardDouble->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardDouble->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardDouble->SelectedText = "The power score of the player is doubled.";


		// Card Change
		this->richTextBoxCardChange->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardChange->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardChange->SelectedText = "Card Type: ";

		this->richTextBoxCardChange->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardChange->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardChange->SelectedText = "Change" + Environment::NewLine;

		this->richTextBoxCardChange->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardChange->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardChange->SelectedText = "Power Value: ";

		this->richTextBoxCardChange->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardChange->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardChange->SelectedText = "3" + Environment::NewLine;

		this->richTextBoxCardChange->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardChange->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Bold);
		this->richTextBoxCardChange->SelectedText = "Effect: ";

		this->richTextBoxCardChange->SelectionColor = System::Drawing::Color::Black;
		this->richTextBoxCardChange->SelectionFont = gcnew System::Drawing::Font(this->richTextBoxCardMinus->Font, FontStyle::Regular);
		this->richTextBoxCardChange->SelectedText = "This cards changes the effect of the last card played by the opponent. "
			"More precisely, the last card played by the opponent is interpreted as a card played by the player who plays the Change card. "
			"If the opponent didn't play a card, this card has the same effect as when the last card played by the opponent is a Power+ card with a power value of 3. "
			"If the last card played by the opponent is a Steal or Change card, it is interpreted as a Power+ card with a power value of 3.";
	}
}
