#pragma once

#include <string>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include "SearchResult.h"

namespace Programm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	static int bytes;
	/// <summary>
	/// Сводка для SearchDialog
	/// </summary>
	public ref class SearchDialog : public System::Windows::Forms::Form
	{
	public:
		SearchDialog(int kolvo)
		{
			InitializeComponent();
			 bytes = kolvo;
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SearchDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^  searchgroupBox;
	protected:
	public: System::Windows::Forms::TextBox^  searchnameBox;

	protected:

	private: System::Windows::Forms::Button^  searchbutton;
	private: System::Windows::Forms::Button^  cancelbutton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

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
			this->searchgroupBox = (gcnew System::Windows::Forms::TextBox());
			this->searchnameBox = (gcnew System::Windows::Forms::TextBox());
			this->searchbutton = (gcnew System::Windows::Forms::Button());
			this->cancelbutton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// searchgroupBox
			// 
			this->searchgroupBox->Location = System::Drawing::Point(139, 135);
			this->searchgroupBox->MaxLength = 20;
			this->searchgroupBox->Name = L"searchgroupBox";
			this->searchgroupBox->Size = System::Drawing::Size(100, 22);
			this->searchgroupBox->TabIndex = 0;
			// 
			// searchnameBox
			// 
			this->searchnameBox->Location = System::Drawing::Point(139, 87);
			this->searchnameBox->MaxLength = 60;
			this->searchnameBox->Name = L"searchnameBox";
			this->searchnameBox->Size = System::Drawing::Size(100, 22);
			this->searchnameBox->TabIndex = 1;
			// 
			// searchbutton
			// 
			this->searchbutton->Location = System::Drawing::Point(452, 75);
			this->searchbutton->Name = L"searchbutton";
			this->searchbutton->Size = System::Drawing::Size(85, 34);
			this->searchbutton->TabIndex = 2;
			this->searchbutton->Text = L"Найти";
			this->searchbutton->UseVisualStyleBackColor = true;
			this->searchbutton->Click += gcnew System::EventHandler(this, &SearchDialog::searchbutton_Click);
			// 
			// cancelbutton
			// 
			this->cancelbutton->Location = System::Drawing::Point(452, 123);
			this->cancelbutton->Name = L"cancelbutton";
			this->cancelbutton->Size = System::Drawing::Size(84, 34);
			this->cancelbutton->TabIndex = 3;
			this->cancelbutton->Text = L"Отмена";
			this->cancelbutton->UseVisualStyleBackColor = true;
			this->cancelbutton->Click += gcnew System::EventHandler(this, &SearchDialog::cancelbutton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(81, 92);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Имя";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(61, 140);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Группа";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(29, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(533, 24);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Введите необходимые данные поиска и нажмите \"Найти\"";
			// 
			// SearchDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 177);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cancelbutton);
			this->Controls->Add(this->searchbutton);
			this->Controls->Add(this->searchnameBox);
			this->Controls->Add(this->searchgroupBox);
			this->Name = L"SearchDialog";
			this->Text = L"Поиск записей";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
private: System::Void searchbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	 char* searchname = ( char*)(Marshal::StringToHGlobalAnsi(searchnameBox->Text)).ToPointer();
	 char* searchgroup = ( char*)(Marshal::StringToHGlobalAnsi(searchgroupBox->Text)).ToPointer();
	Programm::SearchResult^ sr=gcnew SearchResult(searchname,searchgroup,bytes);
	sr->ShowDialog();

}
};
}
