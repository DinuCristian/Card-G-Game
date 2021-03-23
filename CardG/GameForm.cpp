#include "GameForm.h"

namespace CardG {
	void GameForm::computeCardSize(double* cardWidth, double* cardHeight)
	{
		// Set card size:
		// - card width is 10% of the client form width.
		// - card height is 1.419 times the card width.
		*cardWidth = 0.1 * this->mainSplitContainer->Panel1->ClientSize.Width;
		*cardHeight = 1.419 * *cardWidth;

		// Adjust card size if the client form width is too large compared to the client form height.
		if (this->mainSplitContainer->Panel1->ClientSize.Width > 2 * this->mainSplitContainer->Panel1->ClientSize.Height)
		{
			*cardHeight = 0.3 * this->mainSplitContainer->Panel1->ClientSize.Height;
			*cardWidth = *cardHeight / 1.419;
		}
	}

	void GameForm::displayVirtualPlayerCards(double cardWidth, double cardHeight, bool create, bool newGame)
	{
		// Space between two cards.
		double space = 0.025 * this->mainSplitContainer->Panel1->ClientSize.Width;
		// Total width of all cards and spaces between them.
		double totalWidth = this->maxPlayerCardsCount * cardWidth + (this->maxPlayerCardsCount - 1) * space;

		// Set card location coordinates on the form.
		double x = 0.5 * (this->mainSplitContainer->Panel1->ClientSize.Width - totalWidth);
		double y = 0.10 * (this->mainSplitContainer->Panel1->ClientSize.Height - cardHeight);

		// Horizontal card location offset.
		double xOffset = cardWidth + space;

		// Create cards.
		System::ComponentModel::ComponentResourceManager^ resources;
		if (create) {
			this->pictureBoxVirtualPlayerCards = gcnew array<System::Windows::Forms::PictureBox^>(this->maxVirtualPlayerCardsCount);
			resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
		}

		// Loop through all the cards in the card set.
		for (int i = 0; i < this->maxVirtualPlayerCardsCount; i++)
		{
			// Create card i.
			if (create)
			{
				this->pictureBoxVirtualPlayerCards[i] = gcnew System::Windows::Forms::PictureBox();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxVirtualPlayerCards[i]))->BeginInit();
				this->pictureBoxVirtualPlayerCards[i]->Name = this->virtualPlayerCardNamePrefix + i.ToString();
				this->pictureBoxVirtualPlayerCards[i]->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
				this->pictureBoxVirtualPlayerCards[i]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				this->pictureBoxVirtualPlayerCards[i]->TabIndex = i;
				this->pictureBoxVirtualPlayerCards[i]->TabStop = false;
				this->pictureBoxVirtualPlayerCards[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle; // show placeholder
				this->pictureBoxVirtualPlayerCards[i]->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::pictureBoxVirtualPlayerCard_MouseClick);
				this->mainSplitContainer->Panel1->Controls->Add(this->pictureBoxVirtualPlayerCards[i]);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxVirtualPlayerCards[i]))->EndInit();
			}

			// A new game is started.
			if (newGame)
			{
				this->pictureBoxVirtualPlayerCards[i]->Image = nullptr;
				this->pictureBoxVirtualPlayerCards[i]->Enabled = true;
			}

			// Set card i location and size.
			this->pictureBoxVirtualPlayerCards[i]->Location = System::Drawing::Point(int(x + xOffset * i), int(y));
			this->pictureBoxVirtualPlayerCards[i]->Size = System::Drawing::Size(int(cardWidth), int(cardHeight));
		}
	}

	void GameForm::displayPlayedCards(double cardWidth, double cardHeight, bool create, bool newGame)
	{
		// Set card location coordinates on the form.
		double x = 0.1 * this->mainSplitContainer->Panel1->ClientSize.Width;
		double y = 0.5 * this->mainSplitContainer->Panel1->ClientSize.Height - cardHeight / 2;

		// Horizontal card location offset.
		double xOffset = cardWidth + (0.8 * this->mainSplitContainer->Panel1->ClientSize.Width - this->maxPlayedCardsCount * cardWidth) / (this->maxPlayedCardsCount - 1);

		// Create cards.
		System::ComponentModel::ComponentResourceManager^ resources;
		if (create) {
			this->pictureBoxPlayedCards = gcnew array<System::Windows::Forms::PictureBox^>(this->maxPlayedCardsCount);
			resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
		}

		// Loop through all the cards in the played cards.
		for (int i = 0; i < this->maxPlayedCardsCount; i++)
		{
			// Create card i.
			if (create)
			{
				this->pictureBoxPlayedCards[i] = gcnew System::Windows::Forms::PictureBox();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPlayedCards[i]))->BeginInit();
				this->pictureBoxPlayedCards[i]->Name = "";
				this->pictureBoxPlayedCards[i]->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
				this->pictureBoxPlayedCards[i]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				this->pictureBoxPlayedCards[i]->TabIndex = i;
				this->pictureBoxPlayedCards[i]->TabStop = false;
				this->mainSplitContainer->Panel1->Controls->Add(this->pictureBoxPlayedCards[i]);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPlayedCards[i]))->EndInit();
			}

			// A new game is started.
			if (newGame)
			{
				this->pictureBoxPlayedCards[i]->Image = nullptr;
				this->pictureBoxPlayedCards[i]->Name = "";
			}

			double currrentY = y;
			// Set card i location and size.
			if (this->pictureBoxPlayedCards[i]->Name->StartsWith(this->virtualPlayerCardNamePrefix)) {
				currrentY *= 0.9;
			}
			if (this->pictureBoxPlayedCards[i]->Name->StartsWith(this->playerCardNamePrefix)) {
				currrentY *= 1.1;
			}

			this->pictureBoxPlayedCards[i]->Location = System::Drawing::Point(int(x + xOffset * i), int(currrentY));
			this->pictureBoxPlayedCards[i]->Size = System::Drawing::Size(int(cardWidth), int(cardHeight));

			if (i < this->playedCardsCount)
			{
				this->pictureBoxPlayedCards[i]->BringToFront();
			}
		}
	}

	void GameForm::displayPlayerCards(double cardWidth, double cardHeight, bool create, bool newGame)
	{
		// Space between two cards.
		double space = 0.025 * this->mainSplitContainer->Panel1->ClientSize.Width;
		// Total width of all cards and spaces between them.
		double totalWidth = this->maxPlayerCardsCount * cardWidth + (this->maxPlayerCardsCount - 1) * space;

		// Set card location coordinates on the form.
		double x = 0.5 * (this->mainSplitContainer->Panel1->ClientSize.Width - totalWidth);
		double y = 0.90 * (this->mainSplitContainer->Panel1->ClientSize.Height - cardHeight);

		// Horizontal card location offset.
		double xOffset = cardWidth + space;

		// Create cards.
		System::ComponentModel::ComponentResourceManager^ resources;
		if (create) {
			this->pictureBoxPlayerCards = gcnew array<System::Windows::Forms::PictureBox^>(this->maxPlayerCardsCount);
			resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
		}

		// Loop through all the cards in the card set.
		for (int i = 0; i < this->maxPlayerCardsCount; i++)
		{
			// Create card i.
			if (create)
			{
				this->pictureBoxPlayerCards[i] = gcnew System::Windows::Forms::PictureBox();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPlayerCards[i]))->BeginInit();
				this->pictureBoxPlayerCards[i]->Name = this->playerCardNamePrefix + i.ToString();
				this->pictureBoxPlayerCards[i]->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
				this->pictureBoxPlayerCards[i]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				this->pictureBoxPlayerCards[i]->TabIndex = i;
				this->pictureBoxPlayerCards[i]->TabStop = false;
				this->pictureBoxPlayerCards[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle; // show placeholder
				this->pictureBoxPlayerCards[i]->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::pictureBoxPlayerCard_MouseClick);
				this->mainSplitContainer->Panel1->Controls->Add(this->pictureBoxPlayerCards[i]);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPlayerCards[i]))->EndInit();
			}

			// A new game is started.
			if (newGame)
			{
				this->pictureBoxPlayerCards[i]->Image = nullptr;
				this->pictureBoxPlayerCards[i]->Enabled = true;
			}

			// Set card i location and size.
			this->pictureBoxPlayerCards[i]->Location = System::Drawing::Point(int(x + xOffset * i), int(y));
			this->pictureBoxPlayerCards[i]->Size = System::Drawing::Size(int(cardWidth), int(cardHeight));
		}
	}

	void GameForm::onNewGame()
	{
		this->playerCardsCount = 0;
		this->playedCardsCount = 0;
		this->virtualPlayerCardsCount = 0;

		// Compute the card size.
		double cardWidth, cardHeight;
		computeCardSize(&cardWidth, &cardHeight);

		// Display the virtual player card set.
		displayVirtualPlayerCards(cardWidth, cardHeight, false, true);
		// Display the played cards.
		displayPlayedCards(cardWidth, cardHeight, false, true);
		// Display the player card set.
		displayPlayerCards(cardWidth, cardHeight, false, true);

		// Set the virtual player score.
		this->labelVirtualPlayerScore->Text = "0";
		// Set the player score.
		this->labelPlayerScore->Text = "0";
	}

	void GameForm::onPlayerSelectedCard(int cardIndex, String^ cardName) {
		// If the player did not select all cards.
		if (this->playerCardsCount < this->maxPlayerCardsCount)
		{
			// Update the game history.
			this->richTextBox->Text += this->gameEngine->getPlayerName() + " selected card " + (cardIndex + 1).ToString() + Environment::NewLine;
			this->richTextBox->Select(this->richTextBox->Text->Length, 0);

			// Show the face of the selected card in the player set of cards.
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
			this->pictureBoxPlayerCards[this->playerCardsCount]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(this->gameEngine->getThemeColour() + cardName)));

			// Increment the number of cards in the player set of cards.
			this->playerCardsCount += 1;
		}
	}

	void GameForm::onVirtualPlayerSelectedCard(int cardIndex, String^ cardName) {
		// If the virtual player did not select all cards.
		if (this->virtualPlayerCardsCount < this->maxVirtualPlayerCardsCount)
		{
			// Update the game history.
			this->richTextBox->Text += gameEngine->getVirtualPlayerName() + " selected card " + (cardIndex + 1).ToString() + Environment::NewLine;
			this->richTextBox->Select(this->richTextBox->Text->Length, 0);

			// Show the back of the selected card in the virtual player set of cards.
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
			this->pictureBoxVirtualPlayerCards[this->virtualPlayerCardsCount]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(this->gameEngine->getThemeColour() + "CardBack")));

			// Increment the number of cards in the virtual player set of cards.
			this->virtualPlayerCardsCount += 1;
		}
	}

	void GameForm::playerPlayedCard(int cardIndex, String^ cardName)
	{
		// Update the game history.
		this->richTextBox->Text += this->gameEngine->getPlayerName() + " played card " + (cardIndex + 1).ToString() + ": " + cardName + Environment::NewLine;
		this->richTextBox->Select(this->richTextBox->Text->Length, 0);

		// Disable the played card in the player card set of cards.
		this->pictureBoxPlayerCards[cardIndex]->Enabled = false;

		// Set the face and name of the played card on the player board.
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
		this->pictureBoxPlayedCards[this->playedCardsCount]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(this->gameEngine->getThemeColour() + cardName)));
		this->pictureBoxPlayedCards[this->playedCardsCount]->Name = this->playerCardNamePrefix + this->playedCardsCount.ToString();

		// Do not show the face of the played card in the player set of cards.
		this->pictureBoxPlayerCards[cardIndex]->Image = nullptr;

		// Compute and set the location of the played card.
		double x = this->pictureBoxPlayedCards[this->playedCardsCount]->Location.X;
		double y = 1.1 * this->pictureBoxPlayedCards[this->playedCardsCount]->Location.Y;
		this->pictureBoxPlayedCards[playedCardsCount]->Location = System::Drawing::Point(int(x), int(y));

		// Show the played card on the player board.
		this->pictureBoxPlayedCards[this->playedCardsCount]->Visible = true;
		this->pictureBoxPlayedCards[this->playedCardsCount]->BringToFront();

		// Increment the number of played cards.
		this->playedCardsCount += 1;

		// Decrement the number of cards in the player card set.
		this->playerCardsCount -= 1;
	}

	void GameForm::onPlayerPlayedCard(int cardIndex, String^ cardName) {
		// Update the form controls form in a thread-safe way.
		array<Object^>^ parameters = gcnew array<Object^>(2);
		parameters[0] = cardIndex;
		parameters[1] = cardName;
		this->BeginInvoke(gcnew playerPlayedCardDelegate(this, &GameForm::playerPlayedCard), parameters);
	}

	void GameForm::virtualPlayerPlayedCard(int cardIndex, String^ cardName)
	{
		// Update the game history.
		this->richTextBox->Text += gameEngine->getVirtualPlayerName() + " played card " + (cardIndex + 1).ToString() + ": " + cardName + Environment::NewLine;
		this->richTextBox->Select(this->richTextBox->Text->Length, 0);

		// Disable the played card in the player card set of cards.
		this->pictureBoxVirtualPlayerCards[cardIndex]->Enabled = false;

		// Set the face and name of the played card on the virtual player board.
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
		this->pictureBoxPlayedCards[this->playedCardsCount]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(this->gameEngine->getThemeColour() + cardName)));
		this->pictureBoxPlayedCards[this->playedCardsCount]->Name = this->virtualPlayerCardNamePrefix + this->playedCardsCount.ToString();

		// Do not show the back of the played card in the virtual player set of cards.
		this->pictureBoxVirtualPlayerCards[cardIndex]->Image = nullptr;

		// Compute and set the location of the played card.
		double x = this->pictureBoxPlayedCards[this->playedCardsCount]->Location.X;
		double y = 0.9 * this->pictureBoxPlayedCards[this->playedCardsCount]->Location.Y;
		this->pictureBoxPlayedCards[playedCardsCount]->Location = System::Drawing::Point(int(x), int(y));

		// Show the played card on the player board.
		this->pictureBoxPlayedCards[this->playedCardsCount]->Visible = true;
		this->pictureBoxPlayedCards[this->playedCardsCount]->BringToFront();

		// Increment the number of played cards.
		this->playedCardsCount += 1;

		// Decrement the number of cards in the virtual player card set.
		this->virtualPlayerCardsCount -= 1;
	}

	void GameForm::onVirtualPlayerPlayedCard(int cardIndex, String^ cardName) {
		// Update the form controls in a thread-safe way.
		array<Object^>^ parameters = gcnew array<Object^>(2);
		parameters[0] = cardIndex;
		parameters[1] = cardName;
		this->BeginInvoke(gcnew virtualPlayerPlayedCardDlegate(this, &GameForm::virtualPlayerPlayedCard), parameters);
	}

	void GameForm::scoreChanged(int virtualPlayerScore, int playerScore)
	{
		// Set the virtual player score.
		this->labelVirtualPlayerScore->Text = virtualPlayerScore.ToString();
		// Set the player score.
		this->labelPlayerScore->Text = playerScore.ToString();
	}

	void GameForm::onScoreChanged(int virtualPlayerScore, int playerScore) {
		// Update the form controls in a thread-safe way.
		array<Object^>^ parameters = gcnew array<Object^>(2);
		parameters[0] = virtualPlayerScore;
		parameters[1] = playerScore;
		this->BeginInvoke(gcnew scoreChangedDelegate(this, &GameForm::scoreChanged), parameters);
	}

	void GameForm::gameStateChanged(String^ state)
	{
		// Sets the game state.
		this->labelGameState->Text = state;
	}

	void GameForm::onGameStateChanged(String^ state) {
		// Update the form controls in a thread-safe way.
		array<Object^>^ parameters = gcnew array<Object^> { state };
		this->BeginInvoke(gcnew gameStateChangedDelegate(this, &GameForm::gameStateChanged), parameters);
	}

	void GameForm::gameFinished()
	{
		// Build a message; initially empty.
		String^ message = "";

		// Get the virtual player score.
		int virtualPlayerScore = this->gameEngine->getVirtualPlayerScore();
		// Get the player score.
		int playerScore = this->gameEngine->getPlayerScore();

		// Decide who win or if it is a draw. Add winner to the message.
		if (virtualPlayerScore > playerScore)
		{
			message += "You lost!";
		}
		else
		{
			if (virtualPlayerScore < playerScore)
			{
				message += "You won!";
			}
			else
			{
				message = "Draw!";
			}
		}

		// Add score to the message.
		message += Environment::NewLine + Environment::NewLine + "Score:";
		message += Environment::NewLine + " • " + this->gameEngine->getVirtualPlayerName() + ": " + virtualPlayerScore.ToString();
		message += Environment::NewLine + " • " + this->gameEngine->getPlayerName() + ": " + playerScore.ToString();

		// Show the message.
		MessageBox::Show(message, "Game finished", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	void GameForm::onGameFinished()
	{
		// Update the form controls in a thread-safe way.
		this->BeginInvoke(gcnew gameFinishedDelegate(this, &GameForm::gameFinished));
	}

	void GameForm::playerStealCard(int virtualPlayerCardIndex, int playerCardIndex, String^ cardName)
	{
		// Update the game history.
		this->richTextBox->Text += gameEngine->getPlayerName() + " stole card " + (virtualPlayerCardIndex + 1).ToString() + " (" + cardName + ") from " + gameEngine->getVirtualPlayerName() + Environment::NewLine;
		this->richTextBox->Select(this->richTextBox->Text->Length, 0);

		// Remove the stolen card from the virtual player card set and decrement the number of cards in the virtual player card set.
		this->pictureBoxVirtualPlayerCards[virtualPlayerCardIndex]->Enabled = false;
		this->pictureBoxVirtualPlayerCards[virtualPlayerCardIndex]->Image = nullptr;
		this->virtualPlayerCardsCount -= 1;

		// Add the stolen card to the player card set and increment the number of cards in the player card set.
		this->pictureBoxPlayerCards[playerCardIndex]->Enabled = true;
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
		this->pictureBoxPlayerCards[playerCardIndex]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(this->gameEngine->getThemeColour() + cardName)));
		this->pictureBoxPlayerCards[playerCardIndex]->Name = this->playerCardNamePrefix + playerCardIndex.ToString();
		this->playerCardsCount += 1;
	}

	void GameForm::onPlayerStoleCard(int virtualPlayerCardIndex, int playerCardIndex, String^ cardName)
	{
		// Update the form controls in a thread-safe way.
		array<Object^>^ parameters = gcnew array<Object^> { virtualPlayerCardIndex, playerCardIndex, cardName };
		this->BeginInvoke(gcnew playerStealCardDelegate(this, &GameForm::playerStealCard), parameters);
	}

	void GameForm::virtualPlayerStoleCard(int playerCardIndex, array<bool>^ virtualPlayerCards, String^ cardName)
	{
		// Update the game history.
		this->richTextBox->Text += gameEngine->getVirtualPlayerName() + " stole card " + (playerCardIndex + 1).ToString() + " (" + cardName + ") from " + gameEngine->getPlayerName() + Environment::NewLine;
		this->richTextBox->Select(this->richTextBox->Text->Length, 0);

		// Remove the stolen card from the player card set and decrement the number of cards in the player card set.
		this->pictureBoxPlayerCards[playerCardIndex]->Enabled = false;
		this->pictureBoxPlayerCards[playerCardIndex]->Image = nullptr;
		this->playerCardsCount -= 1;

		// Show the virtual player card set.
		this->virtualPlayerCardsCount = 0;
		// Loop through all the cards in the virtual player set of cards.
		for (int i = 0; i < this->maxVirtualPlayerCardsCount; i++)
		{
			if (virtualPlayerCards[i])
			{
				// Show the card and increment the number of cards in the player card set.
				this->pictureBoxVirtualPlayerCards[i]->Enabled = true;
				System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
				this->pictureBoxVirtualPlayerCards[i]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(this->gameEngine->getThemeColour() + "CardBack")));
				this->pictureBoxVirtualPlayerCards[i]->Name = this->virtualPlayerCardNamePrefix + i.ToString();
				this->virtualPlayerCardsCount += 1;
			}
			else
			{
				// No card at this position in the virtual player card set. Clear the previous card at this position in the virtual player card set.
				this->pictureBoxVirtualPlayerCards[i]->Enabled = false;
				this->pictureBoxVirtualPlayerCards[i]->Image = nullptr;
			}
		}
	}

	void GameForm::onVirtualPlayerStoleCard(int playerCardIndex, array<bool>^ virtualPlayerCards, String^ cardName)
	{
		// Update the form controls in a thread-safe way.
		array<Object^>^ parameters = gcnew array<Object^> { playerCardIndex, virtualPlayerCards, cardName };
		this->BeginInvoke(gcnew virtualPlayerStoleCardDelegate(this, &GameForm::virtualPlayerStoleCard), parameters);
	}
}
