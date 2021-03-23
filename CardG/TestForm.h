#pragma once

#include "TestCases.h"

namespace CardG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TestForm
	/// </summary>
	public ref class TestForm : public System::Windows::Forms::Form
	{
	public:
		TestForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToParent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TestForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel;
	protected:
	private: System::Windows::Forms::Button^ button;
	private: System::Windows::Forms::RichTextBox^ richTextBox;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TestForm::typeid));
			this->tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button = (gcnew System::Windows::Forms::Button());
			this->richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->tableLayoutPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel
			// 
			this->tableLayoutPanel->ColumnCount = 2;
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				88.8601F)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				11.1399F)));
			this->tableLayoutPanel->Controls->Add(this->button, 1, 1);
			this->tableLayoutPanel->Controls->Add(this->richTextBox, 0, 0);
			this->tableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel->Name = L"tableLayoutPanel";
			this->tableLayoutPanel->RowCount = 2;
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 90)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel->Size = System::Drawing::Size(1074, 729);
			this->tableLayoutPanel->TabIndex = 0;
			// 
			// button
			// 
			this->button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button->Location = System::Drawing::Point(957, 659);
			this->button->Name = L"button";
			this->button->Size = System::Drawing::Size(114, 67);
			this->button->TabIndex = 0;
			this->button->Text = L"Run";
			this->button->UseVisualStyleBackColor = true;
			this->button->Click += gcnew System::EventHandler(this, &TestForm::button_Click);
			// 
			// richTextBox
			// 
			this->richTextBox->BackColor = System::Drawing::SystemColors::Desktop;
			this->richTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tableLayoutPanel->SetColumnSpan(this->richTextBox, 2);
			this->richTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox->Location = System::Drawing::Point(3, 3);
			this->richTextBox->Name = L"richTextBox";
			this->richTextBox->Size = System::Drawing::Size(1068, 650);
			this->richTextBox->TabIndex = 1;
			this->richTextBox->Text = L"";
			// 
			// TestForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1074, 729);
			this->Controls->Add(this->tableLayoutPanel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(700, 500);
			this->Name = L"TestForm";
			this->Text = L"Card-G - Test";
			this->tableLayoutPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e) {
		TestCases^ testCases = gcnew TestCases(this->richTextBox);
		testCases->Run();
	}
	};
}

