#include "SearchResult.h"

#include <iostream>


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void mainu(array<String^>^ arg) {
	setlocale(LC_ALL, "russian");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
}

