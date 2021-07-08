#include "ChangeForm.h"

#include <iostream>
#include "ErrorForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void maino(array<String^>^ arg) {
	setlocale(LC_ALL, "russian");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
}

