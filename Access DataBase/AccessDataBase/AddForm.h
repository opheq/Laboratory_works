#pragma once
#include "ErrorForm.h"
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include <string.h>
#include <algorithm>
#include <string>
namespace AccessDataBase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Сводка для AddForm
	/// </summary>
	public ref class AddForm : public System::Windows::Forms::Form
	{
	public:
		AddForm()
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  newfn;

	private: System::Windows::Forms::MaskedTextBox^  newnapr;
	protected:



	protected:

	protected:



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;



	private: System::Windows::Forms::Button^  addbutton;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  newln;
	private: System::Windows::Forms::TextBox^  newkurs;

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
			this->newfn = (gcnew System::Windows::Forms::TextBox());
			this->newnapr = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->addbutton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->newln = (gcnew System::Windows::Forms::TextBox());
			this->newkurs = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// newfn
			// 
			this->newfn->Location = System::Drawing::Point(129, 12);
			this->newfn->MaxLength = 40;
			this->newfn->Name = L"newfn";
			this->newfn->Size = System::Drawing::Size(224, 22);
			this->newfn->TabIndex = 3;
			// 
			// newnapr
			// 
			this->newnapr->Location = System::Drawing::Point(129, 98);
			this->newnapr->Name = L"newnapr";
			this->newnapr->Size = System::Drawing::Size(100, 22);
			this->newnapr->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(84, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"ИМЯ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(42, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"ФАМИЛИЯ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(79, 70);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"КУРС";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 97);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(112, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"НАПРАВЛЕНИЕ";
			// 
			// addbutton
			// 
			this->addbutton->Location = System::Drawing::Point(235, 70);
			this->addbutton->Name = L"addbutton";
			this->addbutton->Size = System::Drawing::Size(80, 50);
			this->addbutton->TabIndex = 11;
			this->addbutton->Text = L"Добавить";
			this->addbutton->UseVisualStyleBackColor = true;
			this->addbutton->Click += gcnew System::EventHandler(this, &AddForm::addbutton_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(321, 70);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(32, 50);
			this->button1->TabIndex = 12;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddForm::button1_Click);
			// 
			// newln
			// 
			this->newln->Location = System::Drawing::Point(129, 44);
			this->newln->Name = L"newln";
			this->newln->Size = System::Drawing::Size(224, 22);
			this->newln->TabIndex = 13;
			// 
			// newkurs
			// 
			this->newkurs->Location = System::Drawing::Point(129, 72);
			this->newkurs->Name = L"newkurs";
			this->newkurs->Size = System::Drawing::Size(100, 22);
			this->newkurs->TabIndex = 14;
			// 
			// AddForm
			// 
			this->AcceptButton = this->addbutton;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(359, 129);
			this->ControlBox = false;
			this->Controls->Add(this->newkurs);
			this->Controls->Add(this->newln);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->addbutton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->newnapr);
			this->Controls->Add(this->newfn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"AddForm";
			this->Text = L"Добавить нового студента";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
	private: System::Void addbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		bool error = false;
		char* chkerr;
		chkerr = (char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(newfn->Text))).ToPointer();
		if (strlen(chkerr) == 0 || chkerr == NULL || strstr(chkerr, "  ") != NULL)
		{
			error = true;
		}
		chkerr = (char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(newln->Text))).ToPointer();
		if (strlen(chkerr) == 0 || chkerr == NULL || strstr(chkerr, "  ") != NULL)
		{
			error = true;
		}
		chkerr = (char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(newkurs->Text))).ToPointer();
		if (strlen(chkerr) == 0 || chkerr == NULL||strstr(chkerr,"  ")!=NULL)
		{
			error = true;
		}
		chkerr = (char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(newnapr->Text))).ToPointer();
		if (strlen(chkerr) == 0 || chkerr == NULL || strstr(chkerr, "  ") != NULL)
		{
			error = true;
		}
		if (error == false)
		{
			
			String^ connectionString = "provider = Microsoft.Jet.OLEDB.4.0; data source = Students.mdb";
			OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
			OleDbCommand^ command = conn->CreateCommand();
			command->CommandText = "INSERT INTO Students (fn, ln, kurs, napr) VALUES ('" + gcnew System::String(newfn->Text) + "','" + gcnew System::String(newln->Text) + "','" + gcnew System::String(newkurs->Text) + "','" + gcnew System::String(newnapr->Text) + "')";
			conn->Open();
			command->ExecuteNonQuery();
			conn->Close();
			Close();
		}
		else {
			ErrorForm^ form = gcnew ErrorForm();
			form->ShowDialog();
		}
	}
};
}
