#pragma once
#include "Source.h"
#include "ChangeForm.h"
#include "SearchDialog.h"
#include "ErrorForm.h"
#include <iostream>
#include <fstream>
#include <string>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
namespace Programm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;


	CD cd;
	NG ng;
	static int errorcode=0;
	/// <summary>
	/// Сводка для Window
	/// </summary>
	public ref class Window : public System::Windows::Forms::Form
	{
	public:
		Window(void)
		{
			InitializeComponent();
			std::fstream base;
			base.open("base.txt", std::ios::in);
			base.seekg(0, std::ios::beg);
			int temp;
			for (;;)
			{
				if (base.eof())
					break;
				base.read((char*)&ng, sizeof(ng));
				if (ng.name[1] != cd.empty[1])
					break;
			}
			temp = base.tellp();
			nameBox->Text = gcnew System::String(ng.name);
			groupBox->Text = gcnew System::String(ng.group);
			base.close();
			cd.numofelements = 0;
			base.open("base.txt", std::ios::in);
			for (;;)
			{
				if (base.eof())
					break;
				base.read((char*)&ng, sizeof(ng));
				cd.usedbytes = cd.usedbytes + 80;
				if (ng.name[1] != cd.empty[1] && ng.name[1] != 0)
					cd.numofelements++;
			}
			if (cd.numofelements > 0)
			{
				cd.numofelements--;
				cd.usedbytes = cd.usedbytes - 80;
				changeButton->Enabled = true;
			}
			if (cd.numofelements == 0)
				{
					cd.pos = 0;
				}
			else cd.pos = 1;
			if (cd.numofelements == 0 || cd.numofelements == 1)
			{
				lastbutton->Enabled = false;
				nextbutton->Enabled = false;
			}
			using namespace System::Runtime::InteropServices;
			PosVar->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(cd.pos))).ToPointer()) + gcnew System::String("/") + gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(cd.numofelements))).ToPointer());
			firstbutton->Enabled = false;
			firstbutton->Enabled = false;
			if (cd.numofelements == 0)
				deleteButton->Enabled = false;
			else
				deleteButton->Enabled=true;
			if (cd.numofelements == 2)
			{
				prevbutton->Enabled = false;
				nextbutton->Enabled = false;
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Window()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:

	protected:

	protected:








	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::TextBox^  nameBox;
	private:
	public: System::Windows::Forms::TextBox^  groupBox;


	private: System::Windows::Forms::Button^  prevbutton;
	private: System::Windows::Forms::Button^  firstbutton;
	private: System::Windows::Forms::Button^  nextbutton;
	private: System::Windows::Forms::Button^  lastbutton;
	private: System::Windows::Forms::Button^  addrecordButton;
	private: System::Windows::Forms::TextBox^  addrecordName;
	private: System::Windows::Forms::TextBox^  addrecordGroup;
	private: System::Windows::Forms::Label^  position;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  PosVar;
	private: System::Windows::Forms::Button^  deleteButton;
	private: System::Windows::Forms::Button^  changeButton;
private: System::Windows::Forms::Button^  SearchButton;




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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox = (gcnew System::Windows::Forms::TextBox());
			this->prevbutton = (gcnew System::Windows::Forms::Button());
			this->firstbutton = (gcnew System::Windows::Forms::Button());
			this->nextbutton = (gcnew System::Windows::Forms::Button());
			this->lastbutton = (gcnew System::Windows::Forms::Button());
			this->addrecordButton = (gcnew System::Windows::Forms::Button());
			this->addrecordName = (gcnew System::Windows::Forms::TextBox());
			this->addrecordGroup = (gcnew System::Windows::Forms::TextBox());
			this->position = (gcnew System::Windows::Forms::Label());
			this->PosVar = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->changeButton = (gcnew System::Windows::Forms::Button());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(143, 81);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Группа";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(151, 20);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Имя";
			// 
			// nameBox
			// 
			this->nameBox->Enabled = false;
			this->nameBox->Location = System::Drawing::Point(34, 36);
			this->nameBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(258, 22);
			this->nameBox->TabIndex = 11;
			// 
			// groupBox
			// 
			this->groupBox->Enabled = false;
			this->groupBox->Location = System::Drawing::Point(99, 61);
			this->groupBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox->Name = L"groupBox";
			this->groupBox->Size = System::Drawing::Size(127, 22);
			this->groupBox->TabIndex = 12;
			// 
			// prevbutton
			// 
			this->prevbutton->Enabled = false;
			this->prevbutton->Location = System::Drawing::Point(99, 108);
			this->prevbutton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->prevbutton->Name = L"prevbutton";
			this->prevbutton->Size = System::Drawing::Size(61, 19);
			this->prevbutton->TabIndex = 13;
			this->prevbutton->Text = L"<";
			this->prevbutton->UseVisualStyleBackColor = true;
			this->prevbutton->Click += gcnew System::EventHandler(this, &Window::prevbutton_Click);
			// 
			// firstbutton
			// 
			this->firstbutton->Enabled = false;
			this->firstbutton->Location = System::Drawing::Point(34, 108);
			this->firstbutton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->firstbutton->Name = L"firstbutton";
			this->firstbutton->Size = System::Drawing::Size(61, 19);
			this->firstbutton->TabIndex = 14;
			this->firstbutton->Text = L"<<";
			this->firstbutton->UseVisualStyleBackColor = true;
			this->firstbutton->Click += gcnew System::EventHandler(this, &Window::firstbutton_Click);
			// 
			// nextbutton
			// 
			this->nextbutton->Location = System::Drawing::Point(164, 108);
			this->nextbutton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->nextbutton->Name = L"nextbutton";
			this->nextbutton->Size = System::Drawing::Size(61, 19);
			this->nextbutton->TabIndex = 15;
			this->nextbutton->Text = L">";
			this->nextbutton->UseVisualStyleBackColor = true;
			this->nextbutton->Click += gcnew System::EventHandler(this, &Window::nextbutton_Click);
			// 
			// lastbutton
			// 
			this->lastbutton->Location = System::Drawing::Point(230, 108);
			this->lastbutton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->lastbutton->Name = L"lastbutton";
			this->lastbutton->Size = System::Drawing::Size(61, 19);
			this->lastbutton->TabIndex = 16;
			this->lastbutton->Text = L">>";
			this->lastbutton->UseVisualStyleBackColor = true;
			this->lastbutton->Click += gcnew System::EventHandler(this, &Window::lastbutton_Click);
			// 
			// addrecordButton
			// 
			this->addrecordButton->Location = System::Drawing::Point(423, 154);
			this->addrecordButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->addrecordButton->Name = L"addrecordButton";
			this->addrecordButton->Size = System::Drawing::Size(126, 19);
			this->addrecordButton->TabIndex = 18;
			this->addrecordButton->Text = L"Добавить запись";
			this->addrecordButton->UseVisualStyleBackColor = true;
			this->addrecordButton->Click += gcnew System::EventHandler(this, &Window::addrecordButton_Click);
			// 
			// addrecordName
			// 
			this->addrecordName->Location = System::Drawing::Point(344, 56);
			this->addrecordName->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->addrecordName->MaxLength = 60;
			this->addrecordName->Name = L"addrecordName";
			this->addrecordName->Size = System::Drawing::Size(258, 22);
			this->addrecordName->TabIndex = 19;
			// 
			// addrecordGroup
			// 
			this->addrecordGroup->Location = System::Drawing::Point(423, 81);
			this->addrecordGroup->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->addrecordGroup->MaxLength = 20;
			this->addrecordGroup->Name = L"addrecordGroup";
			this->addrecordGroup->Size = System::Drawing::Size(127, 22);
			this->addrecordGroup->TabIndex = 20;
			// 
			// position
			// 
			this->position->AutoSize = true;
			this->position->Location = System::Drawing::Point(162, 106);
			this->position->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->position->Name = L"position";
			this->position->Size = System::Drawing::Size(0, 13);
			this->position->TabIndex = 21;
			// 
			// PosVar
			// 
			this->PosVar->AutoSize = true;
			this->PosVar->Location = System::Drawing::Point(266, 84);
			this->PosVar->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->PosVar->Name = L"PosVar";
			this->PosVar->Size = System::Drawing::Size(0, 13);
			this->PosVar->TabIndex = 22;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(445, 7);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(90, 13);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Новая запись";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(452, 40);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 13);
			this->label4->TabIndex = 24;
			this->label4->Text = L"Новое имя";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(445, 106);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(80, 13);
			this->label5->TabIndex = 25;
			this->label5->Text = L"Новая группа";
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(99, 145);
			this->deleteButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(61, 35);
			this->deleteButton->TabIndex = 26;
			this->deleteButton->Text = L"Удалить запись";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &Window::deleteButton_Click);
			// 
			// changeButton
			// 
			this->changeButton->Location = System::Drawing::Point(164, 145);
			this->changeButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->changeButton->Name = L"changeButton";
			this->changeButton->Size = System::Drawing::Size(61, 35);
			this->changeButton->TabIndex = 27;
			this->changeButton->Text = L"Изменить запись";
			this->changeButton->UseVisualStyleBackColor = true;
			this->changeButton->Click += gcnew System::EventHandler(this, &Window::changeButton_Click);
			// 
			// SearchButton
			// 
			this->SearchButton->Location = System::Drawing::Point(99, 185);
			this->SearchButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(126, 40);
			this->SearchButton->TabIndex = 29;
			this->SearchButton->Text = L"Поиск по базе";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &Window::SearchButton_Click);
			// 
			// Window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(609, 296);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->changeButton);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->PosVar);
			this->Controls->Add(this->position);
			this->Controls->Add(this->addrecordGroup);
			this->Controls->Add(this->addrecordName);
			this->Controls->Add(this->addrecordButton);
			this->Controls->Add(this->lastbutton);
			this->Controls->Add(this->nextbutton);
			this->Controls->Add(this->firstbutton);
			this->Controls->Add(this->prevbutton);
			this->Controls->Add(this->groupBox);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Window";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Брррррря";
			this->Load += gcnew System::EventHandler(this, &Window::Window_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void prevbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		std::fstream base;
		base.open("base.txt", std::ios::in);
		int temp = cd.pos;
		for (;;)
		{
			base.seekg(temp - 1);
			if (temp == 1)
			{
				base.read((char*)&ng, sizeof(ng));
				break;
			}
			base.seekg(80 * (temp-2), std::ios::beg);
			base.read(ng.name, 60);
			base.read(ng.group, 20);
			if (ng.name[0] != cd.empty[0])
				break;
			temp--;
		} 
		nameBox->Text = gcnew System::String(ng.name);
		groupBox->Text = gcnew System::String(ng.group);
		if (ng.name[1] != cd.empty[1]&&cd.pos>1)
			cd.pos--;
		PosVar->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(cd.pos))).ToPointer()) + gcnew System::String("/") + gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(cd.numofelements))).ToPointer());
		base.close();
		if (cd.pos == 1)
		{
			firstbutton->Enabled = false;
			prevbutton->Enabled = false;
		}
		nextbutton->Enabled = true;
		lastbutton->Enabled = true;
		
	}

	private: System::Void firstbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		std::fstream base;
		base.open("base.txt", std::ios::in);
		base.seekg(std::ios::beg);
		int temp =0;
		for (;;)
		{
			if (base.eof())
				break;
			base.seekg(80 * (temp), std::ios::beg);
			base.read((char*)&ng, sizeof(ng));
			if (ng.name[1] != cd.empty[1])
				break;
			temp++;
		} 
		nameBox->Text = gcnew System::String(ng.name);
		groupBox->Text = gcnew System::String(ng.group);
		if (ng.name[0] != cd.empty[0]&&cd.numofelements>0)
			cd.pos=1;
		else cd.pos = 0;
		PosVar->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(cd.pos))).ToPointer()) + gcnew System::String("/") + gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(cd.numofelements))).ToPointer());
		base.close();
		firstbutton->Enabled = false;
		prevbutton->Enabled = false;
		nextbutton->Enabled = true;
		lastbutton->Enabled = true;
		if (cd.numofelements == 2)
		{
			prevbutton->Enabled = false;
			nextbutton->Enabled = false;
		}
	}

	private: System::Void nextbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		std::fstream base;
		base.open("base.txt", std::ios::in);
		int temp = cd.pos;
		for (;;)
		{
			if (base.eof())
				break;
			base.seekg(80 * (temp), std::ios::beg);
			base.read((char*)&ng, sizeof(ng));
			if (ng.name[1] != cd.empty[1])
				break;
			temp++;
		}
		nameBox->Text = gcnew System::String(ng.name);
		groupBox->Text = gcnew System::String(ng.group);
		cd.pos = cd.pos+1;
		if (cd.pos > cd.numofelements)
			cd.pos = cd.numofelements;
		PosVar->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(cd.pos))).ToPointer()) + gcnew System::String("/") + gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(cd.numofelements))).ToPointer());
		base.close();
		if (cd.pos == cd.numofelements)
		{
			nextbutton->Enabled = false;
			lastbutton->Enabled = false;
		}
		firstbutton->Enabled = true;
		prevbutton->Enabled = true;
	}

	private: System::Void lastbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		std::fstream base;
		base.open("base.txt", std::ios::in);
		base.seekg(-80, std::ios::end);
		int temp = 1;
		for (;;)
		{
			if (base.eof())
				break;
			base.seekg(-80 * (temp), std::ios::end);
			base.read((char*)&ng, sizeof(ng));
			if (ng.name[1] != cd.empty[1])
				break;
			temp++;
		};
		nameBox->Text = gcnew System::String(ng.name);
		groupBox->Text = gcnew System::String(ng.group);
		cd.pos = cd.numofelements;
		PosVar->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(cd.pos))).ToPointer()) + gcnew System::String("/") + gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(cd.numofelements))).ToPointer());
		base.close();
		lastbutton->Enabled = false;
		nextbutton->Enabled = false;
		firstbutton->Enabled = true;
		prevbutton->Enabled = true;
		if (cd.numofelements == 2)
		{
			prevbutton->Enabled = false;
			nextbutton->Enabled = false;
		}
	}

	private: System::Void addrecordButton_Click(System::Object^  sender, System::EventArgs^  e) {
		std::fstream reading("base.txt");
		cd.position = 0;
		bool error=false;
		if (strlen((const char*)(Marshal::StringToHGlobalAnsi(addrecordName->Text)).ToPointer()) > 0)
		{
			if (strlen((const char*)(Marshal::StringToHGlobalAnsi(addrecordGroup->Text)).ToPointer()) > 0)
			{
				std::fstream base("base.txt");
				char *newname =  (char*)(Marshal::StringToHGlobalAnsi(addrecordName->Text)).ToPointer() ;
				char *newgroup =  (char*)(Marshal::StringToHGlobalAnsi(addrecordGroup->Text)).ToPointer() ;
				strlwr(newname);
				newname[0] = toupper(newname[0]);
				std::string str;
				std::string str1;
				str = newname;
				str1 = newgroup;
				for (;;)
				{
					if (base.eof())
						break;
					base.read((char*)&ng, sizeof(ng));
					if (str == ng.name&&str1==ng.group)
						error = true;
				}
				base.close();
				if (error == false)
				{
					if (cd.numofelements == 0)
					{
						std::ofstream base("base.txt");
						strcpy_s(ng.name, 60, newname);
						strcpy_s(ng.group, 20, newgroup);
						base.write((char*)&ng, sizeof(ng));
						cd.usedbytes = 80;
						base.close();
					}
					else
					{
						reading.seekg(0, std::ios::beg);
						while (cd.position <= cd.usedbytes)
						{
							reading.read((char*)&ng, sizeof(ng));
							cd.position = reading.tellp();
							if (ng.name[1] == cd.empty[1])
							{
								std::fstream base("base.txt");
								base.seekp(cd.position - 80, std::ios::beg);
								strcpy_s(ng.name, 60, newname);
								strcpy_s(ng.group, 20, newgroup);
								base.write((char*)&ng, sizeof(ng));
								base.close();
								reading.close();
								break;
							}
							if (cd.position == cd.usedbytes)
							{
								std::fstream base("base.txt");
								base.seekp(0, std::ios::end);
								strcpy_s(ng.name, 60, newname);
								strcpy_s(ng.group, 20, newgroup);
								base.write((char*)&ng, sizeof(ng));
								cd.usedbytes = cd.usedbytes + 80;
								base.close();
								reading.close();
								break;
							}
						}

					}
					cd.numofelements++;
					cd.pos = 1;
					firstbutton->Enabled = false;
					prevbutton->Enabled = false;
					if (cd.numofelements > 2)
						nextbutton->Enabled = true;
					else nextbutton->Enabled = false;
					if (cd.numofelements > 1)
						lastbutton->Enabled = true;
					else 	lastbutton->Enabled = false;
					std::fstream base("base.txt");
					base.seekg(0, std::ios::beg);
					base.read((char*)&ng, sizeof(ng));
					nameBox->Text = gcnew System::String(ng.name);
					groupBox->Text = gcnew System::String(ng.group);
					addrecordName->Text = gcnew System::String(cd.emptyadd);
					addrecordGroup->Text = gcnew System::String(cd.emptyadd);
					deleteButton->Enabled = true;
					PosVar->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(cd.pos))).ToPointer()) + gcnew System::String("/") + gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(cd.numofelements))).ToPointer());
					changeButton->Enabled = true;
				}
				else
				{
					errorcode = 3;
					Programm::ErrorForm^ err = gcnew ErrorForm(errorcode);
					err->ShowDialog();
				}
			}
			else
			{
				errorcode = 2;
				Programm::ErrorForm^ err = gcnew ErrorForm(errorcode);
				err->ShowDialog();
			}
		}
		
		else
		{
			errorcode = 1;
			Programm::ErrorForm^ err = gcnew ErrorForm(errorcode);
			err->ShowDialog();
		}
	}

	private: System::Void deleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
		std::fstream base;
		base.open("base.txt");
		base.seekp(80 * (cd.pos - 1), std::ios::beg);
		base.write(cd.empty, 60);
		base.write(cd.empty, 20);
		int temp = 1;
		if (cd.pos == 1 && cd.numofelements == 1 || cd.pos == 0 && cd.numofelements == 0)
			cd.pos = 0;
		else cd.pos = 1;
		if (cd.numofelements > 1)
			cd.numofelements--;
		else cd.numofelements = 0;
		if (cd.numofelements < 2)
		{
			lastbutton->Enabled = false;
			firstbutton->Enabled = false;
			prevbutton->Enabled = false;
			nextbutton->Enabled = false;
		}
		if (cd.numofelements == 2)
		{
			prevbutton->Enabled = false;
			nextbutton->Enabled = false;
		}
		if (cd.numofelements > 0)
		{
			if (cd.pos ==1)
			{
				base.seekg(80 * (cd.pos), std::ios::beg);
				ng.name[0] = cd.empty[0];
				while (ng.name[1] == cd.empty[1])
				{
					base.read((char*)&ng, sizeof(ng));
				}
			}
			else
			{
				base.seekg(80 * (cd.pos - 1), std::ios::beg);
				ng.name[0] = cd.empty[0];
				while (ng.name[0] == cd.empty[0])
				{
					base.read((char*)&ng, sizeof(ng));
				}
			}
		}
		base.seekg(0, std::ios::beg);
		if (cd.numofelements > 0)
		{
			for (;;)
			{
				if (base.eof())
					break;
				base.read((char*)&ng, sizeof(ng));
				if (ng.name[1] != cd.empty[1])
					break;
			}
			nameBox->Text = gcnew System::String(ng.name);
			groupBox->Text = gcnew System::String(ng.group);
		}
		else
		{
			nameBox->Text = gcnew System::String(cd.emptyadd);
			groupBox->Text = gcnew System::String(cd.emptyadd);
		}
		PosVar->Text = gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(cd.pos))).ToPointer()) + gcnew System::String("/") + gcnew System::String((const char*)(Marshal::StringToHGlobalAnsi(System::Convert::ToString(cd.numofelements))).ToPointer());
		if (cd.numofelements == 0)
		{
			deleteButton->Enabled = false;
			changeButton->Enabled = false;
		}
		firstbutton->Enabled = false;
		prevbutton->Enabled = false;
		if (cd.numofelements > 2)
			nextbutton->Enabled = true;
		else nextbutton->Enabled = false;
		if (cd.numofelements > 1)
			lastbutton->Enabled = true;
		else lastbutton->Enabled = false;
		
	
		base.close();
	}


private: System::Void changeButton_Click(System::Object^  sender, System::EventArgs^  e) {
	int position = cd.pos;
		ChangeForm^ forma = gcnew ChangeForm(position);
		forma->newnameBox->Text = nameBox->Text;
		forma->newgroupBox->Text = groupBox->Text;
		forma->ShowDialog();
	std::fstream base("base.txt");
	for (;;)
	{
		if (base.eof())
			break;
		base.read((char*)&ng, sizeof(ng));
		if (ng.name[1] != cd.empty[1])
			break;
	}
	nameBox->Text = gcnew System::String(ng.name);
	groupBox->Text = gcnew System::String(ng.group);

}
private: System::Void SearchButton_Click(System::Object^  sender, System::EventArgs^  e) {
	SearchDialog^ forma = gcnew SearchDialog(cd.usedbytes);
	forma->ShowDialog();
}
private: System::Void Window_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
