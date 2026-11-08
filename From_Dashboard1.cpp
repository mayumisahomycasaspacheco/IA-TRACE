#include "From_Dashboard1.h"
#include "Form_Dashboard2.h"
#include "Form_Menu.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew IATRACE::Form_Dashboard2());
}