#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

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
	/// Сводка для ResultSearchForm
	/// </summary>
	public ref class ResultSearchForm : public System::Windows::Forms::Form
	{
	public:
		ResultSearchForm(char *ffn, char *lln,char *kkurs, char *nnapr)
		{
			InitializeComponent();
			char* fnsearch = ffn;
			char* lnsearch = lln;
			char* kurssearch = kkurs;
			char* naprsearch = nnapr;
			bool fncheck;
			bool lncheck;
			bool kurscheck;
			bool naprcheck;
			char* searchfn;
			char* searchln;
			char* searchkurs;
			char* searchnapr;
			int pos=0;
			int i = 0;
			String^ connectionString = "provider = Microsoft.Jet.OLEDB.4.0; data source = Students.mdb";
			OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
			OleDbCommand^ command = conn->CreateCommand();
			command->CommandText = "SELECT * FROM Students";
			conn->Open();
			OleDbDataReader^ dataReader = command->ExecuteReader();
			while (dataReader->Read())
			{
				searchfn = ((char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["fn"]))).ToPointer());
				searchln =((char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["ln"]))).ToPointer());
				searchkurs = ((char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["kurs"]))).ToPointer());
				searchnapr= (char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["napr"]))).ToPointer();
				pos++;
				if (strstr(searchfn, fnsearch) != NULL)
				{
					fncheck = true;
				}
				else if (fnsearch == NULL)
					fncheck = true;
				else fncheck = false;
				if (strstr(searchln, lnsearch) != NULL)
				{
					lncheck = true;
				}
				else if (lnsearch == NULL)
					lncheck = true;
				else lncheck = false;
				if (strstr(searchkurs, kurssearch) != NULL)
				{
					kurscheck = true;
				}
				else if (kurssearch == NULL)
					kurscheck = true;
				else kurscheck = false;
				if (strstr(searchnapr, naprsearch) != NULL)
				{
					naprcheck = true;
				}
				else if (naprsearch == NULL)
					naprcheck = true;
				else naprcheck = false;
				if (fncheck == true && lncheck == true && kurscheck == true && naprcheck==true)
				{
			
					DataTable->Rows->Add();
					DataTable->Rows[i]->Cells[0]->Value = pos;
					DataTable->Rows[i]->Cells[1]->Value = gcnew System::String(searchfn);
					DataTable->Rows[i]->Cells[2]->Value = gcnew System::String(searchln);
					DataTable->Rows[i]->Cells[3]->Value = gcnew System::String(searchkurs);
					DataTable->Rows[i]->Cells[4]->Value = gcnew System::String(searchnapr);
					i++;
				}

			}
			conn->Close();
			dataReader->Close();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ResultSearchForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  DataTable;
	protected:

	protected:




	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  position;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  fn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ln;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  kurs;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  napr;











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
			this->DataTable = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->position = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->fn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ln = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->kurs = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->napr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataTable))->BeginInit();
			this->SuspendLayout();
			// 
			// DataTable
			// 
			this->DataTable->AllowUserToAddRows = false;
			this->DataTable->AllowUserToDeleteRows = false;
			this->DataTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DataTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->position, this->fn,
					this->ln, this->kurs, this->napr
			});
			this->DataTable->Location = System::Drawing::Point(12, 12);
			this->DataTable->Name = L"DataTable";
			this->DataTable->ReadOnly = true;
			this->DataTable->RowTemplate->Height = 24;
			this->DataTable->Size = System::Drawing::Size(936, 400);
			this->DataTable->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(954, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 400);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Закрыть";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ResultSearchForm::button1_Click);
			// 
			// position
			// 
			this->position->HeaderText = L"Позиция";
			this->position->Name = L"position";
			this->position->ReadOnly = true;
			// 
			// fn
			// 
			this->fn->HeaderText = L"Имя";
			this->fn->Name = L"fn";
			this->fn->ReadOnly = true;
			this->fn->Width = 200;
			// 
			// ln
			// 
			this->ln->HeaderText = L"Фамилия";
			this->ln->Name = L"ln";
			this->ln->ReadOnly = true;
			this->ln->Width = 150;
			// 
			// kurs
			// 
			this->kurs->HeaderText = L"Курс";
			this->kurs->Name = L"kurs";
			this->kurs->ReadOnly = true;
			this->kurs->Width = 125;
			// 
			// napr
			// 
			this->napr->HeaderText = L"Направление";
			this->napr->Name = L"napr";
			this->napr->ReadOnly = true;
			this->napr->Width = 125;
			// 
			// ResultSearchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1041, 420);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->DataTable);
			this->Name = L"ResultSearchForm";
			this->Text = L"ResultSearchForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataTable))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
};
}
