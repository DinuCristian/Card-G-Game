#pragma once

#include "CardSelectionForm.h"
#include "GameEngine.h"

namespace CardG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	public:
		SettingsForm(GameEngine^ gameEngine)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToParent();

			this->gameEngine = gameEngine;
			loadGameSettings();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::TabControl^ tabControl;
	private: System::Windows::Forms::TabPage^ tabPageVirtualPlayer;
	private: System::Windows::Forms::TabPage^ tabPageCardTheme;
	
	private: System::Windows::Forms::TabPage^ tabPageCardDeck;
	private: System::Windows::Forms::GroupBox^ groupBoxVirtualPlayerSpeed;
	private: System::Windows::Forms::RadioButton^ radioButtonFast;
	private: System::Windows::Forms::RadioButton^ radioButtonNormal;
	private: System::Windows::Forms::RadioButton^ radioButtonSlow;
	private: System::Windows::Forms::GroupBox^ groupBoxCardColourScheme;

	private: System::Windows::Forms::RadioButton^ radioButtonBlue;
	private: System::Windows::Forms::RadioButton^ radioButtonGreen;
	private: System::Windows::Forms::RadioButton^ radioButtonRed;
	private: System::Windows::Forms::RadioButton^ radioButtonBlack;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanelVirtualPlayer;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanelCardTheme;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanelCardDeck;
	private: System::Windows::Forms::GroupBox^ groupBoxBasicCards;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCardMinus2;
	private: System::Windows::Forms::Label^ labelCardMinus2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCardMinus1;
	private: System::Windows::Forms::Label^ labelCardMinus1;
	private: System::Windows::Forms::GroupBox^ groupBoxExtensionCards;
	private: System::Windows::Forms::Label^ labelCardSteal;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCardSteal;
	private: System::Windows::Forms::Label^ labelCardPlus5;
	private: System::Windows::Forms::Label^ labelCardPlus4;
	private: System::Windows::Forms::Label^ labelCardPlus3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCardPlus5;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCardPlus4;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCardPlus3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCardPlus2;
	private: System::Windows::Forms::Label^ labelCardPlus2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCardPlus1;
	private: System::Windows::Forms::Label^ labelCardPlus1;
	private: System::Windows::Forms::Label^ labelCardMinus5;
	private: System::Windows::Forms::Label^ labelCardMinus4;
	private: System::Windows::Forms::Label^ labelCardMinus3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCardMinus5;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCardMinus4;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCardMinus3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCardChange;
	private: System::Windows::Forms::Label^ labelCardDouble;
	private: System::Windows::Forms::Label^ labelCardChange;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCardDouble;
	private: System::Windows::Forms::Button^ buttonCardDeckReset;
	private: System::Windows::Forms::Button^ buttonCardDeckSave;
	private: System::Windows::Forms::PictureBox^ pictureBoxCardBack;
	private: System::Windows::Forms::GroupBox^ groupBoxPreview;
	private: System::Windows::Forms::PictureBox^ pictureBoxStealCard;

	private: System::Windows::Forms::PictureBox^ pictureBoxMinusCard;
	private: System::Windows::Forms::PictureBox^ pictureBoxPlusCard;

	private: System::Windows::Forms::GroupBox^ groupBoxCardFace;
	private: System::Windows::Forms::GroupBox^ groupBoxCardFaceBasicCards;
	private: System::Windows::Forms::GroupBox^ groupBoxCardBack;
	private: System::Windows::Forms::GroupBox^ groupBoxCardFaceExtensionCards;
	private: System::Windows::Forms::PictureBox^ pictureBoxChangeCard;
	private: System::Windows::Forms::PictureBox^ pictureBoxDoubleCard;
	private: System::Windows::Forms::Button^ buttonCardThemeReset;
	private: System::Windows::Forms::Button^ buttonCardThemeSave;
	private: System::Windows::Forms::Button^ buttonVirtualPlayerReset;
	private: System::Windows::Forms::Button^ buttonVirtualPlayerSave;

	private:
		GameEngine^ gameEngine;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SettingsForm::typeid));
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPageVirtualPlayer = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanelVirtualPlayer = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBoxVirtualPlayerSpeed = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonFast = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonNormal = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonSlow = (gcnew System::Windows::Forms::RadioButton());
			this->buttonVirtualPlayerReset = (gcnew System::Windows::Forms::Button());
			this->buttonVirtualPlayerSave = (gcnew System::Windows::Forms::Button());
			this->tabPageCardTheme = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanelCardTheme = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBoxPreview = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxCardFace = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxCardFaceExtensionCards = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBoxChangeCard = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDoubleCard = (gcnew System::Windows::Forms::PictureBox());
			this->groupBoxCardFaceBasicCards = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBoxStealCard = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxMinusCard = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxPlusCard = (gcnew System::Windows::Forms::PictureBox());
			this->groupBoxCardBack = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBoxCardBack = (gcnew System::Windows::Forms::PictureBox());
			this->groupBoxCardColourScheme = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonBlue = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonGreen = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonRed = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonBlack = (gcnew System::Windows::Forms::RadioButton());
			this->buttonCardThemeReset = (gcnew System::Windows::Forms::Button());
			this->buttonCardThemeSave = (gcnew System::Windows::Forms::Button());
			this->tabPageCardDeck = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanelCardDeck = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBoxBasicCards = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDownCardSteal = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownCardPlus5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownCardPlus4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownCardPlus3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownCardPlus2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownCardPlus1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownCardMinus5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownCardMinus4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownCardMinus3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownCardMinus2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownCardMinus1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelCardSteal = (gcnew System::Windows::Forms::Label());
			this->labelCardPlus5 = (gcnew System::Windows::Forms::Label());
			this->labelCardPlus4 = (gcnew System::Windows::Forms::Label());
			this->labelCardPlus3 = (gcnew System::Windows::Forms::Label());
			this->labelCardPlus2 = (gcnew System::Windows::Forms::Label());
			this->labelCardPlus1 = (gcnew System::Windows::Forms::Label());
			this->labelCardMinus5 = (gcnew System::Windows::Forms::Label());
			this->labelCardMinus4 = (gcnew System::Windows::Forms::Label());
			this->labelCardMinus3 = (gcnew System::Windows::Forms::Label());
			this->labelCardMinus2 = (gcnew System::Windows::Forms::Label());
			this->labelCardMinus1 = (gcnew System::Windows::Forms::Label());
			this->groupBoxExtensionCards = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDownCardChange = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownCardDouble = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelCardDouble = (gcnew System::Windows::Forms::Label());
			this->labelCardChange = (gcnew System::Windows::Forms::Label());
			this->buttonCardDeckReset = (gcnew System::Windows::Forms::Button());
			this->buttonCardDeckSave = (gcnew System::Windows::Forms::Button());
			this->tabControl->SuspendLayout();
			this->tabPageVirtualPlayer->SuspendLayout();
			this->tableLayoutPanelVirtualPlayer->SuspendLayout();
			this->groupBoxVirtualPlayerSpeed->SuspendLayout();
			this->tabPageCardTheme->SuspendLayout();
			this->tableLayoutPanelCardTheme->SuspendLayout();
			this->groupBoxPreview->SuspendLayout();
			this->groupBoxCardFace->SuspendLayout();
			this->groupBoxCardFaceExtensionCards->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxChangeCard))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDoubleCard))->BeginInit();
			this->groupBoxCardFaceBasicCards->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxStealCard))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMinusCard))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPlusCard))->BeginInit();
			this->groupBoxCardBack->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCardBack))->BeginInit();
			this->groupBoxCardColourScheme->SuspendLayout();
			this->tabPageCardDeck->SuspendLayout();
			this->tableLayoutPanelCardDeck->SuspendLayout();
			this->groupBoxBasicCards->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardSteal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardPlus5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardPlus4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardPlus3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardPlus2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardPlus1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardMinus5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardMinus4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardMinus3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardMinus2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardMinus1))->BeginInit();
			this->groupBoxExtensionCards->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardChange))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardDouble))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabPageVirtualPlayer);
			this->tabControl->Controls->Add(this->tabPageCardTheme);
			this->tabControl->Controls->Add(this->tabPageCardDeck);
			this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl->Location = System::Drawing::Point(0, 0);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(484, 429);
			this->tabControl->TabIndex = 0;
			// 
			// tabPageVirtualPlayer
			// 
			this->tabPageVirtualPlayer->Controls->Add(this->tableLayoutPanelVirtualPlayer);
			this->tabPageVirtualPlayer->Location = System::Drawing::Point(8, 39);
			this->tabPageVirtualPlayer->Name = L"tabPageVirtualPlayer";
			this->tabPageVirtualPlayer->Padding = System::Windows::Forms::Padding(3);
			this->tabPageVirtualPlayer->Size = System::Drawing::Size(468, 382);
			this->tabPageVirtualPlayer->TabIndex = 0;
			this->tabPageVirtualPlayer->Text = L"Virtual Player";
			this->tabPageVirtualPlayer->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanelVirtualPlayer
			// 
			this->tableLayoutPanelVirtualPlayer->ColumnCount = 3;
			this->tableLayoutPanelVirtualPlayer->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				70)));
			this->tableLayoutPanelVirtualPlayer->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanelVirtualPlayer->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanelVirtualPlayer->Controls->Add(this->groupBoxVirtualPlayerSpeed, 0, 0);
			this->tableLayoutPanelVirtualPlayer->Controls->Add(this->buttonVirtualPlayerReset, 1, 2);
			this->tableLayoutPanelVirtualPlayer->Controls->Add(this->buttonVirtualPlayerSave, 2, 2);
			this->tableLayoutPanelVirtualPlayer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanelVirtualPlayer->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanelVirtualPlayer->Name = L"tableLayoutPanelVirtualPlayer";
			this->tableLayoutPanelVirtualPlayer->RowCount = 3;
			this->tableLayoutPanelVirtualPlayer->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				105)));
			this->tableLayoutPanelVirtualPlayer->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				250)));
			this->tableLayoutPanelVirtualPlayer->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutPanelVirtualPlayer->Size = System::Drawing::Size(462, 376);
			this->tableLayoutPanelVirtualPlayer->TabIndex = 1;
			// 
			// groupBoxVirtualPlayerSpeed
			// 
			this->tableLayoutPanelVirtualPlayer->SetColumnSpan(this->groupBoxVirtualPlayerSpeed, 3);
			this->groupBoxVirtualPlayerSpeed->Controls->Add(this->radioButtonFast);
			this->groupBoxVirtualPlayerSpeed->Controls->Add(this->radioButtonNormal);
			this->groupBoxVirtualPlayerSpeed->Controls->Add(this->radioButtonSlow);
			this->groupBoxVirtualPlayerSpeed->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBoxVirtualPlayerSpeed->Location = System::Drawing::Point(3, 3);
			this->groupBoxVirtualPlayerSpeed->Name = L"groupBoxVirtualPlayerSpeed";
			this->groupBoxVirtualPlayerSpeed->Size = System::Drawing::Size(456, 99);
			this->groupBoxVirtualPlayerSpeed->TabIndex = 0;
			this->groupBoxVirtualPlayerSpeed->TabStop = false;
			this->groupBoxVirtualPlayerSpeed->Text = L"Speed";
			// 
			// radioButtonFast
			// 
			this->radioButtonFast->AutoSize = true;
			this->radioButtonFast->Location = System::Drawing::Point(22, 71);
			this->radioButtonFast->Name = L"radioButtonFast";
			this->radioButtonFast->Size = System::Drawing::Size(85, 29);
			this->radioButtonFast->TabIndex = 2;
			this->radioButtonFast->Text = L"Fast";
			this->radioButtonFast->UseVisualStyleBackColor = true;
			// 
			// radioButtonNormal
			// 
			this->radioButtonNormal->AutoSize = true;
			this->radioButtonNormal->Location = System::Drawing::Point(22, 47);
			this->radioButtonNormal->Name = L"radioButtonNormal";
			this->radioButtonNormal->Size = System::Drawing::Size(111, 29);
			this->radioButtonNormal->TabIndex = 1;
			this->radioButtonNormal->Text = L"Normal";
			// 
			// radioButtonSlow
			// 
			this->radioButtonSlow->AutoSize = true;
			this->radioButtonSlow->Location = System::Drawing::Point(22, 23);
			this->radioButtonSlow->Name = L"radioButtonSlow";
			this->radioButtonSlow->Size = System::Drawing::Size(89, 29);
			this->radioButtonSlow->TabIndex = 0;
			this->radioButtonSlow->TabStop = true;
			this->radioButtonSlow->Text = L"Slow";
			this->radioButtonSlow->UseVisualStyleBackColor = true;
			// 
			// buttonVirtualPlayerReset
			// 
			this->buttonVirtualPlayerReset->Location = System::Drawing::Point(326, 358);
			this->buttonVirtualPlayerReset->Name = L"buttonVirtualPlayerReset";
			this->buttonVirtualPlayerReset->Size = System::Drawing::Size(63, 23);
			this->buttonVirtualPlayerReset->TabIndex = 1;
			this->buttonVirtualPlayerReset->Text = L"Reset";
			this->buttonVirtualPlayerReset->UseVisualStyleBackColor = true;
			this->buttonVirtualPlayerReset->Click += gcnew System::EventHandler(this, &SettingsForm::buttonVirtualPlayerReset_Click);
			// 
			// buttonVirtualPlayerSave
			// 
			this->buttonVirtualPlayerSave->Location = System::Drawing::Point(395, 358);
			this->buttonVirtualPlayerSave->Name = L"buttonVirtualPlayerSave";
			this->buttonVirtualPlayerSave->Size = System::Drawing::Size(64, 23);
			this->buttonVirtualPlayerSave->TabIndex = 2;
			this->buttonVirtualPlayerSave->Text = L"Save";
			this->buttonVirtualPlayerSave->UseVisualStyleBackColor = true;
			this->buttonVirtualPlayerSave->Click += gcnew System::EventHandler(this, &SettingsForm::buttonVirtualPlayerSave_Click);
			// 
			// tabPageCardTheme
			// 
			this->tabPageCardTheme->Controls->Add(this->tableLayoutPanelCardTheme);
			this->tabPageCardTheme->Location = System::Drawing::Point(8, 39);
			this->tabPageCardTheme->Name = L"tabPageCardTheme";
			this->tabPageCardTheme->Padding = System::Windows::Forms::Padding(3);
			this->tabPageCardTheme->Size = System::Drawing::Size(468, 382);
			this->tabPageCardTheme->TabIndex = 1;
			this->tabPageCardTheme->Text = L"Card Theme";
			this->tabPageCardTheme->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanelCardTheme
			// 
			this->tableLayoutPanelCardTheme->ColumnCount = 3;
			this->tableLayoutPanelCardTheme->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				70)));
			this->tableLayoutPanelCardTheme->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanelCardTheme->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanelCardTheme->Controls->Add(this->groupBoxPreview, 0, 1);
			this->tableLayoutPanelCardTheme->Controls->Add(this->groupBoxCardColourScheme, 0, 0);
			this->tableLayoutPanelCardTheme->Controls->Add(this->buttonCardThemeReset, 1, 3);
			this->tableLayoutPanelCardTheme->Controls->Add(this->buttonCardThemeSave, 2, 3);
			this->tableLayoutPanelCardTheme->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanelCardTheme->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanelCardTheme->Name = L"tableLayoutPanelCardTheme";
			this->tableLayoutPanelCardTheme->RowCount = 4;
			this->tableLayoutPanelCardTheme->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				130)));
			this->tableLayoutPanelCardTheme->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				175)));
			this->tableLayoutPanelCardTheme->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutPanelCardTheme->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				100)));
			this->tableLayoutPanelCardTheme->Size = System::Drawing::Size(462, 376);
			this->tableLayoutPanelCardTheme->TabIndex = 2;
			// 
			// groupBoxPreview
			// 
			this->tableLayoutPanelCardTheme->SetColumnSpan(this->groupBoxPreview, 3);
			this->groupBoxPreview->Controls->Add(this->groupBoxCardFace);
			this->groupBoxPreview->Controls->Add(this->groupBoxCardBack);
			this->groupBoxPreview->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBoxPreview->Location = System::Drawing::Point(3, 133);
			this->groupBoxPreview->Name = L"groupBoxPreview";
			this->groupBoxPreview->Size = System::Drawing::Size(456, 169);
			this->groupBoxPreview->TabIndex = 4;
			this->groupBoxPreview->TabStop = false;
			this->groupBoxPreview->Text = L"Preview";
			// 
			// groupBoxCardFace
			// 
			this->groupBoxCardFace->Controls->Add(this->groupBoxCardFaceExtensionCards);
			this->groupBoxCardFace->Controls->Add(this->groupBoxCardFaceBasicCards);
			this->groupBoxCardFace->Location = System::Drawing::Point(83, 20);
			this->groupBoxCardFace->Name = L"groupBoxCardFace";
			this->groupBoxCardFace->Size = System::Drawing::Size(375, 142);
			this->groupBoxCardFace->TabIndex = 9;
			this->groupBoxCardFace->TabStop = false;
			this->groupBoxCardFace->Text = L"Face";
			// 
			// groupBoxCardFaceExtensionCards
			// 
			this->groupBoxCardFaceExtensionCards->Controls->Add(this->pictureBoxChangeCard);
			this->groupBoxCardFaceExtensionCards->Controls->Add(this->pictureBoxDoubleCard);
			this->groupBoxCardFaceExtensionCards->Location = System::Drawing::Point(223, 19);
			this->groupBoxCardFaceExtensionCards->Name = L"groupBoxCardFaceExtensionCards";
			this->groupBoxCardFaceExtensionCards->Size = System::Drawing::Size(144, 117);
			this->groupBoxCardFaceExtensionCards->TabIndex = 1;
			this->groupBoxCardFaceExtensionCards->TabStop = false;
			this->groupBoxCardFaceExtensionCards->Text = L"Extension Cards";
			// 
			// pictureBoxChangeCard
			// 
			this->pictureBoxChangeCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxChangeCard.Image")));
			this->pictureBoxChangeCard->Location = System::Drawing::Point(74, 22);
			this->pictureBoxChangeCard->Name = L"pictureBoxChangeCard";
			this->pictureBoxChangeCard->Size = System::Drawing::Size(62, 88);
			this->pictureBoxChangeCard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxChangeCard->TabIndex = 7;
			this->pictureBoxChangeCard->TabStop = false;
			// 
			// pictureBoxDoubleCard
			// 
			this->pictureBoxDoubleCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxDoubleCard.Image")));
			this->pictureBoxDoubleCard->Location = System::Drawing::Point(6, 22);
			this->pictureBoxDoubleCard->Name = L"pictureBoxDoubleCard";
			this->pictureBoxDoubleCard->Size = System::Drawing::Size(62, 88);
			this->pictureBoxDoubleCard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxDoubleCard->TabIndex = 6;
			this->pictureBoxDoubleCard->TabStop = false;
			// 
			// groupBoxCardFaceBasicCards
			// 
			this->groupBoxCardFaceBasicCards->Controls->Add(this->pictureBoxStealCard);
			this->groupBoxCardFaceBasicCards->Controls->Add(this->pictureBoxMinusCard);
			this->groupBoxCardFaceBasicCards->Controls->Add(this->pictureBoxPlusCard);
			this->groupBoxCardFaceBasicCards->Location = System::Drawing::Point(6, 19);
			this->groupBoxCardFaceBasicCards->Name = L"groupBoxCardFaceBasicCards";
			this->groupBoxCardFaceBasicCards->Size = System::Drawing::Size(211, 117);
			this->groupBoxCardFaceBasicCards->TabIndex = 0;
			this->groupBoxCardFaceBasicCards->TabStop = false;
			this->groupBoxCardFaceBasicCards->Text = L"Basic Cards";
			// 
			// pictureBoxStealCard
			// 
			this->pictureBoxStealCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxStealCard.Image")));
			this->pictureBoxStealCard->Location = System::Drawing::Point(142, 22);
			this->pictureBoxStealCard->Name = L"pictureBoxStealCard";
			this->pictureBoxStealCard->Size = System::Drawing::Size(62, 88);
			this->pictureBoxStealCard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxStealCard->TabIndex = 5;
			this->pictureBoxStealCard->TabStop = false;
			// 
			// pictureBoxMinusCard
			// 
			this->pictureBoxMinusCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxMinusCard.Image")));
			this->pictureBoxMinusCard->Location = System::Drawing::Point(74, 22);
			this->pictureBoxMinusCard->Name = L"pictureBoxMinusCard";
			this->pictureBoxMinusCard->Size = System::Drawing::Size(62, 88);
			this->pictureBoxMinusCard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxMinusCard->TabIndex = 4;
			this->pictureBoxMinusCard->TabStop = false;
			// 
			// pictureBoxPlusCard
			// 
			this->pictureBoxPlusCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxPlusCard.Image")));
			this->pictureBoxPlusCard->Location = System::Drawing::Point(6, 22);
			this->pictureBoxPlusCard->Name = L"pictureBoxPlusCard";
			this->pictureBoxPlusCard->Size = System::Drawing::Size(62, 88);
			this->pictureBoxPlusCard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxPlusCard->TabIndex = 3;
			this->pictureBoxPlusCard->TabStop = false;
			// 
			// groupBoxCardBack
			// 
			this->groupBoxCardBack->Controls->Add(this->pictureBoxCardBack);
			this->groupBoxCardBack->Location = System::Drawing::Point(5, 20);
			this->groupBoxCardBack->Name = L"groupBoxCardBack";
			this->groupBoxCardBack->Size = System::Drawing::Size(72, 142);
			this->groupBoxCardBack->TabIndex = 8;
			this->groupBoxCardBack->TabStop = false;
			this->groupBoxCardBack->Text = L"Back";
			// 
			// pictureBoxCardBack
			// 
			this->pictureBoxCardBack->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxCardBack.Image")));
			this->pictureBoxCardBack->Location = System::Drawing::Point(5, 41);
			this->pictureBoxCardBack->Name = L"pictureBoxCardBack";
			this->pictureBoxCardBack->Size = System::Drawing::Size(62, 88);
			this->pictureBoxCardBack->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxCardBack->TabIndex = 2;
			this->pictureBoxCardBack->TabStop = false;
			// 
			// groupBoxCardColourScheme
			// 
			this->tableLayoutPanelCardTheme->SetColumnSpan(this->groupBoxCardColourScheme, 3);
			this->groupBoxCardColourScheme->Controls->Add(this->radioButtonBlue);
			this->groupBoxCardColourScheme->Controls->Add(this->radioButtonGreen);
			this->groupBoxCardColourScheme->Controls->Add(this->radioButtonRed);
			this->groupBoxCardColourScheme->Controls->Add(this->radioButtonBlack);
			this->groupBoxCardColourScheme->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBoxCardColourScheme->Location = System::Drawing::Point(3, 3);
			this->groupBoxCardColourScheme->Name = L"groupBoxCardColourScheme";
			this->groupBoxCardColourScheme->Size = System::Drawing::Size(456, 124);
			this->groupBoxCardColourScheme->TabIndex = 1;
			this->groupBoxCardColourScheme->TabStop = false;
			this->groupBoxCardColourScheme->Text = L"Colour Scheme";
			// 
			// radioButtonBlue
			// 
			this->radioButtonBlue->AutoSize = true;
			this->radioButtonBlue->Location = System::Drawing::Point(27, 98);
			this->radioButtonBlue->Name = L"radioButtonBlue";
			this->radioButtonBlue->Size = System::Drawing::Size(86, 29);
			this->radioButtonBlue->TabIndex = 3;
			this->radioButtonBlue->Text = L"Blue";
			this->radioButtonBlue->UseVisualStyleBackColor = true;
			this->radioButtonBlue->CheckedChanged += gcnew System::EventHandler(this, &SettingsForm::radioButtonBlue_CheckedChanged);
			// 
			// radioButtonGreen
			// 
			this->radioButtonGreen->AutoSize = true;
			this->radioButtonGreen->Location = System::Drawing::Point(27, 73);
			this->radioButtonGreen->Name = L"radioButtonGreen";
			this->radioButtonGreen->Size = System::Drawing::Size(102, 29);
			this->radioButtonGreen->TabIndex = 2;
			this->radioButtonGreen->Text = L"Green";
			this->radioButtonGreen->UseVisualStyleBackColor = true;
			this->radioButtonGreen->CheckedChanged += gcnew System::EventHandler(this, &SettingsForm::radioButtonGreen_CheckedChanged);
			// 
			// radioButtonRed
			// 
			this->radioButtonRed->AutoSize = true;
			this->radioButtonRed->Location = System::Drawing::Point(27, 48);
			this->radioButtonRed->Name = L"radioButtonRed";
			this->radioButtonRed->Size = System::Drawing::Size(82, 29);
			this->radioButtonRed->TabIndex = 1;
			this->radioButtonRed->Text = L"Red";
			this->radioButtonRed->UseVisualStyleBackColor = true;
			this->radioButtonRed->CheckedChanged += gcnew System::EventHandler(this, &SettingsForm::radioButtonRed_CheckedChanged);
			// 
			// radioButtonBlack
			// 
			this->radioButtonBlack->AutoSize = true;
			this->radioButtonBlack->Location = System::Drawing::Point(27, 23);
			this->radioButtonBlack->Name = L"radioButtonBlack";
			this->radioButtonBlack->Size = System::Drawing::Size(96, 29);
			this->radioButtonBlack->TabIndex = 0;
			this->radioButtonBlack->Text = L"Black";
			this->radioButtonBlack->UseVisualStyleBackColor = true;
			this->radioButtonBlack->CheckedChanged += gcnew System::EventHandler(this, &SettingsForm::radioButtonBlack_CheckedChanged);
			// 
			// buttonCardThemeReset
			// 
			this->buttonCardThemeReset->Location = System::Drawing::Point(326, 358);
			this->buttonCardThemeReset->Name = L"buttonCardThemeReset";
			this->buttonCardThemeReset->Size = System::Drawing::Size(63, 23);
			this->buttonCardThemeReset->TabIndex = 5;
			this->buttonCardThemeReset->Text = L"Reset";
			this->buttonCardThemeReset->UseVisualStyleBackColor = true;
			this->buttonCardThemeReset->Click += gcnew System::EventHandler(this, &SettingsForm::buttonCardThemeReset_Click);
			// 
			// buttonCardThemeSave
			// 
			this->buttonCardThemeSave->Location = System::Drawing::Point(395, 358);
			this->buttonCardThemeSave->Name = L"buttonCardThemeSave";
			this->buttonCardThemeSave->Size = System::Drawing::Size(64, 23);
			this->buttonCardThemeSave->TabIndex = 6;
			this->buttonCardThemeSave->Text = L"Save";
			this->buttonCardThemeSave->UseVisualStyleBackColor = true;
			this->buttonCardThemeSave->Click += gcnew System::EventHandler(this, &SettingsForm::buttonCardThemeSave_Click);
			// 
			// tabPageCardDeck
			// 
			this->tabPageCardDeck->Controls->Add(this->tableLayoutPanelCardDeck);
			this->tabPageCardDeck->Location = System::Drawing::Point(8, 39);
			this->tabPageCardDeck->Name = L"tabPageCardDeck";
			this->tabPageCardDeck->Padding = System::Windows::Forms::Padding(3);
			this->tabPageCardDeck->Size = System::Drawing::Size(468, 382);
			this->tabPageCardDeck->TabIndex = 2;
			this->tabPageCardDeck->Text = L"Card Deck";
			this->tabPageCardDeck->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanelCardDeck
			// 
			this->tableLayoutPanelCardDeck->ColumnCount = 3;
			this->tableLayoutPanelCardDeck->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				70)));
			this->tableLayoutPanelCardDeck->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanelCardDeck->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanelCardDeck->Controls->Add(this->groupBoxBasicCards, 0, 0);
			this->tableLayoutPanelCardDeck->Controls->Add(this->groupBoxExtensionCards, 0, 1);
			this->tableLayoutPanelCardDeck->Controls->Add(this->buttonCardDeckReset, 1, 3);
			this->tableLayoutPanelCardDeck->Controls->Add(this->buttonCardDeckSave, 2, 3);
			this->tableLayoutPanelCardDeck->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanelCardDeck->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanelCardDeck->Name = L"tableLayoutPanelCardDeck";
			this->tableLayoutPanelCardDeck->RowCount = 4;
			this->tableLayoutPanelCardDeck->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				225)));
			this->tableLayoutPanelCardDeck->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				110)));
			this->tableLayoutPanelCardDeck->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanelCardDeck->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutPanelCardDeck->Size = System::Drawing::Size(462, 376);
			this->tableLayoutPanelCardDeck->TabIndex = 0;
			// 
			// groupBoxBasicCards
			// 
			this->tableLayoutPanelCardDeck->SetColumnSpan(this->groupBoxBasicCards, 3);
			this->groupBoxBasicCards->Controls->Add(this->numericUpDownCardSteal);
			this->groupBoxBasicCards->Controls->Add(this->numericUpDownCardPlus5);
			this->groupBoxBasicCards->Controls->Add(this->numericUpDownCardPlus4);
			this->groupBoxBasicCards->Controls->Add(this->numericUpDownCardPlus3);
			this->groupBoxBasicCards->Controls->Add(this->numericUpDownCardPlus2);
			this->groupBoxBasicCards->Controls->Add(this->numericUpDownCardPlus1);
			this->groupBoxBasicCards->Controls->Add(this->numericUpDownCardMinus5);
			this->groupBoxBasicCards->Controls->Add(this->numericUpDownCardMinus4);
			this->groupBoxBasicCards->Controls->Add(this->numericUpDownCardMinus3);
			this->groupBoxBasicCards->Controls->Add(this->numericUpDownCardMinus2);
			this->groupBoxBasicCards->Controls->Add(this->numericUpDownCardMinus1);
			this->groupBoxBasicCards->Controls->Add(this->labelCardSteal);
			this->groupBoxBasicCards->Controls->Add(this->labelCardPlus5);
			this->groupBoxBasicCards->Controls->Add(this->labelCardPlus4);
			this->groupBoxBasicCards->Controls->Add(this->labelCardPlus3);
			this->groupBoxBasicCards->Controls->Add(this->labelCardPlus2);
			this->groupBoxBasicCards->Controls->Add(this->labelCardPlus1);
			this->groupBoxBasicCards->Controls->Add(this->labelCardMinus5);
			this->groupBoxBasicCards->Controls->Add(this->labelCardMinus4);
			this->groupBoxBasicCards->Controls->Add(this->labelCardMinus3);
			this->groupBoxBasicCards->Controls->Add(this->labelCardMinus2);
			this->groupBoxBasicCards->Controls->Add(this->labelCardMinus1);
			this->groupBoxBasicCards->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBoxBasicCards->Location = System::Drawing::Point(3, 3);
			this->groupBoxBasicCards->Name = L"groupBoxBasicCards";
			this->groupBoxBasicCards->Size = System::Drawing::Size(456, 219);
			this->groupBoxBasicCards->TabIndex = 0;
			this->groupBoxBasicCards->TabStop = false;
			this->groupBoxBasicCards->Text = L"Basic Cards";
			// 
			// numericUpDownCardSteal
			// 
			this->numericUpDownCardSteal->Location = System::Drawing::Point(315, 112);
			this->numericUpDownCardSteal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownCardSteal->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownCardSteal->Name = L"numericUpDownCardSteal";
			this->numericUpDownCardSteal->Size = System::Drawing::Size(50, 31);
			this->numericUpDownCardSteal->TabIndex = 20;
			this->numericUpDownCardSteal->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDownCardPlus5
			// 
			this->numericUpDownCardPlus5->Location = System::Drawing::Point(197, 186);
			this->numericUpDownCardPlus5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownCardPlus5->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownCardPlus5->Name = L"numericUpDownCardPlus5";
			this->numericUpDownCardPlus5->Size = System::Drawing::Size(50, 31);
			this->numericUpDownCardPlus5->TabIndex = 16;
			this->numericUpDownCardPlus5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDownCardPlus4
			// 
			this->numericUpDownCardPlus4->Location = System::Drawing::Point(197, 149);
			this->numericUpDownCardPlus4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownCardPlus4->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownCardPlus4->Name = L"numericUpDownCardPlus4";
			this->numericUpDownCardPlus4->Size = System::Drawing::Size(50, 31);
			this->numericUpDownCardPlus4->TabIndex = 15;
			this->numericUpDownCardPlus4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDownCardPlus3
			// 
			this->numericUpDownCardPlus3->Location = System::Drawing::Point(197, 112);
			this->numericUpDownCardPlus3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownCardPlus3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownCardPlus3->Name = L"numericUpDownCardPlus3";
			this->numericUpDownCardPlus3->Size = System::Drawing::Size(50, 31);
			this->numericUpDownCardPlus3->TabIndex = 14;
			this->numericUpDownCardPlus3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDownCardPlus2
			// 
			this->numericUpDownCardPlus2->Location = System::Drawing::Point(197, 75);
			this->numericUpDownCardPlus2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownCardPlus2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownCardPlus2->Name = L"numericUpDownCardPlus2";
			this->numericUpDownCardPlus2->Size = System::Drawing::Size(50, 31);
			this->numericUpDownCardPlus2->TabIndex = 13;
			this->numericUpDownCardPlus2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDownCardPlus1
			// 
			this->numericUpDownCardPlus1->Location = System::Drawing::Point(197, 38);
			this->numericUpDownCardPlus1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownCardPlus1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownCardPlus1->Name = L"numericUpDownCardPlus1";
			this->numericUpDownCardPlus1->Size = System::Drawing::Size(50, 31);
			this->numericUpDownCardPlus1->TabIndex = 11;
			this->numericUpDownCardPlus1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDownCardMinus5
			// 
			this->numericUpDownCardMinus5->Location = System::Drawing::Point(66, 186);
			this->numericUpDownCardMinus5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownCardMinus5->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownCardMinus5->Name = L"numericUpDownCardMinus5";
			this->numericUpDownCardMinus5->Size = System::Drawing::Size(50, 31);
			this->numericUpDownCardMinus5->TabIndex = 6;
			this->numericUpDownCardMinus5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDownCardMinus4
			// 
			this->numericUpDownCardMinus4->Location = System::Drawing::Point(66, 149);
			this->numericUpDownCardMinus4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownCardMinus4->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownCardMinus4->Name = L"numericUpDownCardMinus4";
			this->numericUpDownCardMinus4->Size = System::Drawing::Size(50, 31);
			this->numericUpDownCardMinus4->TabIndex = 5;
			this->numericUpDownCardMinus4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDownCardMinus3
			// 
			this->numericUpDownCardMinus3->Location = System::Drawing::Point(66, 112);
			this->numericUpDownCardMinus3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownCardMinus3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownCardMinus3->Name = L"numericUpDownCardMinus3";
			this->numericUpDownCardMinus3->Size = System::Drawing::Size(50, 31);
			this->numericUpDownCardMinus3->TabIndex = 4;
			this->numericUpDownCardMinus3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDownCardMinus2
			// 
			this->numericUpDownCardMinus2->Location = System::Drawing::Point(66, 75);
			this->numericUpDownCardMinus2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownCardMinus2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownCardMinus2->Name = L"numericUpDownCardMinus2";
			this->numericUpDownCardMinus2->Size = System::Drawing::Size(50, 31);
			this->numericUpDownCardMinus2->TabIndex = 3;
			this->numericUpDownCardMinus2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDownCardMinus1
			// 
			this->numericUpDownCardMinus1->Location = System::Drawing::Point(66, 38);
			this->numericUpDownCardMinus1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownCardMinus1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDownCardMinus1->Name = L"numericUpDownCardMinus1";
			this->numericUpDownCardMinus1->Size = System::Drawing::Size(50, 31);
			this->numericUpDownCardMinus1->TabIndex = 1;
			this->numericUpDownCardMinus1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// labelCardSteal
			// 
			this->labelCardSteal->AutoSize = true;
			this->labelCardSteal->Location = System::Drawing::Point(281, 114);
			this->labelCardSteal->Name = L"labelCardSteal";
			this->labelCardSteal->Size = System::Drawing::Size(67, 25);
			this->labelCardSteal->TabIndex = 21;
			this->labelCardSteal->Text = L"Steal:";
			// 
			// labelCardPlus5
			// 
			this->labelCardPlus5->AutoSize = true;
			this->labelCardPlus5->Location = System::Drawing::Point(157, 188);
			this->labelCardPlus5->Name = L"labelCardPlus5";
			this->labelCardPlus5->Size = System::Drawing::Size(78, 25);
			this->labelCardPlus5->TabIndex = 19;
			this->labelCardPlus5->Text = L"Plus 5:";
			// 
			// labelCardPlus4
			// 
			this->labelCardPlus4->AutoSize = true;
			this->labelCardPlus4->Location = System::Drawing::Point(157, 151);
			this->labelCardPlus4->Name = L"labelCardPlus4";
			this->labelCardPlus4->Size = System::Drawing::Size(78, 25);
			this->labelCardPlus4->TabIndex = 18;
			this->labelCardPlus4->Text = L"Plus 4:";
			// 
			// labelCardPlus3
			// 
			this->labelCardPlus3->AutoSize = true;
			this->labelCardPlus3->Location = System::Drawing::Point(157, 114);
			this->labelCardPlus3->Name = L"labelCardPlus3";
			this->labelCardPlus3->Size = System::Drawing::Size(78, 25);
			this->labelCardPlus3->TabIndex = 17;
			this->labelCardPlus3->Text = L"Plus 3:";
			// 
			// labelCardPlus2
			// 
			this->labelCardPlus2->AutoSize = true;
			this->labelCardPlus2->Location = System::Drawing::Point(157, 77);
			this->labelCardPlus2->Name = L"labelCardPlus2";
			this->labelCardPlus2->Size = System::Drawing::Size(78, 25);
			this->labelCardPlus2->TabIndex = 12;
			this->labelCardPlus2->Text = L"Plus 2:";
			// 
			// labelCardPlus1
			// 
			this->labelCardPlus1->AutoSize = true;
			this->labelCardPlus1->Location = System::Drawing::Point(157, 40);
			this->labelCardPlus1->Name = L"labelCardPlus1";
			this->labelCardPlus1->Size = System::Drawing::Size(78, 25);
			this->labelCardPlus1->TabIndex = 10;
			this->labelCardPlus1->Text = L"Plus 1:";
			// 
			// labelCardMinus5
			// 
			this->labelCardMinus5->AutoSize = true;
			this->labelCardMinus5->Location = System::Drawing::Point(17, 188);
			this->labelCardMinus5->Name = L"labelCardMinus5";
			this->labelCardMinus5->Size = System::Drawing::Size(94, 25);
			this->labelCardMinus5->TabIndex = 9;
			this->labelCardMinus5->Text = L"Minus 5:";
			// 
			// labelCardMinus4
			// 
			this->labelCardMinus4->AutoSize = true;
			this->labelCardMinus4->Location = System::Drawing::Point(17, 151);
			this->labelCardMinus4->Name = L"labelCardMinus4";
			this->labelCardMinus4->Size = System::Drawing::Size(94, 25);
			this->labelCardMinus4->TabIndex = 8;
			this->labelCardMinus4->Text = L"Minus 4:";
			// 
			// labelCardMinus3
			// 
			this->labelCardMinus3->AutoSize = true;
			this->labelCardMinus3->Location = System::Drawing::Point(17, 114);
			this->labelCardMinus3->Name = L"labelCardMinus3";
			this->labelCardMinus3->Size = System::Drawing::Size(94, 25);
			this->labelCardMinus3->TabIndex = 7;
			this->labelCardMinus3->Text = L"Minus 3:";
			// 
			// labelCardMinus2
			// 
			this->labelCardMinus2->AutoSize = true;
			this->labelCardMinus2->Location = System::Drawing::Point(17, 77);
			this->labelCardMinus2->Name = L"labelCardMinus2";
			this->labelCardMinus2->Size = System::Drawing::Size(94, 25);
			this->labelCardMinus2->TabIndex = 2;
			this->labelCardMinus2->Text = L"Minus 2:";
			// 
			// labelCardMinus1
			// 
			this->labelCardMinus1->AutoSize = true;
			this->labelCardMinus1->Location = System::Drawing::Point(17, 40);
			this->labelCardMinus1->Name = L"labelCardMinus1";
			this->labelCardMinus1->Size = System::Drawing::Size(94, 25);
			this->labelCardMinus1->TabIndex = 0;
			this->labelCardMinus1->Text = L"Minus 1:";
			// 
			// groupBoxExtensionCards
			// 
			this->tableLayoutPanelCardDeck->SetColumnSpan(this->groupBoxExtensionCards, 3);
			this->groupBoxExtensionCards->Controls->Add(this->numericUpDownCardChange);
			this->groupBoxExtensionCards->Controls->Add(this->numericUpDownCardDouble);
			this->groupBoxExtensionCards->Controls->Add(this->labelCardDouble);
			this->groupBoxExtensionCards->Controls->Add(this->labelCardChange);
			this->groupBoxExtensionCards->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBoxExtensionCards->Location = System::Drawing::Point(3, 228);
			this->groupBoxExtensionCards->Name = L"groupBoxExtensionCards";
			this->groupBoxExtensionCards->Size = System::Drawing::Size(456, 104);
			this->groupBoxExtensionCards->TabIndex = 1;
			this->groupBoxExtensionCards->TabStop = false;
			this->groupBoxExtensionCards->Text = L"Extension Cards";
			// 
			// numericUpDownCardChange
			// 
			this->numericUpDownCardChange->Location = System::Drawing::Point(66, 71);
			this->numericUpDownCardChange->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownCardChange->Name = L"numericUpDownCardChange";
			this->numericUpDownCardChange->Size = System::Drawing::Size(50, 31);
			this->numericUpDownCardChange->TabIndex = 25;
			// 
			// numericUpDownCardDouble
			// 
			this->numericUpDownCardDouble->Location = System::Drawing::Point(66, 34);
			this->numericUpDownCardDouble->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownCardDouble->Name = L"numericUpDownCardDouble";
			this->numericUpDownCardDouble->Size = System::Drawing::Size(50, 31);
			this->numericUpDownCardDouble->TabIndex = 23;
			// 
			// labelCardDouble
			// 
			this->labelCardDouble->AutoSize = true;
			this->labelCardDouble->Location = System::Drawing::Point(17, 36);
			this->labelCardDouble->Name = L"labelCardDouble";
			this->labelCardDouble->Size = System::Drawing::Size(86, 25);
			this->labelCardDouble->TabIndex = 22;
			this->labelCardDouble->Text = L"Double:";
			// 
			// labelCardChange
			// 
			this->labelCardChange->AutoSize = true;
			this->labelCardChange->Location = System::Drawing::Point(17, 73);
			this->labelCardChange->Name = L"labelCardChange";
			this->labelCardChange->Size = System::Drawing::Size(93, 25);
			this->labelCardChange->TabIndex = 24;
			this->labelCardChange->Text = L"Change:";
			// 
			// buttonCardDeckReset
			// 
			this->buttonCardDeckReset->Location = System::Drawing::Point(326, 358);
			this->buttonCardDeckReset->Name = L"buttonCardDeckReset";
			this->buttonCardDeckReset->Size = System::Drawing::Size(63, 23);
			this->buttonCardDeckReset->TabIndex = 2;
			this->buttonCardDeckReset->Text = L"Reset";
			this->buttonCardDeckReset->UseVisualStyleBackColor = true;
			this->buttonCardDeckReset->Click += gcnew System::EventHandler(this, &SettingsForm::buttonCardDeckReset_Click);
			// 
			// buttonCardDeckSave
			// 
			this->buttonCardDeckSave->Location = System::Drawing::Point(395, 358);
			this->buttonCardDeckSave->Name = L"buttonCardDeckSave";
			this->buttonCardDeckSave->Size = System::Drawing::Size(64, 23);
			this->buttonCardDeckSave->TabIndex = 3;
			this->buttonCardDeckSave->Text = L"Save";
			this->buttonCardDeckSave->UseVisualStyleBackColor = true;
			this->buttonCardDeckSave->Click += gcnew System::EventHandler(this, &SettingsForm::buttonCardDeckSave_Click);
			// 
			// SettingsForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(484, 429);
			this->Controls->Add(this->tabControl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SettingsForm";
			this->Text = L"Card-G - Settings";
			this->tabControl->ResumeLayout(false);
			this->tabPageVirtualPlayer->ResumeLayout(false);
			this->tableLayoutPanelVirtualPlayer->ResumeLayout(false);
			this->groupBoxVirtualPlayerSpeed->ResumeLayout(false);
			this->groupBoxVirtualPlayerSpeed->PerformLayout();
			this->tabPageCardTheme->ResumeLayout(false);
			this->tableLayoutPanelCardTheme->ResumeLayout(false);
			this->groupBoxPreview->ResumeLayout(false);
			this->groupBoxCardFace->ResumeLayout(false);
			this->groupBoxCardFaceExtensionCards->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxChangeCard))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDoubleCard))->EndInit();
			this->groupBoxCardFaceBasicCards->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxStealCard))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMinusCard))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPlusCard))->EndInit();
			this->groupBoxCardBack->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCardBack))->EndInit();
			this->groupBoxCardColourScheme->ResumeLayout(false);
			this->groupBoxCardColourScheme->PerformLayout();
			this->tabPageCardDeck->ResumeLayout(false);
			this->tableLayoutPanelCardDeck->ResumeLayout(false);
			this->groupBoxBasicCards->ResumeLayout(false);
			this->groupBoxBasicCards->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardSteal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardPlus5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardPlus4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardPlus3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardPlus2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardPlus1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardMinus5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardMinus4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardMinus3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardMinus2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardMinus1))->EndInit();
			this->groupBoxExtensionCards->ResumeLayout(false);
			this->groupBoxExtensionCards->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardChange))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCardDouble))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void buttonVirtualPlayerReset_Click(System::Object^ sender, System::EventArgs^ e) {
		this->resetGameSettings();
	}

	private: System::Void buttonVirtualPlayerSave_Click(System::Object^ sender, System::EventArgs^ e) {
		this->saveGameSettings();
	}

	private: System::Void buttonCardThemeReset_Click(System::Object^ sender, System::EventArgs^ e) {
		this->resetGameSettings();
	}

	private: System::Void buttonCardThemeSave_Click(System::Object^ sender, System::EventArgs^ e) {
		this->saveGameSettings();
	}

	private: System::Void buttonCardDeckReset_Click(System::Object^ sender, System::EventArgs^ e) {
		this->resetGameSettings();
	}

	private: System::Void buttonCardDeckSave_Click(System::Object^ sender, System::EventArgs^ e) {
		this->saveGameSettings();
	}

	private: System::Void radioButtonBlack_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!this->radioButtonBlack->Checked)
		{
			return;
		}

		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
		this->pictureBoxCardBack->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("BlackCardBack")));
		this->pictureBoxMinusCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("BlackCardMinus1")));
		this->pictureBoxPlusCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("BlackCardPlus1")));
		this->pictureBoxStealCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("BlackCardSteal")));
		this->pictureBoxDoubleCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("BlackCardDouble")));
		this->pictureBoxChangeCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("BlackCardChange")));
	}

	private: System::Void radioButtonRed_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!this->radioButtonRed->Checked)
		{
			return;
		}

		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
		this->pictureBoxCardBack->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("RedCardBack")));
		this->pictureBoxMinusCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("RedCardMinus1")));
		this->pictureBoxPlusCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("RedCardPlus1")));
		this->pictureBoxStealCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("RedCardSteal")));
		this->pictureBoxDoubleCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("RedCardDouble")));
		this->pictureBoxChangeCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("RedCardChange")));
	}

	private: System::Void radioButtonGreen_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!this->radioButtonGreen->Checked)
		{
			return;
		}

		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
		this->pictureBoxCardBack->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("GreenCardBack")));
		this->pictureBoxMinusCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("GreenCardMinus1")));
		this->pictureBoxPlusCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("GreenCardPlus1")));
		this->pictureBoxStealCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("GreenCardSteal")));
		this->pictureBoxDoubleCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("GreenCardDouble")));
		this->pictureBoxChangeCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("GreenCardChange")));
	}

	private: System::Void radioButtonBlue_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!this->radioButtonBlue->Checked)
		{
			return;
		}

		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CardSelectionForm::typeid));
		this->pictureBoxCardBack->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("BlueCardBack")));
		this->pictureBoxMinusCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("BlueCardMinus1")));
		this->pictureBoxPlusCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("BlueCardPlus1")));
		this->pictureBoxStealCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("BlueCardSteal")));
		this->pictureBoxDoubleCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("BlueCardDouble")));
		this->pictureBoxChangeCard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject("BlueCardChange")));
	}

	private:
		// Loads the game settings.
		void loadGameSettings();

		// Resets the game settings.
		void resetGameSettings();

		// Saves the game settings.
		void saveGameSettings();
	};
}

