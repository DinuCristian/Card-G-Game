#pragma once

#include "GameForm.h"

namespace CardG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Summary for NameForm
	/// </summary>
	public ref class NameForm : public System::Windows::Forms::Form
	{
	public:
		NameForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToScreen();
			this->textBoxPlayerName->Text = Environment::UserName;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NameForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button;
	private: System::Windows::Forms::TextBox^ textBoxPlayerName;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel;
	private: System::Windows::Forms::Label^ labelPlayerName;

	private:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NameForm::typeid));
			this->button = (gcnew System::Windows::Forms::Button());
			this->textBoxPlayerName = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelPlayerName = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// button
			// 
			this->button->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button->Location = System::Drawing::Point(121, 33);
			this->button->Name = L"button";
			this->button->Size = System::Drawing::Size(50, 24);
			this->button->TabIndex = 1;
			this->button->Text = L"OK";
			this->button->UseVisualStyleBackColor = true;
			this->button->Click += gcnew System::EventHandler(this, &NameForm::button_Click);
			// 
			// textBoxPlayerName
			// 
			this->textBoxPlayerName->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxPlayerName->Location = System::Drawing::Point(72, 3);
			this->textBoxPlayerName->MaxLength = 15;
			this->textBoxPlayerName->Name = L"textBoxPlayerName";
			this->textBoxPlayerName->Size = System::Drawing::Size(99, 31);
			this->textBoxPlayerName->TabIndex = 0;
			this->textBoxPlayerName->Text = "";
			this->textBoxPlayerName->TextChanged += gcnew System::EventHandler(this, &NameForm::textBoxPlayerName_TextChanged);
			this->textBoxPlayerName->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &NameForm::textBoxPlayerName_KeyDown);
			// 
			// tableLayoutPanel
			// 
			this->tableLayoutPanel->ColumnCount = 2;
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60)));
			this->tableLayoutPanel->Controls->Add(this->labelPlayerName, 0, 0);
			this->tableLayoutPanel->Controls->Add(this->button, 1, 1);
			this->tableLayoutPanel->Controls->Add(this->textBoxPlayerName, 1, 0);
			this->tableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel->Name = L"tableLayoutPanel";
			this->tableLayoutPanel->RowCount = 2;
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel->Size = System::Drawing::Size(174, 29);
			this->tableLayoutPanel->TabIndex = 3;
			// 
			// labelPlayerName
			// 
			this->labelPlayerName->AutoSize = true;
			this->labelPlayerName->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelPlayerName->Location = System::Drawing::Point(3, 0);
			this->labelPlayerName->Name = L"labelPlayerName";
			this->labelPlayerName->Size = System::Drawing::Size(63, 30);
			this->labelPlayerName->TabIndex = 4;
			this->labelPlayerName->Text = L"Your Name:";
			this->labelPlayerName->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// NameForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(174, 29);
			this->Controls->Add(this->tableLayoutPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(200, 100);
			this->Name = L"NameForm";
			this->Text = L"Card-G - Your Name";
			this->tableLayoutPanel->ResumeLayout(false);
			this->tableLayoutPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void textBoxPlayerName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->textBoxPlayerName->Text->Length > 0 && Regex::IsMatch(this->textBoxPlayerName->Text, "[a-zA-Z]"))
		{
			this->button->Enabled = true;
		}
		else
		{
			this->button->Enabled = false;
		}
	}

	private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e) {
		startGame();
	}

	private: System::Void textBoxPlayerName_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter)
		{
			e->SuppressKeyPress = true;
			startGame();
		}
	}

	private:
		// Starts the game.
		void startGame();
	};
}

