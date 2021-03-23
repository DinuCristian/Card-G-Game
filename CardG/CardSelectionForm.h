#pragma once

#include "GameEngine.h"

namespace CardG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CardSelectionForm
	/// </summary>
	public ref class CardSelectionForm : public System::Windows::Forms::Form
	{
	public:
		CardSelectionForm(GameEngine^ gameEngine)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToParent();

			this->gameEngine = gameEngine;
			this->maxDeckCardsCount = gameEngine->getCardDeckMaxCardsCount();
			this->maxPlayerCardsCount = gameEngine->getMaxPlayerCardsCount();

			this->cardNamePrefix = "Card";
			this->playerCardsCount = 0;

			this->previousCardIndex = 0;
			this->currentCardIndex = 0;
			this->nextCardIndex = 0;

			this->newCardIndex = -1;

			// Compute the card size.
			double cardWidth, cardHeight;
			computeCardSize(&cardWidth, &cardHeight);

			// Display the card deck and the player card set.
			this->displayCardDeck(cardWidth, cardHeight, true);
			this->displayPlayerCards(cardWidth, cardHeight, true);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CardSelectionForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		// The game engine.
		GameEngine^ gameEngine;


		// The card prefix name.
		String^ cardNamePrefix;


		// The maximum number of cards in the card deck.
		int maxDeckCardsCount;

		// The array of cards in the card deck. Each card is represented as a picture box control.
		array<System::Windows::Forms::PictureBox^>^ pictureBoxDeckCards;


		// The maximum number of cards in the player card set.
		int maxPlayerCardsCount;

		// The number of cards in the player card set.
		int playerCardsCount;
		
		// The array of cards in the player card set. Each card is represented as a picture box control.
		array<System::Windows::Forms::PictureBox^>^ pictureBoxPlayerCards;


		// The index of the previous card picture box control within the control collection.
		int previousCardIndex;
		
		// The index of the current card picture box control within the control collection.
		int currentCardIndex;
		
		// The index of the next card picture box control within the control collection.
		int nextCardIndex;


		// The index of the new card picture box control to enter after leaving the current picture box control.
		int newCardIndex;


		// The percentage used to increase/decrease the size of a picture box control when mouse enters/leaves that control.
		const double percentage = 0.5;

	private: System::Windows::Forms::StatusStrip^ statusStrip;
	private: System::Windows::Forms::ToolStripProgressBar^ toolStripProgressBar;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabelDeck;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabelCurrentCard;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabelEmpty;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabelPlayer;

		   /// <summary>
		   /// Required designer variable.
		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
			   this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			   this->toolStripStatusLabelDeck = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			   this->toolStripStatusLabelCurrentCard = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			   this->toolStripStatusLabelEmpty = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			   this->toolStripStatusLabelPlayer = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			   this->toolStripProgressBar = (gcnew System::Windows::Forms::ToolStripProgressBar());
			   this->statusStrip->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // statusStrip
			   // 
			   this->statusStrip->ImageScalingSize = System::Drawing::Size(32, 32);
			   this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				   this->toolStripStatusLabelDeck,
					   this->toolStripStatusLabelCurrentCard, this->toolStripStatusLabelEmpty, this->toolStripStatusLabelPlayer, this->toolStripProgressBar
			   });
			   this->statusStrip->Location = System::Drawing::Point(0, 283);
			   this->statusStrip->Name = L"statusStrip";
			   this->statusStrip->Size = System::Drawing::Size(574, 46);
			   this->statusStrip->TabIndex = 3;
			   this->statusStrip->Text = L"statusStrip";
			   // 
			   // toolStripStatusLabelDeck
			   // 
			   this->toolStripStatusLabelDeck->BorderSides = System::Windows::Forms::ToolStripStatusLabelBorderSides::Right;
			   this->toolStripStatusLabelDeck->BorderStyle = System::Windows::Forms::Border3DStyle::Etched;
			   this->toolStripStatusLabelDeck->Name = L"toolStripStatusLabelDeck";
			   this->toolStripStatusLabelDeck->Size = System::Drawing::Size(181, 36);
			   this->toolStripStatusLabelDeck->Text = L"Deck: 0/0 cards";
			   // 
			   // toolStripStatusLabelCurrentCard
			   // 
			   this->toolStripStatusLabelCurrentCard->BorderSides = System::Windows::Forms::ToolStripStatusLabelBorderSides::Right;
			   this->toolStripStatusLabelCurrentCard->BorderStyle = System::Windows::Forms::Border3DStyle::Etched;
			   this->toolStripStatusLabelCurrentCard->Name = L"toolStripStatusLabelCurrentCard";
			   this->toolStripStatusLabelCurrentCard->Size = System::Drawing::Size(260, 36);
			   this->toolStripStatusLabelCurrentCard->Text = L"Current card: 0/0 cards";
			   // 
			   // toolStripStatusLabelEmpty
			   // 
			   this->toolStripStatusLabelEmpty->Enabled = false;
			   this->toolStripStatusLabelEmpty->Name = L"toolStripStatusLabelEmpty";
			   this->toolStripStatusLabelEmpty->Size = System::Drawing::Size(118, 36);
			   this->toolStripStatusLabelEmpty->Spring = true;
			   this->toolStripStatusLabelEmpty->Text = L"Empty";
			   // 
			   // toolStripStatusLabelPlayer
			   // 
			   this->toolStripStatusLabelPlayer->BorderSides = System::Windows::Forms::ToolStripStatusLabelBorderSides::Left;
			   this->toolStripStatusLabelPlayer->BorderStyle = System::Windows::Forms::Border3DStyle::Etched;
			   this->toolStripStatusLabelPlayer->Name = L"toolStripStatusLabelPlayer";
			   this->toolStripStatusLabelPlayer->Size = System::Drawing::Size(192, 36);
			   this->toolStripStatusLabelPlayer->Text = L"Player: 0/0 cards";
			   // 
			   // toolStripProgressBar
			   // 
			   this->toolStripProgressBar->Name = L"toolStripProgressBar";
			   this->toolStripProgressBar->Size = System::Drawing::Size(100, 34);
			   // 
			   // CardSelectionForm
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->ClientSize = System::Drawing::Size(574, 329);
			   this->Controls->Add(this->statusStrip);
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->MinimumSize = System::Drawing::Size(500, 300);
			   this->Name = L"CardSelectionForm";
			   this->Text = L"Card-G - Card Selection";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CardSelectionForm::CardSelectionForm_FormClosing);
			   this->Resize += gcnew System::EventHandler(this, &CardSelectionForm::CardSelectionForm_Resize);
			   this->statusStrip->ResumeLayout(false);
			   this->statusStrip->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void pictureBox_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		// Get the index of the current card picture box control.
		System::Windows::Forms::PictureBox^ pictureBox = cli::safe_cast<System::Windows::Forms::PictureBox^>(sender);
		int pictureBoxIndex = int::Parse(pictureBox->Name->Substring(cardNamePrefix->Length));

		// If there is a new card to enter, then leave the previous card.
		if (this->newCardIndex != -1)
		{
			// Leave the previous card - begin.
			// Decrease and update the child index of the previous card. 
			if (newCardIndex > 0)
			{
				System::Windows::Forms::PictureBox^ previousPictureBox = this->pictureBoxDeckCards[newCardIndex - 1];
				this->decreaseNeighbourPictureBox(previousPictureBox);
				previousPictureBox->Parent->Controls->SetChildIndex(previousPictureBox, previousCardIndex);
			}

			// Decrease and update the child index of the current card. 
			System::Windows::Forms::PictureBox^ newCardPictureBox = this->pictureBoxDeckCards[newCardIndex];
			this->decreaseCurrentPictureBox(newCardPictureBox);
			newCardPictureBox->Parent->Controls->SetChildIndex(newCardPictureBox, currentCardIndex);

			// Decrease and update the child index of the next card. 
			if (newCardIndex + 1 < this->maxDeckCardsCount)
			{
				System::Windows::Forms::PictureBox^ nextPictureBox = this->pictureBoxDeckCards[newCardIndex + 1];
				this->decreaseNeighbourPictureBox(nextPictureBox);
				nextPictureBox->Parent->Controls->SetChildIndex(nextPictureBox, nextCardIndex);
			}
			// Leave the previous card - end.
		}

		// Enter the new card - begin.
		// Increase and save the child index of the previous card. 
		previousCardIndex = 0;
		if (pictureBoxIndex > 0)
		{
			System::Windows::Forms::PictureBox^ previousPictureBox = this->pictureBoxDeckCards[pictureBoxIndex - 1];
			this->increaseNeighbourPictureBox(previousPictureBox);
			previousCardIndex = previousPictureBox->Parent->Controls->GetChildIndex(previousPictureBox);
		}

		// Increase and save the child index of the current card. 
		this->increaseCurrentPictureBox(pictureBox);
		currentCardIndex = pictureBox->Parent->Controls->GetChildIndex(pictureBox);

		// Increase and save the child index of the next card. 
		nextCardIndex = 0;
		if (pictureBoxIndex + 1 < this->maxDeckCardsCount)
		{
			System::Windows::Forms::PictureBox^ nextPictureBox = this->pictureBoxDeckCards[pictureBoxIndex + 1];
			this->increaseNeighbourPictureBox(nextPictureBox);
			nextCardIndex = nextPictureBox->Parent->Controls->GetChildIndex(nextPictureBox);
		}

		// Bring to front the previous card.
		if (pictureBoxIndex > 0)
		{
			this->pictureBoxDeckCards[pictureBoxIndex - 1]->BringToFront();
		}
		// Bring to front the next card.
		if (pictureBoxIndex + 1 < this->maxDeckCardsCount)
		{
			this->pictureBoxDeckCards[pictureBoxIndex + 1]->BringToFront();
		}
		// Bring to front the current card.
		pictureBox->BringToFront();
		// Enter the new card - begin.

		// Update the tool strip status information.
		this->toolStripStatusLabelCurrentCard->Text = "Current card: " + (pictureBoxIndex + 1).ToString() + "/" + maxDeckCardsCount.ToString();
	}

	private: System::Void pictureBox_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		// Update the tool strip status information.
		this->toolStripStatusLabelCurrentCard->Text = "Current card: NA/" + maxDeckCardsCount.ToString();

		// Get the index of the current card picture box control.
		System::Windows::Forms::PictureBox^ pictureBox = cli::safe_cast<System::Windows::Forms::PictureBox^>(sender);
		int pictureBoxIndex = int::Parse(pictureBox->Name->Substring(cardNamePrefix->Length));
		
		// Compute the index of the new card to enter after leaving the current card in the card deck.
		this->computeNewCardIndex(pictureBoxIndex);

		// Leave the current card - begin.
		// Decrease and update the child index of the previous card. 
		if (pictureBoxIndex > 0)
		{
			System::Windows::Forms::PictureBox^ previousPictureBox = this->pictureBoxDeckCards[pictureBoxIndex - 1];
			this->decreaseNeighbourPictureBox(previousPictureBox);
			previousPictureBox->Parent->Controls->SetChildIndex(previousPictureBox, previousCardIndex);
		}

		// Decrease and update the child index of the current card. 
		this->decreaseCurrentPictureBox(pictureBox);
		pictureBox->Parent->Controls->SetChildIndex(pictureBox, currentCardIndex);

		// Decrease and update the child index of the next card. 
		if (pictureBoxIndex + 1 < this->maxDeckCardsCount)
		{
			System::Windows::Forms::PictureBox^ nextPictureBox = this->pictureBoxDeckCards[pictureBoxIndex + 1];
			this->decreaseNeighbourPictureBox(nextPictureBox);
			nextPictureBox->Parent->Controls->SetChildIndex(nextPictureBox, nextCardIndex);
		}
		// Leave the current card - end.

		// Return if do not enter previous or next card
		if (this->newCardIndex == -1)
		{
			return;
		}

		// Enter the previous or next card - begin.
		// Check if the new card is the previous or next card.
		if (this->newCardIndex == pictureBoxIndex - 1 || this->newCardIndex == pictureBoxIndex + 1) {
			// Increase and save the child index of the previous card. 
			previousCardIndex = 0;
			if (this->newCardIndex > 0)
			{
				System::Windows::Forms::PictureBox^ previousPictureBox = this->pictureBoxDeckCards[this->newCardIndex - 1];
				this->increaseNeighbourPictureBox(previousPictureBox);
				previousCardIndex = previousPictureBox->Parent->Controls->GetChildIndex(previousPictureBox);
			}

			// Increase and save the child index of the current card.
			System::Windows::Forms::PictureBox^ newPictureBox = this->pictureBoxDeckCards[this->newCardIndex];
			this->increaseCurrentPictureBox(newPictureBox);
			currentCardIndex = newPictureBox->Parent->Controls->GetChildIndex(newPictureBox);

			// Increase and save the child index of the next card.
			nextCardIndex = 0;
			if (this->newCardIndex + 1 < this->maxDeckCardsCount)
			{
				System::Windows::Forms::PictureBox^ nextPictureBox = this->pictureBoxDeckCards[this->newCardIndex + 1];
				this->increaseNeighbourPictureBox(nextPictureBox);
				nextCardIndex = nextPictureBox->Parent->Controls->GetChildIndex(nextPictureBox);
			}

			// Bring to front the previous card.
			if (this->newCardIndex > 0)
			{
				this->pictureBoxDeckCards[this->newCardIndex - 1]->BringToFront();
			}
			// Bring to front the next card.
			if (this->newCardIndex + 1 < this->maxDeckCardsCount)
			{
				this->pictureBoxDeckCards[this->newCardIndex + 1]->BringToFront();
			}
			// Bring to front the current card.
			this->pictureBoxDeckCards[this->newCardIndex]->BringToFront();
		}
		// Enter the previous or next card - end.
	}

	private: System::Void pictureBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Return if the player selected all cards or this event is not a left click.
		if (this->playerCardsCount >= this->maxPlayerCardsCount || e->Button != System::Windows::Forms::MouseButtons::Left)
		{
			return;
		}

		// Increment the progress bar.
		this->toolStripProgressBar->Value = this->playerCardsCount + 1;

		// Get the selected card index.
		System::Windows::Forms::PictureBox^ pictureBox = cli::safe_cast<System::Windows::Forms::PictureBox^>(sender);
		int pictureBoxIndex = int::Parse(pictureBox->Name->Substring(this->cardNamePrefix->Length));

		// Add the selected card to the player card set and get back its name.
		String^ cardName = this->gameEngine->addPlayerCard(pictureBoxIndex);

		// Hide the selected card from the deck.
		this->pictureBoxDeckCards[pictureBoxIndex]->Visible = false;

		// Get the selected card face and display it in the player card set.
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
		this->pictureBoxPlayerCards[this->playerCardsCount]->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(this->gameEngine->getThemeColour() + cardName)));;

		// Set the selected card name in the player card set.
		this->pictureBoxPlayerCards[this->playerCardsCount]->Name = this->pictureBoxDeckCards[pictureBoxIndex]->Name;

		// Increment the number of cards in the player card set.
		this->playerCardsCount += 1;

		// Update the tool strip status.
		this->toolStripStatusLabelDeck->Text = "Deck: " + (this->maxDeckCardsCount - this->playerCardsCount).ToString() + "/" + this->maxDeckCardsCount.ToString() + " cards";
		this->toolStripStatusLabelPlayer->Text = "Player: " + this->playerCardsCount.ToString() + "/" + this->maxPlayerCardsCount.ToString() + " cards";

		// Show a meesage and then close this form if the player selected all cards.
		if (this->playerCardsCount == this->maxPlayerCardsCount)
		{
			MessageBox::Show("You selected your cards." + Environment::NewLine + "The game will start shortly." + Environment::NewLine + "Good luck!", "Good luck!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}
	}

	private: System::Void CardSelectionForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		// Compute the card size.
		double cardWidth, cardHeight;
		computeCardSize(&cardWidth, &cardHeight);

		// Display the card deck and the player card set.
		this->displayCardDeck(cardWidth, cardHeight, false);
		this->displayPlayerCards(cardWidth, cardHeight, false);
	}

	private: System::Void CardSelectionForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		// Return if the player selected all cards.
		if (this->playerCardsCount == this->maxPlayerCardsCount)
		{
			return;
		}
		
		// Show a message and ask the user if they want to continue with card selection.
		System::Windows::Forms::DialogResult dialogResult = MessageBox::Show("You must select 5 cards to start a game." + Environment::NewLine + "Do you want to continue?", "Card selection", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (dialogResult == System::Windows::Forms::DialogResult::Yes)
		{
			// Cancel the form closing event when user wants to continue with card selection.
			e->Cancel = true;
		}
		else
		{
			// Cancel the new game that was about to start and exit this form when user doesn't want to continue with card selection.
			this->gameEngine->newGame(true);
		}
	}

	private:
		// Computes the size of a card based on the size of the client area of the form.
		//   cardWidth: The card width.
		//   cardHeight: The card height.
		void computeCardSize(double* cardWidth, double* cardHeight);

		// Displays the card deck.
		//   cardWidth: The card width.
		//   cardHeight: The card height.
		//   create: Indicates whether the controls should be created.
		void displayCardDeck(double cardWidth, double cardHeight, bool create);

		// Displays the player card set.
		//   cardWidth: The card width.
		//   cardHeight: The card height.
		//   create: Indicates whether the controls should be created.
		void displayPlayerCards(double cardWidth, double cardHeight, bool create);

		// Computes the index of the new card to enter after leaving the current card in the card deck.
		//   pictureBoxIndex: The index of the current card picture box control in the card deck.
		void computeNewCardIndex(int pictureBoxIndex);

		// Increases the current picture box control size.
		//   pictureBox: The picture box control whose size to increase.
		void increaseCurrentPictureBox(PictureBox^ pictureBox);

		// Increases the neighbour picture box control size.
		//   pictureBox: The picture box control whose size to increase.
		void increaseNeighbourPictureBox(PictureBox^ pictureBox);

		// Decreases the current picture box control size.
		//   pictureBox: The picture box control whose size to decrease.
		void decreaseCurrentPictureBox(PictureBox^ pictureBox);

		// Decreases the neighbour picture box control size.
		//   pictureBox: The picture box control whose size to decrease.
		void decreaseNeighbourPictureBox(PictureBox^ pictureBox);
	};
}

