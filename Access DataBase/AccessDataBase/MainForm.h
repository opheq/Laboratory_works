
#pragma once
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include "AddForm.h"
#include "ResultSearchForm.h"
#include "SearchForm.h"
#include "ChangeForm.h"
namespace AccessDataBase {
	static int pos=1;
	static int numofelements = 0;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;
	using namespace System::Runtime::InteropServices;
	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			int i = 0;
			InitializeComponent();
			String^ connectionString = "provider = Microsoft.Jet.OLEDB.4.0; data source = Students.mdb";
			OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
			OleDbCommand^ command = conn->CreateCommand();
			command->CommandText = "SELECT * FROM Students";
			conn->Open();
			OleDbDataReader^ dataReader = command->ExecuteReader();
			while (dataReader->Read())
			{
				i++;
				if (i == pos)
				{
					fn->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["fn"]))).ToPointer());
					ln->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["ln"]))).ToPointer());
					kurs->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["kurs"]))).ToPointer());
					napr->Text = 0 + gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["napr"]))).ToPointer());
					
				}
				numofelements++;
			}
			number->Text = pos + "/" + numofelements;
			dataReader->Close();
			if (numofelements == 0 || numofelements == 1)
			{
				lastbutton->Enabled = false;
				nextbutton->Enabled = false;
			}
			firstbutton->Enabled = false;
			if (numofelements == 0)
				deletebutton->Enabled = false;
			else
				deletebutton->Enabled = true;
			if (numofelements == 2)
			{
				prevbutton->Enabled = false;
				nextbutton->Enabled = false;
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  nextbutton;
	protected:
	private: System::Windows::Forms::Button^  lastbutton;
	private: System::Windows::Forms::Button^  firstbutton;
	private: System::Windows::Forms::Button^  prevbutton;
	private: System::Windows::Forms::TextBox^  fn;
	private: System::Windows::Forms::TextBox^  ln;










	private: System::Windows::Forms::Label^  label;
	private: System::Windows::Forms::Button^  addnewbutton;
	private: System::Windows::Forms::Button^  deletebutton;
	private: System::Windows::Forms::Button^  searchbutton;

	private: System::Windows::Forms::TextBox^  kurs;
	private: System::Windows::Forms::MaskedTextBox^  napr;




	private: System::Windows::Forms::Button^  changebutton;
	private: System::Windows::Forms::Button^  number;


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
			this->nextbutton = (gcnew System::Windows::Forms::Button());
			this->lastbutton = (gcnew System::Windows::Forms::Button());
			this->firstbutton = (gcnew System::Windows::Forms::Button());
			this->prevbutton = (gcnew System::Windows::Forms::Button());
			this->fn = (gcnew System::Windows::Forms::TextBox());
			this->ln = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->addnewbutton = (gcnew System::Windows::Forms::Button());
			this->deletebutton = (gcnew System::Windows::Forms::Button());
			this->searchbutton = (gcnew System::Windows::Forms::Button());
			this->kurs = (gcnew System::Windows::Forms::TextBox());
			this->napr = (gcnew System::Windows::Forms::MaskedTextBox());
			this->changebutton = (gcnew System::Windows::Forms::Button());
			this->number = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// nextbutton
			// 
			this->nextbutton->Location = System::Drawing::Point(242, 201);
			this->nextbutton->Name = L"nextbutton";
			this->nextbutton->Size = System::Drawing::Size(75, 23);
			this->nextbutton->TabIndex = 0;
			this->nextbutton->Text = L">";
			this->nextbutton->UseVisualStyleBackColor = true;
			this->nextbutton->Click += gcnew System::EventHandler(this, &MainForm::nextbutton_Click);
			// 
			// lastbutton
			// 
			this->lastbutton->Location = System::Drawing::Point(341, 201);
			this->lastbutton->Name = L"lastbutton";
			this->lastbutton->Size = System::Drawing::Size(75, 23);
			this->lastbutton->TabIndex = 1;
			this->lastbutton->Text = L">>";
			this->lastbutton->UseVisualStyleBackColor = true;
			this->lastbutton->Click += gcnew System::EventHandler(this, &MainForm::lastbutton_Click);
			// 
			// firstbutton
			// 
			this->firstbutton->Location = System::Drawing::Point(44, 201);
			this->firstbutton->Name = L"firstbutton";
			this->firstbutton->Size = System::Drawing::Size(75, 23);
			this->firstbutton->TabIndex = 2;
			this->firstbutton->Text = L"<<";
			this->firstbutton->UseVisualStyleBackColor = true;
			this->firstbutton->Click += gcnew System::EventHandler(this, &MainForm::firstbutton_Click);
			// 
			// prevbutton
			// 
			this->prevbutton->Location = System::Drawing::Point(143, 201);
			this->prevbutton->Name = L"prevbutton";
			this->prevbutton->Size = System::Drawing::Size(75, 23);
			this->prevbutton->TabIndex = 3;
			this->prevbutton->Text = L"<";
			this->prevbutton->UseVisualStyleBackColor = true;
			this->prevbutton->Click += gcnew System::EventHandler(this, &MainForm::prevbutton_Click);
			// 
			// fn
			// 
			this->fn->Location = System::Drawing::Point(143, 12);
			this->fn->Name = L"fn";
			this->fn->ReadOnly = true;
			this->fn->Size = System::Drawing::Size(174, 22);
			this->fn->TabIndex = 5;
			// 
			// ln
			// 
			this->ln->Location = System::Drawing::Point(143, 40);
			this->ln->Name = L"ln";
			this->ln->ReadOnly = true;
			this->ln->Size = System::Drawing::Size(174, 22);
			this->ln->TabIndex = 8;
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Location = System::Drawing::Point(87, 48);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(0, 17);
			this->label->TabIndex = 9;
			// 
			// addnewbutton
			// 
			this->addnewbutton->Location = System::Drawing::Point(44, 172);
			this->addnewbutton->Name = L"addnewbutton";
			this->addnewbutton->Size = System::Drawing::Size(174, 23);
			this->addnewbutton->TabIndex = 10;
			this->addnewbutton->Text = L"Add";
			this->addnewbutton->UseVisualStyleBackColor = true;
			this->addnewbutton->Click += gcnew System::EventHandler(this, &MainForm::addnewbutton_Click);
			// 
			// deletebutton
			// 
			this->deletebutton->Location = System::Drawing::Point(242, 172);
			this->deletebutton->Name = L"deletebutton";
			this->deletebutton->Size = System::Drawing::Size(174, 23);
			this->deletebutton->TabIndex = 11;
			this->deletebutton->Text = L"Delete";
			this->deletebutton->UseVisualStyleBackColor = true;
			this->deletebutton->Click += gcnew System::EventHandler(this, &MainForm::deletebutton_Click);
			// 
			// searchbutton
			// 
			this->searchbutton->Location = System::Drawing::Point(44, 125);
			this->searchbutton->Name = L"searchbutton";
			this->searchbutton->Size = System::Drawing::Size(174, 31);
			this->searchbutton->TabIndex = 12;
			this->searchbutton->Text = L"Search";
			this->searchbutton->UseVisualStyleBackColor = true;
			this->searchbutton->Click += gcnew System::EventHandler(this, &MainForm::searchbutton_Click);
			// 
			// kurs
			// 
			this->kurs->Location = System::Drawing::Point(143, 68);
			this->kurs->Name = L"kurs";
			this->kurs->ReadOnly = true;
			this->kurs->Size = System::Drawing::Size(75, 22);
			this->kurs->TabIndex = 14;
			// 
			// napr
			// 
			this->napr->BackColor = System::Drawing::SystemColors::Menu;
			this->napr->HideSelection = false;
			this->napr->Location = System::Drawing::Point(242, 68);
			this->napr->Name = L"napr";
			this->napr->Size = System::Drawing::Size(75, 22);
			this->napr->TabIndex = 15;
			this->napr->ValidatingType = System::DateTime::typeid;
			// 
			// changebutton
			// 
			this->changebutton->Location = System::Drawing::Point(242, 125);
			this->changebutton->Name = L"changebutton";
			this->changebutton->Size = System::Drawing::Size(174, 30);
			this->changebutton->TabIndex = 16;
			this->changebutton->Text = L"Change";
			this->changebutton->UseVisualStyleBackColor = true;
			this->changebutton->Click += gcnew System::EventHandler(this, &MainForm::changebutton_Click);
			// 
			// number
			// 
			this->number->Enabled = false;
			this->number->Location = System::Drawing::Point(191, 96);
			this->number->Name = L"number";
			this->number->Size = System::Drawing::Size(75, 23);
			this->number->TabIndex = 17;
			this->number->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(479, 249);
			this->Controls->Add(this->number);
			this->Controls->Add(this->changebutton);
			this->Controls->Add(this->napr);
			this->Controls->Add(this->kurs);
			this->Controls->Add(this->searchbutton);
			this->Controls->Add(this->deletebutton);
			this->Controls->Add(this->addnewbutton);
			this->Controls->Add(this->label);
			this->Controls->Add(this->ln);
			this->Controls->Add(this->fn);
			this->Controls->Add(this->prevbutton);
			this->Controls->Add(this->firstbutton);
			this->Controls->Add(this->lastbutton);
			this->Controls->Add(this->nextbutton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"MainForm";
			this->Text = L"Студенты";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void nextbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	int i = 0;
	pos++;
	if (pos > numofelements)
		pos = numofelements;
	String^ connectionString = "provider = Microsoft.Jet.OLEDB.4.0; data source = Students.mdb";
	OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
	OleDbCommand^ command = conn->CreateCommand();
	command->CommandText = "SELECT * FROM Students";
	conn->Open();
	OleDbDataReader^ dataReader = command->ExecuteReader();
	while (dataReader->Read())
	{
		i++;
		if (i == pos)
		{
			fn->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["fn"]))).ToPointer());
			ln->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["ln"]))).ToPointer());
			kurs->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["kurs"]))).ToPointer());
			napr->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["napr"]))).ToPointer());		
			break;
		}
	}
	number->Text = pos + "/" + numofelements;
	dataReader->Close();
	conn->Close();
	if (pos == numofelements)
	{
		nextbutton->Enabled = false;
		lastbutton->Enabled = false;
	}
	firstbutton->Enabled = true;
	prevbutton->Enabled = true;
}
private: System::Void prevbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	int i = 0;
	pos--;
	if (pos < 1)
		pos = 1;
	String^ connectionString = "provider = Microsoft.Jet.OLEDB.4.0; data source = Students.mdb";
	OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
	OleDbCommand^ command = conn->CreateCommand();
	command->CommandText = "SELECT * FROM Students";
	conn->Open();
	OleDbDataReader^ dataReader = command->ExecuteReader();
	while (dataReader->Read())
	{
		i++;
		if (i == pos)
		{
			fn->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["fn"]))).ToPointer());
			ln->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["ln"]))).ToPointer());
			kurs->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["kurs"]))).ToPointer());
			napr->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["napr"]))).ToPointer());
			break;
		}
	}
	number->Text = pos + "/" + numofelements;
	dataReader->Close();
	conn->Close();
	if (pos == 1)
	{
		firstbutton->Enabled = false;
		prevbutton->Enabled = false;
	}
	nextbutton->Enabled = true;
	lastbutton->Enabled = true;
}
private: System::Void firstbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	int i = 0;
	pos=1;
	String^ connectionString = "provider = Microsoft.Jet.OLEDB.4.0; data source = Students.mdb";
	OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
	OleDbCommand^ command = conn->CreateCommand();
	command->CommandText = "SELECT * FROM Students";
	conn->Open();
	OleDbDataReader^ dataReader = command->ExecuteReader();
	while (dataReader->Read())
	{
		i++;
		if (i == pos)
		{
			fn->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["fn"]))).ToPointer());
			ln->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["ln"]))).ToPointer());
			kurs->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["kurs"]))).ToPointer());
			napr->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["napr"]))).ToPointer());
			break;
		}
	}
	number->Text = pos + "/" + numofelements;
	dataReader->Close();
	conn->Close();
	firstbutton->Enabled = false;
	prevbutton->Enabled = false;
	nextbutton->Enabled = true;
	lastbutton->Enabled = true;
	if (numofelements == 2)
	{
		prevbutton->Enabled = false;
		nextbutton->Enabled = false;
	}
}
private: System::Void lastbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	int i = 0;
	pos = numofelements;
	String^ connectionString = "provider = Microsoft.Jet.OLEDB.4.0; data source = Students.mdb";
	OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
	OleDbCommand^ command = conn->CreateCommand();
	command->CommandText = "SELECT * FROM Students";
	conn->Open();
	OleDbDataReader^ dataReader = command->ExecuteReader();
	while (dataReader->Read())
	{
		i++;
		if (i == pos)
		{
			fn->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["fn"]))).ToPointer());
			ln->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["ln"]))).ToPointer());
			kurs->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["kurs"]))).ToPointer());
			napr->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["napr"]))).ToPointer());
			break;
		}
	}
	number->Text = pos + "/" + numofelements;
	dataReader->Close();
	conn->Close();
	lastbutton->Enabled = false;
	nextbutton->Enabled = false;
	firstbutton->Enabled = true;
	prevbutton->Enabled = true;
	if (numofelements == 2)
	{
		prevbutton->Enabled = false;
		nextbutton->Enabled = false;
	}
}
private: System::Void addnewbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	AddForm^ form = gcnew AddForm();
	form->ShowDialog();
	numofelements++;
	number->Text = pos + "/" + numofelements;
	deletebutton->Enabled = true;

}
private: System::Void searchbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	SearchForm^ forma = gcnew SearchForm();
	forma->ShowDialog();
}
private: System::Void changebutton_Click(System::Object^  sender, System::EventArgs^  e) {
	char *changefn = ((char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(fn->Text))).ToPointer());
	char *changeln = ((char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(ln->Text))).ToPointer());
	char *changekurs = ((char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(kurs->Text))).ToPointer());
	char *changenapr = ((char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(napr->Text))).ToPointer());
	ChangeForm^ formo = gcnew ChangeForm(changefn,changeln,changekurs,changenapr);
	formo->newfn->Text = fn->Text;
	formo->newln->Text = ln->Text;
	formo->newkurs->Text = kurs->Text;
	formo->newnapr->Text = napr->Text;
	formo->ShowDialog();
	int i = 0;
	String^ connectionString = "provider = Microsoft.Jet.OLEDB.4.0; data source = Students.mdb";
	OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
	OleDbCommand^ command = conn->CreateCommand();
	command->CommandText = "SELECT * FROM Students";
	conn->Open();
	OleDbDataReader^ dataReader = command->ExecuteReader();
	while (dataReader->Read())
	{
		i++;
		if (i == pos)
		{
			fn->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["fn"]))).ToPointer());
			ln->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["ln"]))).ToPointer());
			kurs->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["kurs"]))).ToPointer());
			napr->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["napr"]))).ToPointer());
			break;
		}
	}
	number->Text = pos + "/" + numofelements;
	dataReader->Close();
	conn->Close();
	
}
private: System::Void deletebutton_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ connectionString = "provider = Microsoft.Jet.OLEDB.4.0; data source = Students.mdb";
	OleDbConnection^ conn = gcnew OleDbConnection(connectionString);
	OleDbCommand^ command = conn->CreateCommand();
	command->CommandText = "DELETE FROM Students WHERE fn='" + gcnew System::String(fn->Text) + "'and ln='" + gcnew System::String(ln->Text) + "' and kurs='" + gcnew System::String(kurs->Text) + "';";
	conn->Open();
	command->ExecuteNonQuery();
	conn->Close();
	if (pos == 1 && numofelements == 1 || pos == 0 && numofelements == 0)
		pos = 0;
	else pos = 1;
	if (numofelements > 1)
		numofelements--;
	else numofelements = 0;
	if (numofelements < 2)
	{
		lastbutton->Enabled = false;
		firstbutton->Enabled = false;
		prevbutton->Enabled = false;
		nextbutton->Enabled = false;
	}
	if (numofelements == 2)
	{
		prevbutton->Enabled = false;
		nextbutton->Enabled = false;
	}
	number->Text = pos + "/" + numofelements;
	int i = 0;
	command->CommandText = "SELECT * FROM Students";
	conn->Open();
	OleDbDataReader^ dataReader = command->ExecuteReader();
	while (dataReader->Read())
	{
		i++;
		if (i == pos)
		{
			fn->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["fn"]))).ToPointer());
			ln->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["ln"]))).ToPointer());
			kurs->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["kurs"]))).ToPointer());
			napr->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(dataReader["napr"]))).ToPointer());
			break;
		}
	}
	if (numofelements == 0)
	{
		deletebutton->Enabled = false;
		changebutton->Enabled = false;
	}
	firstbutton->Enabled = false;
	prevbutton->Enabled = false;
	if (numofelements > 2)
		nextbutton->Enabled = true;
	else nextbutton->Enabled = false;
	if (numofelements > 1)
		lastbutton->Enabled = true;
	else lastbutton->Enabled = false;
}
};
}
