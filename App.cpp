#include "App.h"
#include "Windows.h"


wxIMPLEMENT_APP(App);


bool App::OnInit()
{
	Window* Calculator = new Window;
	Calculator->Show(true);
	return true;
}