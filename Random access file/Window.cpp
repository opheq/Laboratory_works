#include "Window.h"
#include "Source.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ args) {
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Programm::Window form;
	Application::Run(%form);

}

