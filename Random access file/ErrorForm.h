#pragma once

namespace Programm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ErrorForm
	/// </summary>
	public ref class ErrorForm : public System::Windows::Forms::Form
	{
	public:
		ErrorForm(int &errorcode)
		{
			InitializeComponent();
			if(errorcode==1)
			{ 
				label2->Text = "Код ошибки: 1";
				label1->Text = "Проверьте правильность введенного имени";
			}
			if (errorcode == 2)
			{
				label2->Text = "Код ошибки: 2";
				label1->Text = "Проверьте правильность введенной группы";
			}
			if (errorcode == 3)
			{
				label2->Text = "Код ошибки: 3";
				label1->Text = "Данная запись уже существует в базе";
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ErrorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(271, 78);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ErrorForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Проверьте введенные данные";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Код ошибки: ";
			// 
			// ErrorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(386, 124);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"ErrorForm";
			this->Text = L"ErrorForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
	};
}
