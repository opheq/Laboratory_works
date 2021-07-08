#include "SearchDialog.h"

#include <iostream>


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void maini(array<String^>^ arg) {
	setlocale(LC_ALL, "russian");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
}
