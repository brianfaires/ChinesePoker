#pragma once
#include "stdafx.h"
#include "Dealer.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ChinesePoker {
	public ref class SimForm : public System::Windows::Forms::Form
	{
	public:
		SimForm(System::Windows::Forms::Form^ _parent, Dealer^ dealer)
		{
			InitializeComponent();
			parent = _parent;
			table = dealer;
		}

	protected:
		~SimForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Dealer^ table;
	private: System::Windows::Forms::Form^ parent;

	#pragma region Windows Form Designer generated code
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::ProgressBar^  progressBar2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Button^  btn_begin;
	private: System::Windows::Forms::Button^  btn_pause;
	private: System::Windows::Forms::Button^  btn_save;
	private: System::Windows::Forms::Button^  btn_ellipses;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;

	private:
		System::ComponentModel::Container ^components;

		void InitializeComponent(void)
		{
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->btn_begin = (gcnew System::Windows::Forms::Button());
			this->btn_pause = (gcnew System::Windows::Forms::Button());
			this->btn_save = (gcnew System::Windows::Forms::Button());
			this->btn_ellipses = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			this->numericUpDown1->Location = System::Drawing::Point(283, 12);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000000000, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(96, 20);
			this->numericUpDown1->TabIndex = 0;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000000, 0, 0, 0});
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, 0});
			this->numericUpDown2->Location = System::Drawing::Point(283, 38);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000000, 0, 0, 0});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(96, 20);
			this->numericUpDown2->TabIndex = 1;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, 0});
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(154, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Total Hands to Simulate:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(134, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(143, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Hands between data dumps:";
			// 
			// progressBar1
			// 
			this->progressBar1->BackColor = System::Drawing::SystemColors::Control;
			this->progressBar1->Location = System::Drawing::Point(12, 284);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(367, 23);
			this->progressBar1->TabIndex = 4;
			// 
			// progressBar2
			// 
			this->progressBar2->BackColor = System::Drawing::SystemColors::Control;
			this->progressBar2->Location = System::Drawing::Point(12, 255);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(367, 23);
			this->progressBar2->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::Control;
			this->label3->Location = System::Drawing::Point(147, 260);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Current data dump";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::Control;
			this->label4->Location = System::Drawing::Point(154, 288);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(75, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Total Progress";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(246, 64);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(133, 17);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Learn after each dump";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// btn_begin
			// 
			this->btn_begin->Enabled = false;
			this->btn_begin->Location = System::Drawing::Point(12, 9);
			this->btn_begin->Name = L"btn_begin";
			this->btn_begin->Size = System::Drawing::Size(101, 96);
			this->btn_begin->TabIndex = 9;
			this->btn_begin->Text = L"Begin Simulation";
			this->btn_begin->UseVisualStyleBackColor = true;
			this->btn_begin->Click += gcnew System::EventHandler(this, &SimForm::btn_begin_Click);
			// 
			// btn_pause
			// 
			this->btn_pause->Enabled = false;
			this->btn_pause->Location = System::Drawing::Point(12, 111);
			this->btn_pause->Name = L"btn_pause";
			this->btn_pause->Size = System::Drawing::Size(101, 44);
			this->btn_pause->TabIndex = 10;
			this->btn_pause->Text = L"Pause Simulation";
			this->btn_pause->UseVisualStyleBackColor = true;
			this->btn_pause->Click += gcnew System::EventHandler(this, &SimForm::btn_pause_Click);
			// 
			// btn_save
			// 
			this->btn_save->Enabled = false;
			this->btn_save->Location = System::Drawing::Point(12, 161);
			this->btn_save->Name = L"btn_save";
			this->btn_save->Size = System::Drawing::Size(101, 44);
			this->btn_save->TabIndex = 11;
			this->btn_save->Text = L"Save data to:";
			this->btn_save->UseVisualStyleBackColor = true;
			this->btn_save->Click += gcnew System::EventHandler(this, &SimForm::btn_save_Click);
			// 
			// btn_ellipses
			// 
			this->btn_ellipses->Location = System::Drawing::Point(345, 211);
			this->btn_ellipses->Name = L"btn_ellipses";
			this->btn_ellipses->Size = System::Drawing::Size(34, 20);
			this->btn_ellipses->TabIndex = 12;
			this->btn_ellipses->Text = L"...";
			this->btn_ellipses->UseVisualStyleBackColor = true;
			this->btn_ellipses->Click += gcnew System::EventHandler(this, &SimForm::btn_ellipses_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 211);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(327, 20);
			this->textBox1->TabIndex = 13;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &SimForm::textBox1_TextChanged);
			// 
			// SimForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(391, 314);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btn_ellipses);
			this->Controls->Add(this->btn_save);
			this->Controls->Add(this->btn_pause);
			this->Controls->Add(this->btn_begin);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->progressBar2);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Name = L"SimForm";
			this->Text = L"SimForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SimForm::SimForm_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btn_begin_Click(System::Object^, System::EventArgs^) {
		btn_begin->Enabled = false;
		btn_pause->Enabled = true;
		table->brain->myStats->LoadFromFile("stats.txt");
		table->brain->Learn();
		int batchSize = (int)numericUpDown2->Value;
		bool learning = checkBox1->Checked;
		for(int i = 0; i < numericUpDown1->Value; i += batchSize)
		{
			table->SimHands(batchSize);
			table->brain->myStats->DumpToFile(textBox1->Text->Substring(0, textBox1->Text->Length - 4) + (i/batchSize).ToString() + ".txt");
			if(learning)
				table->brain->Learn();
			btn_pause->Update();
		}					
		if(textBox1->Text != "")
			table->brain->myStats->DumpToFile(textBox1->Text);
		btn_pause->Enabled = false;
	 }
	private: System::Void btn_pause_Click(System::Object^, System::EventArgs^) {
		if(btn_save->Enabled)
		{
			btn_save->Enabled = false;
			btn_pause->Text = "Pause Simulation";
		}
		else
		{
			btn_save->Enabled = true;
			btn_pause->Text = "Resume Simulation";
		}
	}
	private: System::Void btn_save_Click(System::Object^, System::EventArgs^) {
	}
	private: System::Void SimForm_FormClosed(System::Object^, System::Windows::Forms::FormClosedEventArgs^) {
		 parent->Enabled = true;
	}
	private: System::Void btn_ellipses_Click(System::Object^, System::EventArgs^) {
		saveFileDialog1->ShowDialog();
		if(saveFileDialog1->FileName)
		{
			textBox1->Text = saveFileDialog1->FileName;
			saveFileDialog1->Reset();
		}
	}
	private: System::Void textBox1_TextChanged(System::Object^, System::EventArgs^) {
		btn_begin->Enabled = true;
	}
};
}
