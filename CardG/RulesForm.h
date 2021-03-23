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
	/// Summary for RulesForm
	/// </summary>
	public ref class RulesForm : public System::Windows::Forms::Form
	{
	public:
		RulesForm(GameEngine^ gameEngine)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToParent();

			this->gameEngine = gameEngine;
			this->displayRules();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RulesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanelRules;
	private: System::Windows::Forms::PictureBox^ pictureBoxMinusCard;
	private: System::Windows::Forms::PictureBox^ pictureBoxChangeCard;
	private: System::Windows::Forms::PictureBox^ pictureBoxPlusCard;
	private: System::Windows::Forms::PictureBox^ pictureBoxStealCard;
	private: System::Windows::Forms::PictureBox^ pictureBoxDoubleCard;

	private:
		GameEngine^ gameEngine;

	private: System::Windows::Forms::RichTextBox^ richTextBoxCardMinus;
	private: System::Windows::Forms::RichTextBox^ richTextBoxCardPlus;
	private: System::Windows::Forms::RichTextBox^ richTextBoxCardSteal;
	private: System::Windows::Forms::RichTextBox^ richTextBoxCardDouble;
	private: System::Windows::Forms::RichTextBox^ richTextBoxCardChange;
	private: System::Windows::Forms::RichTextBox^ richTextBoxDescription;
	private: System::Windows::Forms::Label^ labelBasicCards;
	private: System::Windows::Forms::Label^ labelExtensionCards;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RulesForm::typeid));
			this->tableLayoutPanelRules = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pictureBoxChangeCard = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxMinusCard = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxPlusCard = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxStealCard = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDoubleCard = (gcnew System::Windows::Forms::PictureBox());
			this->richTextBoxCardMinus = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBoxCardPlus = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBoxCardSteal = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBoxCardDouble = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBoxCardChange = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBoxDescription = (gcnew System::Windows::Forms::RichTextBox());
			this->labelBasicCards = (gcnew System::Windows::Forms::Label());
			this->labelExtensionCards = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanelRules->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxChangeCard))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMinusCard))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPlusCard))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxStealCard))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDoubleCard))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanelRules
			// 
			this->tableLayoutPanelRules->ColumnCount = 2;
			this->tableLayoutPanelRules->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				70)));
			this->tableLayoutPanelRules->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				200)));
			this->tableLayoutPanelRules->Controls->Add(this->pictureBoxChangeCard, 0, 8);
			this->tableLayoutPanelRules->Controls->Add(this->pictureBoxMinusCard, 0, 3);
			this->tableLayoutPanelRules->Controls->Add(this->pictureBoxPlusCard, 0, 4);
			this->tableLayoutPanelRules->Controls->Add(this->pictureBoxStealCard, 0, 5);
			this->tableLayoutPanelRules->Controls->Add(this->pictureBoxDoubleCard, 0, 7);
			this->tableLayoutPanelRules->Controls->Add(this->richTextBoxCardMinus, 1, 3);
			this->tableLayoutPanelRules->Controls->Add(this->richTextBoxCardPlus, 1, 4);
			this->tableLayoutPanelRules->Controls->Add(this->richTextBoxCardSteal, 1, 5);
			this->tableLayoutPanelRules->Controls->Add(this->richTextBoxCardDouble, 1, 7);
			this->tableLayoutPanelRules->Controls->Add(this->richTextBoxCardChange, 1, 8);
			this->tableLayoutPanelRules->Controls->Add(this->richTextBoxDescription, 0, 0);
			this->tableLayoutPanelRules->Controls->Add(this->labelBasicCards, 0, 2);
			this->tableLayoutPanelRules->Controls->Add(this->labelExtensionCards, 0, 6);
			this->tableLayoutPanelRules->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanelRules->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanelRules->Name = L"tableLayoutPanelRules";
			this->tableLayoutPanelRules->RowCount = 9;
			this->tableLayoutPanelRules->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				75)));
			this->tableLayoutPanelRules->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				0)));
			this->tableLayoutPanelRules->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				12)));
			this->tableLayoutPanelRules->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				90)));
			this->tableLayoutPanelRules->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				90)));
			this->tableLayoutPanelRules->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				90)));
			this->tableLayoutPanelRules->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				12)));
			this->tableLayoutPanelRules->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				90)));
			this->tableLayoutPanelRules->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				90)));
			this->tableLayoutPanelRules->Size = System::Drawing::Size(724, 549);
			this->tableLayoutPanelRules->TabIndex = 0;
			// 
			// pictureBoxChangeCard
			// 
			this->pictureBoxChangeCard->Location = System::Drawing::Point(3, 462);
			this->pictureBoxChangeCard->Name = L"pictureBoxChangeCard";
			this->pictureBoxChangeCard->Size = System::Drawing::Size(62, 84);
			this->pictureBoxChangeCard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxChangeCard->TabIndex = 4;
			this->pictureBoxChangeCard->TabStop = false;
			// 
			// pictureBoxMinusCard
			// 
			this->pictureBoxMinusCard->Location = System::Drawing::Point(3, 90);
			this->pictureBoxMinusCard->Name = L"pictureBoxMinusCard";
			this->pictureBoxMinusCard->Size = System::Drawing::Size(62, 84);
			this->pictureBoxMinusCard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxMinusCard->TabIndex = 0;
			this->pictureBoxMinusCard->TabStop = false;
			// 
			// pictureBoxPlusCard
			// 
			this->pictureBoxPlusCard->Location = System::Drawing::Point(3, 180);
			this->pictureBoxPlusCard->Name = L"pictureBoxPlusCard";
			this->pictureBoxPlusCard->Size = System::Drawing::Size(62, 84);
			this->pictureBoxPlusCard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxPlusCard->TabIndex = 1;
			this->pictureBoxPlusCard->TabStop = false;
			// 
			// pictureBoxStealCard
			// 
			this->pictureBoxStealCard->Location = System::Drawing::Point(3, 270);
			this->pictureBoxStealCard->Name = L"pictureBoxStealCard";
			this->pictureBoxStealCard->Size = System::Drawing::Size(62, 84);
			this->pictureBoxStealCard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxStealCard->TabIndex = 2;
			this->pictureBoxStealCard->TabStop = false;
			// 
			// pictureBoxDoubleCard
			// 
			this->pictureBoxDoubleCard->Location = System::Drawing::Point(3, 372);
			this->pictureBoxDoubleCard->Name = L"pictureBoxDoubleCard";
			this->pictureBoxDoubleCard->Size = System::Drawing::Size(62, 84);
			this->pictureBoxDoubleCard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxDoubleCard->TabIndex = 3;
			this->pictureBoxDoubleCard->TabStop = false;
			// 
			// richTextBoxCardMinus
			// 
			this->richTextBoxCardMinus->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBoxCardMinus->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBoxCardMinus->Enabled = false;
			this->richTextBoxCardMinus->Location = System::Drawing::Point(73, 90);
			this->richTextBoxCardMinus->Name = L"richTextBoxCardMinus";
			this->richTextBoxCardMinus->Size = System::Drawing::Size(648, 84);
			this->richTextBoxCardMinus->TabIndex = 5;
			this->richTextBoxCardMinus->Text = L"";
			// 
			// richTextBoxCardPlus
			// 
			this->richTextBoxCardPlus->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBoxCardPlus->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBoxCardPlus->Enabled = false;
			this->richTextBoxCardPlus->Location = System::Drawing::Point(73, 180);
			this->richTextBoxCardPlus->Name = L"richTextBoxCardPlus";
			this->richTextBoxCardPlus->Size = System::Drawing::Size(648, 84);
			this->richTextBoxCardPlus->TabIndex = 6;
			this->richTextBoxCardPlus->Text = L"";
			// 
			// richTextBoxCardSteal
			// 
			this->richTextBoxCardSteal->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBoxCardSteal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBoxCardSteal->Enabled = false;
			this->richTextBoxCardSteal->Location = System::Drawing::Point(73, 270);
			this->richTextBoxCardSteal->Name = L"richTextBoxCardSteal";
			this->richTextBoxCardSteal->Size = System::Drawing::Size(648, 84);
			this->richTextBoxCardSteal->TabIndex = 7;
			this->richTextBoxCardSteal->Text = L"";
			// 
			// richTextBoxCardDouble
			// 
			this->richTextBoxCardDouble->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBoxCardDouble->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBoxCardDouble->Enabled = false;
			this->richTextBoxCardDouble->Location = System::Drawing::Point(73, 372);
			this->richTextBoxCardDouble->Name = L"richTextBoxCardDouble";
			this->richTextBoxCardDouble->Size = System::Drawing::Size(648, 84);
			this->richTextBoxCardDouble->TabIndex = 8;
			this->richTextBoxCardDouble->Text = L"";
			// 
			// richTextBoxCardChange
			// 
			this->richTextBoxCardChange->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBoxCardChange->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBoxCardChange->Enabled = false;
			this->richTextBoxCardChange->Location = System::Drawing::Point(73, 462);
			this->richTextBoxCardChange->Name = L"richTextBoxCardChange";
			this->richTextBoxCardChange->Size = System::Drawing::Size(648, 84);
			this->richTextBoxCardChange->TabIndex = 9;
			this->richTextBoxCardChange->Text = L"";
			// 
			// richTextBoxDescription
			// 
			this->richTextBoxDescription->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tableLayoutPanelRules->SetColumnSpan(this->richTextBoxDescription, 2);
			this->richTextBoxDescription->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBoxDescription->Enabled = false;
			this->richTextBoxDescription->Location = System::Drawing::Point(3, 3);
			this->richTextBoxDescription->Name = L"richTextBoxDescription";
			this->richTextBoxDescription->Size = System::Drawing::Size(718, 69);
			this->richTextBoxDescription->TabIndex = 10;
			this->richTextBoxDescription->Text = L"";
			// 
			// labelBasicCards
			// 
			this->tableLayoutPanelRules->SetColumnSpan(this->labelBasicCards, 2);
			this->labelBasicCards->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelBasicCards->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelBasicCards->Location = System::Drawing::Point(3, 75);
			this->labelBasicCards->Name = L"labelBasicCards";
			this->labelBasicCards->Size = System::Drawing::Size(718, 12);
			this->labelBasicCards->TabIndex = 11;
			this->labelBasicCards->Text = L"Basic Cards";
			this->labelBasicCards->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelExtensionCards
			// 
			this->tableLayoutPanelRules->SetColumnSpan(this->labelExtensionCards, 2);
			this->labelExtensionCards->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelExtensionCards->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelExtensionCards->Location = System::Drawing::Point(3, 357);
			this->labelExtensionCards->Name = L"labelExtensionCards";
			this->labelExtensionCards->Size = System::Drawing::Size(718, 12);
			this->labelExtensionCards->TabIndex = 12;
			this->labelExtensionCards->Text = L"Extension Cards";
			this->labelExtensionCards->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// RulesForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(724, 549);
			this->Controls->Add(this->tableLayoutPanelRules);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"RulesForm";
			this->Text = L"Card-G - Rules";
			this->tableLayoutPanelRules->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxChangeCard))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMinusCard))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPlusCard))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxStealCard))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxDoubleCard))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		// Displays the game rules.
		void displayRules();
	};
}

