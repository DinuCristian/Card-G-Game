#pragma once

#include "CardSelectionForm.h"
#include "SettingsForm.h"
#include "RulesForm.h"
#include "AboutForm.h"
#include "GameEngine.h"
#include "TestForm.h"

namespace CardG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(String^ playerName)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToScreen();

			this->gameEngine = gcnew GameEngine(playerName);
			this->gameEngine->onNewGame += gcnew GameEngine::newGameEventHandler(this, &CardG::GameForm::onNewGame);
			this->gameEngine->onPlayerSelectedCard += gcnew GameEngine::playerSelectedCardEventHandler(this, &CardG::GameForm::onPlayerSelectedCard);
			this->gameEngine->onVirtualPlayerSelectedCard += gcnew GameEngine::virtualPlayerSelectedCardEventHandler(this, &CardG::GameForm::onVirtualPlayerSelectedCard);
			this->gameEngine->onPlayerPlayedCard += gcnew GameEngine::playerPlayedCardEventHandler(this, &CardG::GameForm::onPlayerPlayedCard);
			this->gameEngine->onVirtualPlayerPlayedCard += gcnew GameEngine::virtualPlayerPlayedCardEventHandler(this, &CardG::GameForm::onVirtualPlayerPlayedCard);
			this->gameEngine->onScoreChanged += gcnew GameEngine::scoreChangedEventHandler(this, &CardG::GameForm::onScoreChanged);
			this->gameEngine->onGameStateChanged += gcnew GameEngine::gameStateChangedEventHandler(this, &CardG::GameForm::onGameStateChanged);
			this->gameEngine->onGameFinished += gcnew GameEngine::gameFinishedEventHandler(this, &CardG::GameForm::onGameFinished);
			this->gameEngine->onPlayerStoleCard += gcnew GameEngine::playerStoleCardEventHandler(this, &CardG::GameForm::onPlayerStoleCard);
			this->gameEngine->onVirtualPlayerStoleCard += gcnew GameEngine::virtualPlayerStoleCardEventHandler(this, &CardG::GameForm::onVirtualPlayerStoleCard);

			this->maxVirtualPlayerCardsCount = gameEngine->getMaxVirtualPlayerCardsCount();
			this->maxPlayerCardsCount = gameEngine->getMaxPlayerCardsCount();
			this->maxPlayedCardsCount = this->maxVirtualPlayerCardsCount + this->maxPlayerCardsCount;

			this->virtualPlayerCardsCount = 0;
			this->playedCardsCount = 0;
			this->playerCardsCount = 0;

			this->virtualPlayerCardNamePrefix = "VirtualPlayerCard";
			this->playerCardNamePrefix = "PlayerCard";

			this->labelVirtualPlayerName->Text = gameEngine->getVirtualPlayerName() + ":";
			this->labelPlayerName->Text = gameEngine->getPlayerName() + ":";

			// Compute the card size.
			double cardWidth, cardHeight;
			computeCardSize(&cardWidth, &cardHeight);

			// Display the virtual player card set.
			displayVirtualPlayerCards(cardWidth, cardHeight, true, true);
			// Display the played cards.
			displayPlayedCards(cardWidth, cardHeight, true, true);
			// Display the player card set.
			displayPlayerCards(cardWidth, cardHeight, true, true);

			this->mainSplitContainer->Panel1->Resize += gcnew System::EventHandler(this, &GameForm::mainSplitContainer_Panel1_Resize);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::StatusStrip^ statusStrip;
	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ newGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ rulesToolStripMenuItem;

	private: System::Windows::Forms::SplitContainer^ mainSplitContainer;
	private: System::Windows::Forms::SplitContainer^ historySplitContainer;
	private: System::Windows::Forms::RichTextBox^ richTextBox;

	private:
		// The game engine.
		GameEngine^ gameEngine;


		// The virtual player card name prefix.
		String^ virtualPlayerCardNamePrefix;
		
		// The player card name prefix.
		String^ playerCardNamePrefix;


		// The maximum number of cards in the virtual player set.
		int maxVirtualPlayerCardsCount;

		// The number of cards in the virtual player set.
		int virtualPlayerCardsCount;

		// The array of virtual player cards. Each card is represented as a picture box control.
		array<System::Windows::Forms::PictureBox^>^ pictureBoxVirtualPlayerCards;


		// The maximum number of played cards.
		int maxPlayedCardsCount;

		// The number of played cards.
		int playedCardsCount;

		// The array of played cards. Each card is represented as a picture box control.
		array<System::Windows::Forms::PictureBox^>^ pictureBoxPlayedCards;


		// The maximum number of cards in the player set.
		int maxPlayerCardsCount;

		// The number of cards in the player set.
		int playerCardsCount;

		// The array of player cards. Each card is represented as a picture box control.
		array<System::Windows::Forms::PictureBox^>^ pictureBoxPlayerCards;


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel;
	private: System::Windows::Forms::Label^ labelVirtualPlayerName;
	private: System::Windows::Forms::Label^ labelVirtualPlayerScore;

	private: System::Windows::Forms::Label^ labelPlayerName;
	private: System::Windows::Forms::Label^ labelPlayerScore;
	private: System::Windows::Forms::Label^ labelGameTurn;

	private: System::Windows::Forms::Label^ labelGameState;

	private: System::Windows::Forms::PictureBox^ pictureBoxSplitter;
	private: System::Windows::Forms::Label^ labelHistory;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;

	private:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->newGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rulesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mainSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->historySplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelVirtualPlayerName = (gcnew System::Windows::Forms::Label());
			this->pictureBoxSplitter = (gcnew System::Windows::Forms::PictureBox());
			this->labelHistory = (gcnew System::Windows::Forms::Label());
			this->labelVirtualPlayerScore = (gcnew System::Windows::Forms::Label());
			this->labelPlayerName = (gcnew System::Windows::Forms::Label());
			this->labelPlayerScore = (gcnew System::Windows::Forms::Label());
			this->labelGameTurn = (gcnew System::Windows::Forms::Label());
			this->labelGameState = (gcnew System::Windows::Forms::Label());
			this->richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainSplitContainer))->BeginInit();
			this->mainSplitContainer->Panel2->SuspendLayout();
			this->mainSplitContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->historySplitContainer))->BeginInit();
			this->historySplitContainer->Panel1->SuspendLayout();
			this->historySplitContainer->Panel2->SuspendLayout();
			this->historySplitContainer->SuspendLayout();
			this->tableLayoutPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSplitter))->BeginInit();
			this->SuspendLayout();
			// 
			// statusStrip
			// 
			this->statusStrip->ImageScalingSize = System::Drawing::Size(32, 32);
			this->statusStrip->Location = System::Drawing::Point(0, 507);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(774, 22);
			this->statusStrip->TabIndex = 0;
			this->statusStrip->Text = L"statusStrip1";
			// 
			// menuStrip
			// 
			this->menuStrip->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->newGameToolStripMenuItem,
					this->settingsToolStripMenuItem, this->rulesToolStripMenuItem, this->aboutToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(774, 40);
			this->menuStrip->TabIndex = 1;
			this->menuStrip->Text = L"menuStrip";
			// 
			// newGameToolStripMenuItem
			// 
			this->newGameToolStripMenuItem->Name = L"newGameToolStripMenuItem";
			this->newGameToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->newGameToolStripMenuItem->Size = System::Drawing::Size(152, 36);
			this->newGameToolStripMenuItem->Text = L"&New Game";
			this->newGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::newGameToolStripMenuItem_Click);
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(121, 36);
			this->settingsToolStripMenuItem->Text = L"&Settings";
			this->settingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::settingsToolStripMenuItem_Click);
			// 
			// rulesToolStripMenuItem
			// 
			this->rulesToolStripMenuItem->Name = L"rulesToolStripMenuItem";
			this->rulesToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::R));
			this->rulesToolStripMenuItem->Size = System::Drawing::Size(92, 36);
			this->rulesToolStripMenuItem->Text = L"&Rules";
			this->rulesToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::rulesToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(100, 36);
			this->aboutToolStripMenuItem->Text = L"&About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::aboutToolStripMenuItem_Click);
			// 
			// mainSplitContainer
			// 
			this->mainSplitContainer->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->mainSplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainSplitContainer->Location = System::Drawing::Point(0, 40);
			this->mainSplitContainer->Name = L"mainSplitContainer";
			this->mainSplitContainer->Panel1MinSize = 550;
			// 
			// mainSplitContainer.Panel2
			// 
			this->mainSplitContainer->Panel2->Controls->Add(this->historySplitContainer);
			this->mainSplitContainer->Panel2MinSize = 200;
			this->mainSplitContainer->Size = System::Drawing::Size(774, 467);
			this->mainSplitContainer->SplitterDistance = 550;
			this->mainSplitContainer->TabIndex = 2;
			this->mainSplitContainer->TabStop = false;
			// 
			// historySplitContainer
			// 
			this->historySplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->historySplitContainer->IsSplitterFixed = true;
			this->historySplitContainer->Location = System::Drawing::Point(0, 0);
			this->historySplitContainer->Name = L"historySplitContainer";
			this->historySplitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// historySplitContainer.Panel1
			// 
			this->historySplitContainer->Panel1->Controls->Add(this->tableLayoutPanel);
			// 
			// historySplitContainer.Panel2
			// 
			this->historySplitContainer->Panel2->Controls->Add(this->richTextBox);
			this->historySplitContainer->Size = System::Drawing::Size(216, 463);
			this->historySplitContainer->SplitterDistance = 101;
			this->historySplitContainer->TabIndex = 0;
			this->historySplitContainer->TabStop = false;
			// 
			// tableLayoutPanel
			// 
			this->tableLayoutPanel->ColumnCount = 2;
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel->Controls->Add(this->labelVirtualPlayerName, 0, 0);
			this->tableLayoutPanel->Controls->Add(this->pictureBoxSplitter, 0, 3);
			this->tableLayoutPanel->Controls->Add(this->labelHistory, 0, 4);
			this->tableLayoutPanel->Controls->Add(this->labelVirtualPlayerScore, 1, 0);
			this->tableLayoutPanel->Controls->Add(this->labelPlayerName, 0, 1);
			this->tableLayoutPanel->Controls->Add(this->labelPlayerScore, 1, 1);
			this->tableLayoutPanel->Controls->Add(this->labelGameTurn, 0, 2);
			this->tableLayoutPanel->Controls->Add(this->labelGameState, 1, 2);
			this->tableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel->Name = L"tableLayoutPanel";
			this->tableLayoutPanel->RowCount = 5;
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 5)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel->Size = System::Drawing::Size(216, 101);
			this->tableLayoutPanel->TabIndex = 0;
			// 
			// labelVirtualPlayerName
			// 
			this->labelVirtualPlayerName->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelVirtualPlayerName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelVirtualPlayerName->Location = System::Drawing::Point(3, 0);
			this->labelVirtualPlayerName->Name = L"labelVirtualPlayerName";
			this->labelVirtualPlayerName->Size = System::Drawing::Size(102, 25);
			this->labelVirtualPlayerName->TabIndex = 0;
			this->labelVirtualPlayerName->Text = L"Neo:";
			this->labelVirtualPlayerName->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// pictureBoxSplitter
			// 
			this->pictureBoxSplitter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxSplitter->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tableLayoutPanel->SetColumnSpan(this->pictureBoxSplitter, 2);
			this->pictureBoxSplitter->Location = System::Drawing::Point(3, 78);
			this->pictureBoxSplitter->Name = L"pictureBoxSplitter";
			this->pictureBoxSplitter->Size = System::Drawing::Size(210, 1);
			this->pictureBoxSplitter->TabIndex = 7;
			this->pictureBoxSplitter->TabStop = false;
			// 
			// labelHistory
			// 
			this->tableLayoutPanel->SetColumnSpan(this->labelHistory, 2);
			this->labelHistory->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelHistory->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelHistory->Location = System::Drawing::Point(3, 80);
			this->labelHistory->Name = L"labelHistory";
			this->labelHistory->Size = System::Drawing::Size(210, 25);
			this->labelHistory->TabIndex = 6;
			this->labelHistory->Text = L"History";
			this->labelHistory->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelVirtualPlayerScore
			// 
			this->labelVirtualPlayerScore->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelVirtualPlayerScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelVirtualPlayerScore->Location = System::Drawing::Point(111, 0);
			this->labelVirtualPlayerScore->Name = L"labelVirtualPlayerScore";
			this->labelVirtualPlayerScore->Size = System::Drawing::Size(102, 25);
			this->labelVirtualPlayerScore->TabIndex = 1;
			this->labelVirtualPlayerScore->Text = L"0";
			this->labelVirtualPlayerScore->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelPlayerName
			// 
			this->labelPlayerName->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelPlayerName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPlayerName->Location = System::Drawing::Point(3, 25);
			this->labelPlayerName->Name = L"labelPlayerName";
			this->labelPlayerName->Size = System::Drawing::Size(102, 25);
			this->labelPlayerName->TabIndex = 2;
			this->labelPlayerName->Text = L"You:";
			this->labelPlayerName->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelPlayerScore
			// 
			this->labelPlayerScore->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelPlayerScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPlayerScore->Location = System::Drawing::Point(111, 25);
			this->labelPlayerScore->Name = L"labelPlayerScore";
			this->labelPlayerScore->Size = System::Drawing::Size(102, 25);
			this->labelPlayerScore->TabIndex = 3;
			this->labelPlayerScore->Text = L"0";
			this->labelPlayerScore->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelGameTurn
			// 
			this->labelGameTurn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelGameTurn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelGameTurn->Location = System::Drawing::Point(3, 50);
			this->labelGameTurn->Name = L"labelGameTurn";
			this->labelGameTurn->Size = System::Drawing::Size(102, 25);
			this->labelGameTurn->TabIndex = 4;
			this->labelGameTurn->Text = L"Turn:";
			this->labelGameTurn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelGameState
			// 
			this->labelGameState->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelGameState->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelGameState->Location = System::Drawing::Point(111, 50);
			this->labelGameState->Name = L"labelGameState";
			this->labelGameState->Size = System::Drawing::Size(102, 25);
			this->labelGameState->TabIndex = 5;
			this->labelGameState->Text = L"N/A";
			this->labelGameState->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// richTextBox
			// 
			this->richTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox->Location = System::Drawing::Point(0, 0);
			this->richTextBox->Name = L"richTextBox";
			this->richTextBox->ReadOnly = true;
			this->richTextBox->Size = System::Drawing::Size(216, 358);
			this->richTextBox->TabIndex = 0;
			this->richTextBox->Text = L"";
			// 
			// GameForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(774, 529);
			this->Controls->Add(this->mainSplitContainer);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->menuStrip);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip;
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"GameForm";
			this->Text = L"Card-G";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GameForm::GameForm_FormClosing);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GameForm::GameForm_KeyDown);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->mainSplitContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainSplitContainer))->EndInit();
			this->mainSplitContainer->ResumeLayout(false);
			this->historySplitContainer->Panel1->ResumeLayout(false);
			this->historySplitContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->historySplitContainer))->EndInit();
			this->historySplitContainer->ResumeLayout(false);
			this->tableLayoutPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxSplitter))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void mainSplitContainer_Panel1_Resize(System::Object^ sender, System::EventArgs^ e) {
		// Compute the card size.
		double cardWidth, cardHeight;
		computeCardSize(&cardWidth, &cardHeight);

		// Display the virtual player card set.
		displayVirtualPlayerCards(cardWidth, cardHeight, false, false);
		// Display the played cards.
		displayPlayedCards(cardWidth, cardHeight, false, false);
		// Display the player card set.
		displayPlayerCards(cardWidth, cardHeight, false, false);
	}

	private: System::Void pictureBoxVirtualPlayerCard_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Return if this event is not a left click or the player can not steal a card.
		if (e->Button != System::Windows::Forms::MouseButtons::Left || !this->gameEngine->isPlayerSteal())
		{
			return;
		}

		// Get the index of the current card picture box control from the virtual player set of cards.
		System::Windows::Forms::PictureBox^ pictureBox = cli::safe_cast<System::Windows::Forms::PictureBox^>(sender);
		int pictureBoxIndex = int::Parse(pictureBox->Name->Substring(this->virtualPlayerCardNamePrefix->Length));

		// The player steals the selected card from the virtual player set of cards.
		this->gameEngine->playerStealsCard(pictureBoxIndex);
	}

	private: System::Void pictureBoxPlayerCard_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Return if this event is not a left click or the player can not play a card.
		if (e->Button != System::Windows::Forms::MouseButtons::Left || !this->gameEngine->isPlayerTurn())
		{
			return;
		}

		// Get the index of the current card picture box control from the player set of cards.
		System::Windows::Forms::PictureBox^ pictureBox = cli::safe_cast<System::Windows::Forms::PictureBox^>(sender);
		int pictureBoxIndex = int::Parse(pictureBox->Name->Substring(this->playerCardNamePrefix->Length));

		// The player plays the selected card from the player set of cards.
		this->gameEngine->playerPlaysCard(pictureBoxIndex);
	}

	private: System::Void newGameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		// Show a message if a game is underway.
		if (this->gameEngine->isGameUnderway())
		{
			System::Windows::Forms::DialogResult dialogResult = MessageBox::Show("A game is underway." + Environment::NewLine + "Do you want to cancel the current game and start a new one?", "New game", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			if (dialogResult == System::Windows::Forms::DialogResult::No)
			{
				// Return if the user decided to continue the current game.
				return;
			}
		}

		// Start a new game.
		this->gameEngine->newGame(false);

		// Clear the game history.
		this->richTextBox->Clear();

		// Create a card selection form.
		CardSelectionForm^ form = gcnew CardSelectionForm(this->gameEngine);
		// Show the card selection form.
		form->ShowDialog();

		// Clear the game history if the player did not selected all cards.
		if (!this->gameEngine->playerSelectedAllCards())
		{
			this->richTextBox->Clear();
		}

		// The virtual player selects his set of cards from the card deck.
		this->gameEngine->selectVirtualPlayerCards();
	}

	private: System::Void settingsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		// Show a message and return if a game is underway. Settings can not be changed while a game is underway.
		if (this->gameEngine->isGameUnderway())
		{
			MessageBox::Show("Settings can not be change while a game is underway!", "Settings", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}

		// Create a settings form.
		CardG::SettingsForm^ form = (gcnew CardG::SettingsForm(this->gameEngine));
		// Show the settings form.
		form->ShowDialog();
	}

	private: System::Void rulesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		// Creates a rules form.
		CardG::RulesForm^ form = (gcnew CardG::RulesForm(this->gameEngine));
		// Show the rules form.
		form->ShowDialog();
	}

	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create an about form.
		CardG::AboutForm^ form = (gcnew CardG::AboutForm());
		// Show the about form.
		form->ShowDialog();
	}

	private: System::Void GameForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		// Close all forms and exit the application.
		Application::Exit();
	}

	private: System::Void GameForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		// Create and show a test form if the F1 key is pressed.
		if (e->KeyCode == System::Windows::Forms::Keys::F1)
		{
			// Create a test form.
			TestForm^ form = gcnew TestForm();
			// Show the test form.
			form->ShowDialog();
		}
	}

	private:
		// Computes the size of a card based on the size of the client area of the form.
		//   cardWidth: The card width.
		//   cardHeight: The card height.
		void computeCardSize(double* cardWidth, double* cardHeight);

		// Displays the virtual player set of cards.
		//   cardWidth: The card width.
		//   cardHeight: The card height.
		//   create: Indicates whether the controls should be created.
		//   newGame: Indicates whether a new game is started.
		void displayVirtualPlayerCards(double cardWidth, double cardHeight, bool create, bool newGame);

		// Displays the played cards.
		//   cardWidth: The card width.
		//   cardHeight: The card height.
		//   create: Indicates whether the controls should be created.
		//   newGame: Indicates whether a new game is started.
		void displayPlayedCards(double cardWidth, double cardHeight, bool create, bool newGame);

		// Displays the player set of cards.
		//   cardWidth: The card width.
		//   cardHeight: The card height.
		//   create: Indicates whether the controls should be created.
		//   newGame: Indicates whether a new game is started.
		void displayPlayerCards(double cardWidth, double cardHeight, bool create, bool newGame);

		// Handles the new game event.
		void onNewGame();

		// Handles the player selected card event.
		//   cardIndex: The index of the selected card.
		//   cardName: The name of the selected card.
		void onPlayerSelectedCard(int cardIndex, String^ cardName);

		// Handles the virtual player selected card event.
		//   cardIndex: The index of the selected card.
		//   cardName: The name of the selected card.
		void onVirtualPlayerSelectedCard(int cardIndex, String^ cardName);

		// Represents a reference to a method that updates the form controls after the player played card event.
	    //   cardIndex: The index of the played card.
		//   cardName: The name of the played card.
		delegate void playerPlayedCardDelegate(int cardIndex, String^ cardName);

		// Updates the form controls after the player played card event.
		//   cardIndex: The index of the played card.
		//   cardName: The name of the played card.
		void playerPlayedCard(int cardIndex, String^ cardName);

		// Handles the player played card event.
		//   cardIndex: The index of the played card.
		//   cardName: The name of the played card.
		void onPlayerPlayedCard(int cardIndex, String^ cardName);

		// Represents a reference to a method that updates the form controls after the virtual player played card event.
		//   cardIndex: The index of the played card.
		//   cardName: The name of the played card.
		delegate void virtualPlayerPlayedCardDlegate(int cardIndex, String^ cardName);

		// Updates the form controls after the virtual player played card event.
		//   cardIndex: The index of the played card.
		//   cardName: The name of the played card.
		void virtualPlayerPlayedCard(int cardIndex, String^ cardName);

		// Handles the virtual player played card event.
		//   cardIndex: The index of the played card.
		//   cardName: The name of the played card.
		void onVirtualPlayerPlayedCard(int cardIndex, String^ cardName);

		// Represents a reference to a method that updates the form controls after the score changed event.
		//   virtualPlayerScore: The virtual player score.
		//   playerScore: The player score.
		delegate void scoreChangedDelegate(int virtualPlayerScore, int playerScore);

		// Updates the form controls after the score changed event.
		//   virtualPlayerScore: The virtual player score.
		//   playerScore: The player score.
		void scoreChanged(int virtualPlayerScore, int playerScore);

		// Handles the score changed event.
		//   virtualPlayerScore: The virtual player score.
		//   playerScore: The player score.
		void onScoreChanged(int virtualPlayerScore, int playerScore);

		// Represents a reference to a method that updates the form controls after the game state changed event.
		//   state: The game state.
		delegate void gameStateChangedDelegate(String^ turn);

		// Updates the form controls after the game state changed event.
		//   state: The game state.
		void gameStateChanged(String^ state);

		// Handles the game state changed event.
		//   state: The game state.
		void onGameStateChanged(String^ state);

		// Represents a reference to a method that updates the form controls after the game finished  event.
		delegate void gameFinishedDelegate();

		// Updates the form controls after the game finished  event.
		void gameFinished();

		// Handles the game finished event.
		void onGameFinished();

		// Represents a reference to a method that updates the form controls after the player stole card event.
		//   virtualPlayerCardIndex: The index of the card stolen from the virtual player card set.
		//   playerCardIndex: The index of the stolen card in the player card set.
		//   cardName: The name of the stolen card.
		delegate void playerStealCardDelegate(int virtualPlayerCardIndex, int playerCardIndex, String^ cardName);

		// Updates the form controls after the player stole card event.
		//   virtualPlayerCardIndex: The index of the card stolen from the virtual player card set.
		//   playerCardIndex: The index of the stolen card in the player card set.
		//   cardName: The name of the stolen card.
		void playerStealCard(int virtualPlayerCardIndex, int playerCardIndex, String^ cardName);

		// Handles the player stole card event.
		//   virtualPlayerCardIndex: The index of the card stolen from the virtual player card set.
		//   playerCardIndex: The index of the stolen card in the player card set.
		//   cardName: The name of the stolen card.
		void onPlayerStoleCard(int virtualPlayerCardIndex, int playerCardIndex, String^ cardName);

		// Represents a reference to a method that updates the form controls after the virtual player stole card event.
		//   playerCardIndex: The index of the card stolen from the player card set.
		//   virtualPlayerCards: The indexes of the cards in the virtual player card set.
		//   cardName: The name of the stolen card.
		delegate void virtualPlayerStoleCardDelegate(int playerCardIndex, array<bool>^ virtualPlayerCards, String^ cardName);
		
		// Updates the form controls after the virtual player stole card event.
		//   playerCardIndex: The index of the card stolen from the player card set.
		//   virtualPlayerCards: The indexes of the cards in the virtual player card set.
		//   cardName: The name of the stolen card.
		void virtualPlayerStoleCard(int playerCardIndex, array<bool>^ virtualPlayerCards, String^ cardName);

		// Handles the virtual player stole card event.
		//   playerCardIndex: The index of the card stolen from the player card set.
		//   virtualPlayerCards: The indexes of the cards in the virtual player card set.
		//   cardName: The name of the stolen card.
		void onVirtualPlayerStoleCard(int playerCardIndex, array<bool>^ virtualPlayerCards, String^ cardName);

		// Represents a reference to a method that updates the form controls after the history notification event.
		//   message: The history notification messgage.
		delegate void historyNotificationDelegate(String^ message);
	};
}

