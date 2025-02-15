#include "Windows.h"



wxBEGIN_EVENT_TABLE(Window, wxFrame)

EVT_BUTTON(10001, Window::Button1)
EVT_BUTTON(10002, Window::Button2)
EVT_BUTTON(10003, Window::Button3)
EVT_BUTTON(10004, Window::Button4)
EVT_BUTTON(10005, Window::Button5)
EVT_BUTTON(10006, Window::Button6)
EVT_BUTTON(10007, Window::Button7)
EVT_BUTTON(10008, Window::Button8)
EVT_BUTTON(10009, Window::Button9)
EVT_BUTTON(10000, Window::Button0)
EVT_BUTTON(10010, Window::ButtonEquals)
EVT_BUTTON(10011, Window::ButtonClear)
EVT_BUTTON(10012, Window::ButtonBackspaceDelete)
EVT_BUTTON(10013, Window::ButtonNegativePositive)
EVT_BUTTON(10014, Window::ButtonModulo)
EVT_BUTTON(10015, Window::ButtonAdd)
EVT_BUTTON(10016, Window::ButtonMinus)
EVT_BUTTON(10017, Window::ButtonDivide)
EVT_BUTTON(10018, Window::ButtonMultiply)
EVT_BUTTON(10019, Window::ButtonSin)
EVT_BUTTON(10020, Window::ButtonCos)
EVT_BUTTON(10021, Window::ButtonTan)
EVT_BUTTON(10022, Window::ButtonDecimal)
EVT_BUTTON(10023, Window::ButtonNegative)

wxEND_EVENT_TABLE()

Window::Window() : wxFrame(nullptr, wxID_ANY, "Krystal Calculator", wxPoint(200, 200), wxSize(400, 500))
{

	Controls();
	
	

}
void Window::Controls(){
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	textBox = new wxTextCtrl(this, wxID_ANY, " ", wxDefaultPosition, wxSize(300,50));
	mainSizer->Add(textBox, 0, wxALL | wxEXPAND, 5);

	wxGridSizer* grid = new wxGridSizer(6,4,3,3);

	sin = new wxButton(this, 10019, "sin"); 
	cos = new wxButton(this, 10020, " cos");
	tan = new wxButton(this, 10021, " tan");
	 button1 = new wxButton(this, 10001, " 1 "),
	 button2 = new wxButton(this,10002, " 2 "); 
	 button3 = new wxButton(this, 10003, " 3 ");
     button4 = new wxButton(this, 10004, " 4 "); 
	 button5 = new wxButton(this, 10005, " 5 ");
	 button6 = new wxButton(this, 10006, " 6 ");
	 button7 = new wxButton(this, 10007, " 7 ");
	 button8 = new wxButton(this, 10008, " 8 ");
	 button9 = new wxButton(this, 10009, " 9 ");
	 Minus = new wxButton(this, 10016, " - ");
	 button0 = new wxButton(this, 10000, " 0 ");
	 Add = new wxButton(this, 10015, " + ");
	 Clear = new wxButton(this, 10011, " C");
	 BackspaceDelete = new wxButton(this, 10012, " <-");
	 Multiply = new wxButton(this, 10018, " * ");
     Modulo = new wxButton(this, 10014, " % ");
	 Negative = new wxButton(this, 10023, " - ");
	 Divide = new wxButton(this, 10017, " / ");
     Decimal = new wxButton(this, 10022, " . ");
	 NegativePositive = new wxButton(this, 10013, " -/+ ");
     Equals = new wxButton(this, 10010, " = ");

	 grid->Add(sin, 1, wxEXPAND);
	 grid->Add(cos, 1, wxEXPAND);
	 grid->Add(tan, 1, wxEXPAND);
	 grid->Add(Clear, 1, wxEXPAND);
	 grid->Add(Negative, 1, wxEXPAND);
	 grid->Add(Decimal, 1, wxEXPAND);
     grid->Add(button9, 1, wxEXPAND);
	 grid->Add(button8, 1, wxEXPAND);
	 grid->Add(button7, 1, wxEXPAND);
     grid->Add(button6, 1, wxEXPAND);
	 grid->Add(button5, 1, wxEXPAND);
	 grid->Add(button4, 1, wxEXPAND); 
	 grid->Add(button3, 1, wxEXPAND);
	 grid->Add(button2, 1, wxEXPAND);
	 grid->Add(button1, 1, wxEXPAND);
	 grid->Add(Minus, 1, wxEXPAND);
     grid->Add(button0, 1, wxEXPAND);
 	 grid->Add(Add, 1, wxEXPAND);
     grid->Add(Multiply, 1, wxEXPAND);
	 grid->Add(Modulo, 1, wxEXPAND);
	 grid->Add(Divide, 1, wxEXPAND);  
	 grid->Add(NegativePositive, 1, wxEXPAND);
	 grid->Add(Equals, 1, wxEXPAND);
	 grid->Add(BackspaceDelete, 1, wxEXPAND);

	 mainSizer->Add(grid, 1, wxEXPAND | wxALL, 5);
	 SetSizer(mainSizer);

}

void Window::Button1(wxCommandEvent& evt)
{
	textBox->AppendText("1");
}

void Window::Button2(wxCommandEvent& evt)
{
	textBox->AppendText("2");
}

void Window::Button3(wxCommandEvent& evt)
{
	textBox->AppendText("3");
}

void Window::Button4(wxCommandEvent& evt)
{
	textBox->AppendText("4");
}

void Window::Button5(wxCommandEvent& evt)
{
	textBox->AppendText("5");
}

void Window::Button6(wxCommandEvent& evt)
{
	textBox->AppendText("6");
}

void Window::Button7(wxCommandEvent& evt)
{
	textBox->AppendText("7");
}

void Window::Button8(wxCommandEvent& evt)
{
	textBox->AppendText("8");
}

void Window::Button9(wxCommandEvent& evt)
{
	textBox->AppendText("9");
}

void Window::ButtonClear(wxCommandEvent& evt)
{
	textBox->Clear();
}

void Window::ButtonMultiply(wxCommandEvent& evt)
{
}

void Window::ButtonMinus(wxCommandEvent& evt)
{
	textBox->AppendText("-");
}

void Window::ButtonDivide(wxCommandEvent& evt)
{
}

void Window::ButtonAdd(wxCommandEvent& evt)
{
}

void Window::ButtonModulo(wxCommandEvent& evt)
{
}

void Window::ButtonDecimal(wxCommandEvent& evt)
{
}

void Window::ButtonNegative(wxCommandEvent& evt)
{
}

void Window::ButtonSin(wxCommandEvent& evt)
{
}

void Window::ButtonCos(wxCommandEvent& evt)
{
}

void Window::ButtonTan(wxCommandEvent& evt)
{
}

void Window::ButtonNegativePositive(wxCommandEvent& evt)
{

}



void Window::Button0(wxCommandEvent& evt)
{
}

void Window::ButtonBackspaceDelete(wxCommandEvent& evt)
{
	wxString current = textBox->GetValue();
	if (!current.empty()) {
		textBox->SetValue(current.RemoveLast());
	}
}

void Window::ButtonEquals(wxCommandEvent& evt)
{
}
