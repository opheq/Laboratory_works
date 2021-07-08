#include "ErrorForm.h"
#include "Source.h"
#include <iostream>
#include <fstream>
#include <string>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

#pragma once

namespace Programm {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	static int pos;
	/// <summary>
	/// Сводка для ChangeForm
	/// </summary>
	public ref class ChangeForm : public System::Windows::Forms::Form
	{
	public:
		ChangeForm(int &position)
		{
			InitializeComponent();
			pos = position;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ChangeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  returnbutton;
	public: System::Windows::Forms::TextBox^  newnameBox;
	public: System::Windows::Forms::TextBox^  newgroupBox;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  AcceptChanges;
	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->returnbutton = (gcnew System::Windows::Forms::Button());
			this->newnameBox = (gcnew System::Windows::Forms::TextBox());
			this->newgroupBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->AcceptChanges = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// returnbutton
			// 
			this->returnbutton->Location = System::Drawing::Point(225, 67);
			this->returnbutton->Margin = System::Windows::Forms::Padding(2);
			this->returnbutton->Name = L"returnbutton";
			this->returnbutton->Size = System::Drawing::Size(81, 38);
			this->returnbutton->TabIndex = 0;
			this->returnbutton->Text = L"Отмена";
			this->returnbutton->UseVisualStyleBackColor = true;
			this->returnbutton->Click += gcnew System::EventHandler(this, &ChangeForm::returnbutton_Click);
			// 
			// newnameBox
			// 
			this->newnameBox->Location = System::Drawing::Point(11, 20);
			this->newnameBox->Margin = System::Windows::Forms::Padding(2);
			this->newnameBox->MaxLength = 60;
			this->newnameBox->Name = L"newnameBox";
			this->newnameBox->Size = System::Drawing::Size(206, 22);
			this->newnameBox->TabIndex = 1;
			// 
			// newgroupBox
			// 
			this->newgroupBox->Location = System::Drawing::Point(69, 59);
			this->newgroupBox->Margin = System::Windows::Forms::Padding(2);
			this->newgroupBox->Name = L"newgroupBox";
			this->newgroupBox->Size = System::Drawing::Size(85, 22);
			this->newgroupBox->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(97, 44);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Имя";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(97, 83);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Группа";
			// 
			// AcceptChanges
			// 
			this->AcceptChanges->Location = System::Drawing::Point(225, 17);
			this->AcceptChanges->Margin = System::Windows::Forms::Padding(2);
			this->AcceptChanges->Name = L"AcceptChanges";
			this->AcceptChanges->Size = System::Drawing::Size(81, 38);
			this->AcceptChanges->TabIndex = 5;
			this->AcceptChanges->Text = L"Применить";
			this->AcceptChanges->UseVisualStyleBackColor = true;
			this->AcceptChanges->Click += gcnew System::EventHandler(this, &ChangeForm::AcceptChanges_Click);
			// 
			// ChangeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(343, 118);
			this->Controls->Add(this->AcceptChanges);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->newgroupBox);
			this->Controls->Add(this->newnameBox);
			this->Controls->Add(this->returnbutton);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"ChangeForm";
			this->Text = L"ChangeForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void returnbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
private: System::Void AcceptChanges_Click(System::Object^  sender, System::EventArgs^  e) {
	std::fstream base("base.txt");
	NG nga;
	CD cda;
	int errorcode = 0;
	base.seekp(80 * (pos-1), std::ios::beg);
	if (strlen((const char*)(Marshal::StringToHGlobalAnsi(newnameBox->Text)).ToPointer()) > 0)
	{
		if (strlen((const char*)(Marshal::StringToHGlobalAnsi(newgroupBox->Text)).ToPointer()) > 0)
		{
			char *newnewname = { (char*)(Marshal::StringToHGlobalAnsi(newnameBox->Text)).ToPointer() };
			char *newnewgroup = { (char*)(Marshal::StringToHGlobalAnsi(newgroupBox->Text)).ToPointer() };
			strcpy_s(nga.name, 60, newnewname);
			strcpy_s(nga.group, 20, newnewgroup);
			_strlwr_s(nga.name);
			nga.name[0] = toupper(nga.name[0]);
			base.write((char*)&nga, sizeof(nga));
			base.close();
			Close();
		}
		else
		{
			errorcode = 2;
			Programm::ErrorForm^ err = gcnew ErrorForm(errorcode);
			err->ShowDialog();
		}
		
	}
	else {
		errorcode = 1;
		Programm::ErrorForm^ err = gcnew ErrorForm(errorcode);
		err->ShowDialog();
	}
}
};
}