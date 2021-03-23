#include "NameForm.h"


using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void Main(array<String^>^ args) {

    Application::EnableVisualStyles();

    Application::SetCompatibleTextRenderingDefault(false);

    CardG::NameForm form;
    Application::Run(% form);
}
