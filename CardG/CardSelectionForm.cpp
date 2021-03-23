#include "CardSelectionForm.h"

namespace CardG {
	void CardSelectionForm::computeCardSize(double* cardWidth, double* cardHeight)
	{
		// Set card size:
		// - card width is 10% of the client form width.
		// - card height is 1.419 times the card width.
		*cardWidth = 0.1 * this->ClientSize.Width;
		*cardHeight = 1.419 * *cardWidth;

		// Adjust card size if the client form width is too large compared to the client form height.
		if (this->ClientSize.Width > 2 * this->ClientSize.Height)
		{
			*cardHeight = 0.3 * this->ClientSize.Height;
			*cardWidth = *cardHeight / 1.419;
		}
	}

	void CardSelectionForm::displayCardDeck(double cardWidth, double cardHeight, bool create)
	{
		// Set card location coordinates on the form.
		double x = 0.05 * this->ClientSize.Width;
		double y = 0.15 * (this->ClientSize.Height - cardHeight);

		// Horizontal card location offset.
		double xOffset = cardWidth + (0.9 * this->ClientSize.Width - this->maxDeckCardsCount * cardWidth) / (this->maxDeckCardsCount - 1);

		// Create cards.
		System::ComponentModel::ComponentResourceManager^ resources;
		if (create) {
			this->pictureBoxDeckCards = gcnew array<System::Windows::Forms::PictureBox^>(this->maxDeckCardsCount);
			resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
		}

		// Loop through all the cards in the card deck.
		for (int i = 0; i < this->maxDeckCardsCount; i++)
		{
			// Create card i.
			if (create) {
				this->pictureBoxDeckCards[i] = gcnew System::Windows::Forms::PictureBox();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDeckCards[i]))->BeginInit();
				this->pictureBoxDeckCards[i]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(this->gameEngine->getThemeColour() + "CardBack")));
				this->pictureBoxDeckCards[i]->Name = this->cardNamePrefix + i.ToString();
				this->pictureBoxDeckCards[i]->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
				this->pictureBoxDeckCards[i]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				this->pictureBoxDeckCards[i]->TabIndex = i;
				this->pictureBoxDeckCards[i]->TabStop = false;
				this->pictureBoxDeckCards[i]->MouseEnter += gcnew System::EventHandler(this, &CardSelectionForm::pictureBox_MouseEnter);
				this->pictureBoxDeckCards[i]->MouseLeave += gcnew System::EventHandler(this, &CardSelectionForm::pictureBox_MouseLeave);
				this->pictureBoxDeckCards[i]->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &CardSelectionForm::pictureBox_MouseClick);
				this->Controls->Add(this->pictureBoxDeckCards[i]);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDeckCards[i]))->EndInit();
			}

			// Set card i location and size.
			this->pictureBoxDeckCards[i]->Location = System::Drawing::Point(int(x + xOffset * i), int(y));
			this->pictureBoxDeckCards[i]->Size = System::Drawing::Size(int(cardWidth), int(cardHeight));
			this->pictureBoxDeckCards[i]->BringToFront();
		}

		// Set the status bar information.
		if (create)
		{
			this->toolStripStatusLabelDeck->Text = "Deck: " + this->maxDeckCardsCount.ToString() + "/" + this->maxDeckCardsCount.ToString() + " cards";
			this->toolStripStatusLabelEmpty->Text = "";
			this->toolStripStatusLabelPlayer->Text = "Player: 0/" + this->maxPlayerCardsCount.ToString() + " cards";
			this->toolStripProgressBar->Maximum = this->maxPlayerCardsCount;
		}
	}

	void CardSelectionForm::displayPlayerCards(double cardWidth, double cardHeight, bool create)
	{
		// Space between two cards.
		double space = 0.025 * this->ClientSize.Width;
		// Total width of all cards and spaces between them
		double totalWidth = this->maxPlayerCardsCount * cardWidth + (this->maxPlayerCardsCount - 1) * space;

		// Set card location coordinates on the form.
		double x = 0.5 * (this->ClientSize.Width - totalWidth);
		double y = 0.75 * (this->ClientSize.Height - cardHeight);

		// Horizontal card location offset.
		double xOffset = cardWidth + space;

		// Create cards.
		System::ComponentModel::ComponentResourceManager^ resources;
		if (create) {
			this->pictureBoxPlayerCards = gcnew array<System::Windows::Forms::PictureBox^>(this->maxPlayerCardsCount);
			resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
		}

		// Loop through all the cards in the player card set.
		for (int i = 0; i < this->maxPlayerCardsCount; i++)
		{
			// Create card i.
			if (create)
			{
				this->pictureBoxPlayerCards[i] = gcnew System::Windows::Forms::PictureBox();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPlayerCards[i]))->BeginInit();
				this->pictureBoxPlayerCards[i]->Name = "";
				this->pictureBoxPlayerCards[i]->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
				this->pictureBoxPlayerCards[i]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				this->pictureBoxPlayerCards[i]->TabIndex = i;
				this->pictureBoxPlayerCards[i]->TabStop = false;
				this->pictureBoxPlayerCards[i]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle; // show placeholder
				this->Controls->Add(this->pictureBoxPlayerCards[i]);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPlayerCards[i]))->EndInit();
			}

			// Set card i location and size.
			this->pictureBoxPlayerCards[i]->Location = System::Drawing::Point(int(x + xOffset * i), int(y));
			this->pictureBoxPlayerCards[i]->Size = System::Drawing::Size(int(cardWidth), int(cardHeight));
		}
	}

	void CardSelectionForm::computeNewCardIndex(int pictureBoxIndex)
	{
		// Initially, the index of the new card is set to -1. This means there is no new card to enter after leaving the current card.
		this->newCardIndex = -1;
		// Get the card picture box control.
		System::Windows::Forms::PictureBox^ pictureBox = this->pictureBoxDeckCards[pictureBoxIndex];

		// If this card picture box control in not the first one.
		if (pictureBoxIndex - 1 > 0) {
			// Get the previous card picture box control.
			System::Windows::Forms::PictureBox^ previousPictureBox = this->pictureBoxDeckCards[pictureBoxIndex - 1];
			// Get the cursor position.
			Point cursorPosition = this->PointToClient(Cursor->Position);

			// Determine if the cursor position is in the rectangular area of the previous card.
			if ((cursorPosition.X - 1 <= pictureBox->Location.X) &&
				(cursorPosition.X >= previousPictureBox->Location.X) &&
				(cursorPosition.Y >= previousPictureBox->Location.Y) &&
				(cursorPosition.Y <= previousPictureBox->Location.Y + previousPictureBox->Size.Height))
			{
				// Set the new card index to the previous card index.
				this->newCardIndex = pictureBoxIndex - 1;
				return;
			}
		}

		// If this card picture box control in not the last one.
		if (pictureBoxIndex + 1 < this->maxDeckCardsCount) {
			// Get the next card picture box control.
			System::Windows::Forms::PictureBox^ nextPictureBox = this->pictureBoxDeckCards[pictureBoxIndex + 1];
			// Get the cursor position.
			Point cursorPosition = this->PointToClient(Cursor->Position);

			// Determine if the cursor position is in the rectangular area of the next card.
			if ((cursorPosition.X + 1 >= pictureBox->Location.X + pictureBox->Size.Width) &&
				(cursorPosition.X <= nextPictureBox->Location.X + nextPictureBox->Size.Width) &&
				(cursorPosition.Y >= nextPictureBox->Location.Y) &&
				(cursorPosition.Y <= nextPictureBox->Location.Y + nextPictureBox->Size.Height))
			{
				// Set the new card index to the next card index.
				this->newCardIndex = pictureBoxIndex + 1;
				return;
			}
		}
	}

	void CardSelectionForm::increaseCurrentPictureBox(PictureBox^ pictureBox)
	{
		// Compute the new location (x, y).
		double x = pictureBox->Location.X - pictureBox->Size.Width * this->percentage / 2;
		double y = pictureBox->Location.Y - pictureBox->Size.Height * this->percentage / 2;
		// Compute the new size (width, height).
		double width = pictureBox->Size.Width * (1 + this->percentage);
		double height = pictureBox->Size.Height * (1 + this->percentage);

		// Set the new location and size.
		pictureBox->Location = System::Drawing::Point(int(x), int(y));
		pictureBox->Size = System::Drawing::Size(int(width), int(height));
	}

	void CardSelectionForm::increaseNeighbourPictureBox(PictureBox^ pictureBox)
	{
		// Compute the new location (x, y).
		double x = pictureBox->Location.X - pictureBox->Size.Width * this->percentage / 4;
		double y = pictureBox->Location.Y - pictureBox->Size.Height * this->percentage / 4;
		// Compute the new size (width, height).
		double width = pictureBox->Size.Width * (1 + this->percentage / 2);
		double height = pictureBox->Size.Height * (1 + this->percentage / 2);

		// Set the new location and size.
		pictureBox->Location = System::Drawing::Point(int(x), int(y));
		pictureBox->Size = System::Drawing::Size(int(width), int(height));
	}

	void CardSelectionForm::decreaseCurrentPictureBox(PictureBox^ pictureBox)
	{
		// Get the current card picture box control index.
		int pictureBoxIndex = int::Parse(pictureBox->Name->Substring(cardNamePrefix->Length));

		// Get the y coordinate of the first card location.
		double y = this->pictureBoxDeckCards[0]->Location.Y;
		// Get the first card size (width, height).
		double height = this->pictureBoxDeckCards[0]->Size.Height;
		double width = this->pictureBoxDeckCards[0]->Size.Width;

		// If this card is in the first half of the card deck, update the y coordinate of the card location and the card size (width, height) from those of the last card in the deck.
		if (pictureBoxIndex < this->maxDeckCardsCount / 2)
		{
			y = this->pictureBoxDeckCards[this->maxDeckCardsCount - 1]->Location.Y;
			width = this->pictureBoxDeckCards[this->maxDeckCardsCount - 1]->Size.Width;
			height = this->pictureBoxDeckCards[this->maxDeckCardsCount - 1]->Size.Height;
		}

		// Compute the x coordinate for card location.
		double x = pictureBox->Location.X + pictureBox->Size.Width * this->percentage / (2 * (1 + this->percentage));

		// Set the new location and size.
		pictureBox->Location = System::Drawing::Point(int(x), int(y));
		pictureBox->Size = System::Drawing::Size(int(width), int(height));
	}

	void CardSelectionForm::decreaseNeighbourPictureBox(PictureBox^ pictureBox)
	{
		// Get the current card picture box control index.
		int pictureBoxIndex = int::Parse(pictureBox->Name->Substring(cardNamePrefix->Length));

		// Get the y coordinate of the first card location.
		double y = this->pictureBoxDeckCards[0]->Location.Y;
		// Get the first card size (width, height).
		double width = this->pictureBoxDeckCards[0]->Size.Width;
		double height = this->pictureBoxDeckCards[0]->Size.Height;

		// If this card is in the first half of the card deck, update the y coordinate of the card location and the card size (width, height) from those of the last card in the deck.
		if (pictureBoxIndex < this->maxDeckCardsCount / 2)
		{
			y = this->pictureBoxDeckCards[this->maxDeckCardsCount - 1]->Location.Y;
			width = this->pictureBoxDeckCards[this->maxDeckCardsCount - 1]->Size.Width;
			height = this->pictureBoxDeckCards[this->maxDeckCardsCount - 1]->Size.Height;
		}

		// Compute the x coordinate for card location.
		double x = pictureBox->Location.X + pictureBox->Size.Width * this->percentage / (2 * (2 + this->percentage));

		// Set the new location and size.
		pictureBox->Location = System::Drawing::Point(int(x), int(y));
		pictureBox->Size = System::Drawing::Size(int(width), int(height));
	}
}
