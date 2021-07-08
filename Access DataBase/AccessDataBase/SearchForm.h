#pragma once
#include "ResultSearchForm.h"
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
namespace AccessDataBase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Сводка для SearchForm
	/// </summary>
	public ref class SearchForm : public System::Windows::Forms::Form
	{
	public:
		SearchForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SearchForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  fnbox;
	private: System::Windows::Forms::TextBox^  kursbox;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^  lnbox;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;



	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  naprbox;
	private: System::Windows::Forms::Label^  label6;

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
			this->fnbox = (gcnew System::Windows::Forms::TextBox());
			this->kursbox = (gcnew System::Windows::Forms::TextBox());
			this->lnbox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->naprbox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// fnbox
			// 
			this->fnbox->Location = System::Drawing::Point(251, 95);
			this->fnbox->Name = L"fnbox";
			this->fnbox->Size = System::Drawing::Size(267, 22);
			this->fnbox->TabIndex = 0;
			// 
			// kursbox
			// 
			this->kursbox->Location = System::Drawing::Point(251, 155);
			this->kursbox->Name = L"kursbox";
			this->kursbox->Size = System::Drawing::Size(267, 22);
			this->kursbox->TabIndex = 2;
			// 
			// lnbox
			// 
			this->lnbox->Location = System::Drawing::Point(251, 123);
			this->lnbox->Name = L"lnbox";
			this->lnbox->Size = System::Drawing::Size(267, 22);
			this->lnbox->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(210, 95);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Имя";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(175, 123);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Фамилия";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(206, 155);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Курс";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 132);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 79);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Найти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SearchForm::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(3, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(515, 29);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Введите параметры для поиска и нажмите";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(5, 38);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(101, 29);
			this->label5->TabIndex = 12;
			this->label5->Text = L"\"Найти\"";
			// 
			// naprbox
			// 
			this->naprbox->Location = System::Drawing::Point(251, 183);
			this->naprbox->Name = L"naprbox";
			this->naprbox->Size = System::Drawing::Size(267, 22);
			this->naprbox->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(148, 183);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(97, 17);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Направление";
			// 
			// SearchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(530, 223);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->naprbox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lnbox);
			this->Controls->Add(this->kursbox);
			this->Controls->Add(this->fnbox);
			this->Name = L"SearchForm";
			this->Text = L"Поиск";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		char* ffn= (char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(fnbox->Text))).ToPointer();;
		char* lln= (char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(lnbox->Text))).ToPointer();;
		char* kkurs= (char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(kursbox->Text))).ToPointer();;
		char* nnapr = (char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(naprbox->Text))).ToPointer();;
		ResultSearchForm^ form = gcnew ResultSearchForm(ffn, lln, kkurs, nnapr);
		form->ShowDialog();
	}
};
}
