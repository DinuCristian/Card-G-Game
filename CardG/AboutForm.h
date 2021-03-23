#pragma once

namespace CardG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AboutForm
	/// </summary>
	public ref class AboutForm : public System::Windows::Forms::Form
	{
	public:
		AboutForm(void)
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
		~AboutForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Label^ labelVersion;
	private: System::Windows::Forms::Label^ labelCopyright;
	private: System::Windows::Forms::Label^ labelCopyrightNotice;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel;
	private: System::Windows::Forms::PictureBox^ pictureBox;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutForm::typeid));
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->labelVersion = (gcnew System::Windows::Forms::Label());
			this->labelCopyright = (gcnew System::Windows::Forms::Label());
			this->labelCopyrightNotice = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// labelTitle
			// 
			this->labelTitle->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->Location = System::Drawing::Point(3, 0);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(340, 68);
			this->labelTitle->TabIndex = 1;
			this->labelTitle->Text = L"Card-G";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelVersion
			// 
			this->labelVersion->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelVersion->Location = System::Drawing::Point(3, 68);
			this->labelVersion->Name = L"labelVersion";
			this->labelVersion->Size = System::Drawing::Size(340, 34);
			this->labelVersion->TabIndex = 2;
			this->labelVersion->Text = L"Version 1.0.0";
			this->labelVersion->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelCopyright
			// 
			this->labelCopyright->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelCopyright->Location = System::Drawing::Point(3, 124);
			this->labelCopyright->Name = L"labelCopyright";
			this->labelCopyright->Size = System::Drawing::Size(340, 45);
			this->labelCopyright->TabIndex = 3;
			this->labelCopyright->Text = L"Copyright © 2020 Cristian Dinu.";
			this->labelCopyright->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelCopyrightNotice
			// 
			this->labelCopyrightNotice->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelCopyrightNotice->Location = System::Drawing::Point(3, 169);
			this->labelCopyrightNotice->Name = L"labelCopyrightNotice";
			this->labelCopyrightNotice->Size = System::Drawing::Size(340, 45);
			this->labelCopyrightNotice->TabIndex = 4;
			this->labelCopyrightNotice->Text = L"All rights reserved.";
			this->labelCopyrightNotice->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel
			// 
			this->tableLayoutPanel->ColumnCount = 1;
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel->Controls->Add(this->labelTitle, 0, 0);
			this->tableLayoutPanel->Controls->Add(this->labelVersion, 0, 1);
			this->tableLayoutPanel->Controls->Add(this->labelCopyrightNotice, 0, 4);
			this->tableLayoutPanel->Controls->Add(this->labelCopyright, 0, 3);
			this->tableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->tableLayoutPanel->Location = System::Drawing::Point(228, 0);
			this->tableLayoutPanel->Name = L"tableLayoutPanel";
			this->tableLayoutPanel->RowCount = 6;
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 30)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 15)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
			this->tableLayoutPanel->Size = System::Drawing::Size(346, 229);
			this->tableLayoutPanel->TabIndex = 5;
			// 
			// pictureBox
			// 
			this->pictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox.Image")));
			this->pictureBox->Location = System::Drawing::Point(0, 0);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(228, 229);
			this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox->TabIndex = 6;
			this->pictureBox->TabStop = false;
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(574, 229);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->tableLayoutPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AboutForm";
			this->Text = L"Card-G - About";
			this->tableLayoutPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

