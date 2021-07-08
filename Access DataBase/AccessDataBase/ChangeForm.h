#pragma once
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include "ErrorForm.h"
namespace AccessDataBase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;
	using namespace System::Runtime::InteropServices;
	static char *cfn;
	static char *cln;
	static char *ckurs;
	static char *cnapr;
	/// <summary>
	/// Сводка для ChangeForm
	/// </summary>
	public ref class ChangeForm : public System::Windows::Forms::Form
	{
	public:
		ChangeForm(char *changefn, char *changeln, char *changekurs, char *changenapr)
		{
			InitializeComponent();
			cfn = changefn;
			cln = changeln;
			ckurs = changekurs;
			cnapr = changenapr;
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
	public: System::Windows::Forms::TextBox^  newfn;
	public: System::Windows::Forms::TextBox^  newln;

	public: System::Windows::Forms::TextBox^  newkurs;
	protected:
	public:
	protected:

	protected:

	public:

	protected:

	protected:



	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	public: System::Windows::Forms::MaskedTextBox^  newnapr;
	private:

	private:


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
			this->newln = (gcnew System::Windows::Forms::TextBox());
			this->newkurs = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->newnapr = (gcnew System::Windows::Forms::MaskedTextBox());
			this->SuspendLayout();
			// 
			// newfn
			// 
			this->newfn->Location = System::Drawing::Point(194, 139);
			this->newfn->MaxLength = 60;
			this->newfn->Name = L"newfn";
			this->newfn->Size = System::Drawing::Size(214, 22);
			this->newfn->TabIndex = 0;
			// 
			// newln
			// 
			this->newln->Location = System::Drawing::Point(194, 167);
			this->newln->MaxLength = 60;
			this->newln->Name = L"newln";
			this->newln->Size = System::Drawing::Size(214, 22);
			this->newln->TabIndex = 1;
			// 
			// newkurs
			// 
			this->newkurs->Location = System::Drawing::Point(194, 195);
			this->newkurs->MaxLength = 60;
			this->newkurs->Name = L"newkurs";
			this->newkurs->Size = System::Drawing::Size(100, 22);
			this->newkurs->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(300, 195);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 46);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Применить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ChangeForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(421, 25);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Измените данные и нажмите \"Применить\"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(72, 144);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Имя";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(86, 228);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Направление";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(142, 200);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Курс";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(93, 172);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(70, 17);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Фамилия";
			// 
			// newnapr
			// 
			this->newnapr->Location = System::Drawing::Point(194, 223);
			this->newnapr->Name = L"newnapr";
			this->newnapr->Size = System::Drawing::Size(100, 22);
			this->newnapr->TabIndex = 10;
			// 
			// ChangeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(436, 251);
			this->Controls->Add(this->newnapr);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->newkurs);
			this->Controls->Add(this->newln);
			this->Controls->Add(this->newfn);
			this->Name = L"ChangeForm";
			this->Text = L"ChangeForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (strlen((const char*)(Marshal::StringToHGlobalAnsi(newfn->Text)).ToPointer()) > 0)
		{
			if (strlen((const char*)(Marshal::StringToHGlobalAnsi(newln->Text)).ToPointer()) > 0)
			{
				if (strlen((const char*)(Marshal::StringToHGlobalAnsi(newkurs->Text)).ToPointer()) > 0)
				{
					if (strlen((const char*)(Marshal::StringToHGlobalAnsi(newnapr->Text)).ToPointer()) > 0)
					{
						std::string str = (char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(newnapr->Text))).ToPointer();
						String^ connectionString = "provider = Microsoft.Jet.OLEDB.4.0; data source = Students.mdb";
						OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
						OleDbCommand^ command = conn->CreateCommand();
						command->CommandText = "UPDATE Students set fn='" + gcnew System::String(newfn->Text) + "' , ln='" + gcnew System::String(newln->Text) + "' , kurs='" + gcnew System::String(newkurs->Text) + "' , napr='" + gcnew System::String(newnapr->Text) + "' WHERE fn='" + gcnew System::String(cfn)	+ "' and ln='" + gcnew System::String(cln)+ "' and kurs='" + gcnew System::String(ckurs) + "';";
						int k = 0;
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
				else {
					ErrorForm^ form = gcnew ErrorForm();
					form->ShowDialog();
				}
			}
			else {
				ErrorForm^ form = gcnew ErrorForm();
				form->ShowDialog();
			}
		}
		else {
			ErrorForm^ form = gcnew ErrorForm();
			form->ShowDialog();
		}
	}
	};
}
