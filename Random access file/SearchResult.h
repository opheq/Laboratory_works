#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
namespace Programm {

	enum { size_name = 60 };


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;

	/// <summary>
	/// Сводка для SearchResult
	/// </summary>


	public ref class SearchResult : public System::Windows::Forms::Form
	{
	public:
		SearchResult(char *name, char *group,int usedbytes)
		{
			InitializeComponent();
			char*namesearch = name;
			char*groupsearch = group;
			int bytes = usedbytes;
			char sname[60] = "";
			char sgroup[20] = "";
			bool namecheck;
			bool groupcheck;
			int pos = 0;
			int i = 0;
			int j=0;
			std::fstream base;
			base.open("base.txt");
			base.seekg(0,std::ios::beg);
			for (;;)
			{
				if (j == bytes)
					break;
				base.read(sname, 60);
				base.read(sgroup, 20);
				pos++;
				if (strstr(sname,namesearch)!=NULL)
				{
					namecheck = true;
				}
				else if(namesearch==NULL)
					namecheck = true;
				else namecheck = false;
				if (strstr(sgroup, groupsearch) != NULL)
				{
					groupcheck = true;
				}
				else if (groupsearch == NULL)
					groupcheck = true;
				else groupcheck = false;
				if (namecheck == true && groupcheck == true)
				{
					
					DataTable->Rows->Add();
					DataTable->Rows[i]->Cells[0]->Value = gcnew System::String(sname);
					DataTable->Rows[i]->Cells[1]->Value = gcnew System::String(sgroup);
					DataTable->Rows[i]->Cells[2]->Value = pos;
					i++;
				
				}
				j = j + 80;
			}
			base.close();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SearchResult()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  DataTable;
	protected:

	protected:





	private: System::Windows::Forms::Button^  closewindow;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  FIO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  GROUP;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Position;






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
			this->DataTable = (gcnew System::Windows::Forms::DataGridView());
			this->FIO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GROUP = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Position = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->closewindow = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataTable))->BeginInit();
			this->SuspendLayout();
			// 
			// DataTable
			// 
			this->DataTable->AllowUserToAddRows = false;
			this->DataTable->AllowUserToResizeColumns = false;
			this->DataTable->AllowUserToResizeRows = false;
			this->DataTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DataTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->FIO, this->GROUP,
					this->Position
			});
			this->DataTable->Location = System::Drawing::Point(28, 10);
			this->DataTable->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->DataTable->Name = L"DataTable";
			this->DataTable->RowTemplate->Height = 24;
			this->DataTable->Size = System::Drawing::Size(689, 476);
			this->DataTable->TabIndex = 0;
			// 
			// FIO
			// 
			this->FIO->HeaderText = L"ФИО";
			this->FIO->MinimumWidth = 450;
			this->FIO->Name = L"FIO";
			this->FIO->ReadOnly = true;
			this->FIO->Width = 450;
			// 
			// GROUP
			// 
			this->GROUP->HeaderText = L"Группа";
			this->GROUP->MinimumWidth = 100;
			this->GROUP->Name = L"GROUP";
			// 
			// Position
			// 
			this->Position->HeaderText = L"Позиция";
			this->Position->Name = L"Position";
			this->Position->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// closewindow
			// 
			this->closewindow->Location = System::Drawing::Point(721, 10);
			this->closewindow->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->closewindow->Name = L"closewindow";
			this->closewindow->Size = System::Drawing::Size(56, 476);
			this->closewindow->TabIndex = 3;
			this->closewindow->Text = L"Закрыть";
			this->closewindow->UseVisualStyleBackColor = true;
			this->closewindow->Click += gcnew System::EventHandler(this, &SearchResult::closewindow_Click);
			// 
			// SearchResult
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(778, 495);
			this->Controls->Add(this->closewindow);
			this->Controls->Add(this->DataTable);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"SearchResult";
			this->Text = L"Результаты поиска";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataTable))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void closewindow_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
};
}
