#include "Windows.h"
#include <wx/tokenzr.h>
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"
#include <cmath>
using namespace std;

//window constructor - main window 
Window::Window() : wxFrame(nullptr, wxID_ANY, "Krystal Calculator", wxPoint(0,0), wxSize(250, 200))
{
	//main position and size set
	wxPoint pos(100, 100);
	wxSize size(100, 50);

	Controls(); //sets up the layout
	BindEvents();//bind button events
	
}
//bindevents -  buttons to clicks
void Window::BindEvents() {

	
	//bind all buttons events
	//ids connects for different functions
	Bind(wxEVT_BUTTON, &Window::Button0, this, 10000);
	Bind(wxEVT_BUTTON, &Window::Button1, this, 10001);
	Bind(wxEVT_BUTTON, &Window::Button2, this, 10002);
	Bind(wxEVT_BUTTON, &Window::Button3, this, 10003);
	Bind(wxEVT_BUTTON, &Window::Button4, this, 10004);
	Bind(wxEVT_BUTTON, &Window::Button5, this, 10005);
	Bind(wxEVT_BUTTON, &Window::Button6, this, 10006);
	Bind(wxEVT_BUTTON, &Window::Button7, this, 10007);
	Bind(wxEVT_BUTTON, &Window::Button8, this, 10008);
	Bind(wxEVT_BUTTON, &Window::Button9, this, 10009);
	Bind(wxEVT_BUTTON, &Window::ButtonEquals, this, 10010);
	Bind(wxEVT_BUTTON, &Window::ButtonClear, this, 10011);
	Bind(wxEVT_BUTTON, &Window::ButtonBackspaceDelete, this, 10012);
	Bind(wxEVT_BUTTON, &Window::ButtonNegativePositive, this, 10013);
	Bind(wxEVT_BUTTON, &Window::ButtonModulo, this, 10014);
	Bind(wxEVT_BUTTON, &Window::ButtonAdd, this, 10015);
	Bind(wxEVT_BUTTON, &Window::ButtonMinus, this, 10016);
	Bind(wxEVT_BUTTON, &Window::ButtonDivide, this, 10017);
	Bind(wxEVT_BUTTON, &Window::ButtonMultiply, this, 10018);
	Bind(wxEVT_BUTTON, &Window::ButtonSin, this, 10019);
	Bind(wxEVT_BUTTON, &Window::ButtonCos, this, 10020);
	Bind(wxEVT_BUTTON, &Window::ButtonTan, this, 10021);
	Bind(wxEVT_BUTTON, &Window::ButtonDecimal, this, 10022);
	Bind(wxEVT_BUTTON, &Window::Button, this, 10026);


}
//getTextBox display
wxTextCtrl* Window::GetTextBox()
{
	return textBox; 
}

void Window::Controls(){

	
	Add = Minus = Decimal = BackspaceDelete = nullptr;
	NegativePositive = Multiply = nullptr;
	Clear = Equals = Divide = Modulo = nullptr;
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	//create add textbox 
	textBox = new wxTextCtrl(this, wxID_ANY, " ", wxDefaultPosition, wxSize(255,55));
	//set color to textbox
	textBox->SetBackgroundColour(wxColour(*wxBLUE));
	this->SetBackgroundColour(wxColour(*wxGREEN));
	textBox->SetForegroundColour(wxColour("ORANGE"));
	mainSizer->Add(textBox, 0, wxEXPAND | wxALL, 5);
	//create grid sizer
	wxGridSizer* grid = new wxGridSizer(6,4,3,3);
	CreateBtn();
	//row1
	 grid->Add(sin, 1, wxEXPAND | wxALL, 1);
	 grid->Add(cos, 1, wxEXPAND | wxALL, 1);
	 grid->Add(tan, 1, wxEXPAND | wxALL, 1);
	 grid->Add(Clear, 1, wxEXPAND | wxALL, 1);
	//row2
     grid->Add(button9, 1, wxEXPAND | wxALL, 1);
	 grid->Add(button8, 1, wxEXPAND | wxALL, 1);
	 grid->Add(button7, 1, wxEXPAND | wxALL, 1);
	 grid->Add(Divide, 1, wxEXPAND | wxALL, 1);
    //row3
     grid->Add(button6, 1, wxEXPAND | wxALL, 1);
	 grid->Add(button5, 1, wxEXPAND | wxALL, 1);
	 grid->Add(button4, 1, wxEXPAND | wxALL, 1);
	 grid->Add(Multiply, 1, wxEXPAND | wxALL,1);
	 //row4
	 grid->Add(button3, 1, wxEXPAND | wxALL, 1);
	 grid->Add(button2, 1, wxEXPAND | wxALL, 1);
	 grid->Add(button1, 1, wxEXPAND | wxALL, 1);
	 grid->Add(Modulo, 1, wxEXPAND | wxALL, 1);
	 //row5
	 grid->Add(Minus, 1, wxEXPAND | wxALL, 1);
     grid->Add(button0, 1, wxEXPAND | wxALL,1);
	 grid->Add(Add, 1, wxEXPAND | wxALL, 1);
	 grid->Add(Equals, 1, wxEXPAND | wxALL, 1);
	 //row6
	
	 grid->Add(Decimal, 1, wxEXPAND | wxALL, 1);
	 grid->Add(BackspaceDelete, 1, wxEXPAND | wxALL, 1);
	 grid->Add(NegativePositive, 1, wxEXPAND | wxALL, 1);

	 grid->Add(button, 1, wxEXPAND | wxALL, 1);
	//add grid to main sizer
	 mainSizer->Add(grid, 1, wxEXPAND | wxALL, 5);
	
	 //set the main sizer
	 SetSizer(mainSizer);
	 this->Refresh();
	 this->Update();
	 //fit the window to its contents
	 Fit();
}
void Window::CreateBtn() {
	////Creating Addition Button
	sin = ButtonFactory::CreateFunctionBtn(this, 10019, "sin", wxDefaultPosition, wxDefaultSize);
	cos = ButtonFactory::CreateFunctionBtn(this, 10020, " cos", wxDefaultPosition, wxDefaultSize);
	tan = ButtonFactory::CreateFunctionBtn(this, 10021, " tan", wxDefaultPosition, wxDefaultSize);

	button1 = ButtonFactory::CreateNumberBtn(this, 10001, " 1 ", wxDefaultPosition, wxDefaultSize);
	button2 = ButtonFactory::CreateNumberBtn(this, 10002, " 2 ", wxDefaultPosition, wxDefaultSize);
	button3 = ButtonFactory::CreateNumberBtn(this, 10003, " 3 ", wxDefaultPosition, wxDefaultSize);
	button4 = ButtonFactory::CreateNumberBtn(this, 10004, " 4 ", wxDefaultPosition, wxDefaultSize);
	button5 = ButtonFactory::CreateNumberBtn(this, 10005, " 5 ", wxDefaultPosition, wxDefaultSize);
	button6 = ButtonFactory::CreateNumberBtn(this, 10006, " 6 ", wxDefaultPosition, wxDefaultSize);
	button7 = ButtonFactory::CreateNumberBtn(this, 10007, " 7 ", wxDefaultPosition, wxDefaultSize);
	button8 = ButtonFactory::CreateNumberBtn(this, 10008, " 8 ", wxDefaultPosition, wxDefaultSize);
	button9 = ButtonFactory::CreateNumberBtn(this, 10009, " 9 ", wxDefaultPosition, wxDefaultSize);

	Minus = ButtonFactory::CreateOperationBtn(this, 10016, " - ", wxDefaultPosition, wxDefaultSize);
	button0 = ButtonFactory::CreateNumberBtn(this, 10000, " 0 ", wxDefaultPosition, wxDefaultSize);
	Add = ButtonFactory::CreateOperationBtn(this, 10015, " + ", wxDefaultPosition, wxDefaultSize);	
	Multiply = ButtonFactory::CreateOperationBtn(this, 10018, " * ", wxDefaultPosition, wxDefaultSize);
	Modulo = ButtonFactory::CreateOperationBtn(this, 10014, " % ", wxDefaultPosition, wxDefaultSize);
	Divide = ButtonFactory::CreateOperationBtn(this, 10017, " / ", wxDefaultPosition, wxDefaultSize);
	NegativePositive = ButtonFactory::CreateOperationBtn(this, 10013, " -/+ ", wxDefaultPosition, wxDefaultSize);
	Decimal = ButtonFactory::CreateOperationBtn(this, 10022, " . ", wxDefaultPosition, wxDefaultSize);

	Clear = ButtonFactory::CreateClearBtn(this, 10011, " C", wxDefaultPosition, wxDefaultSize);
	button = ButtonFactory::CreateBtn(this, 10026, " ", wxDefaultPosition, wxDefaultSize);
	BackspaceDelete = ButtonFactory::CreateBackSpaceBtn(this, 10012, "<-", wxDefaultPosition, wxDefaultSize);
	Equals = ButtonFactory::CreateEqualBtn(this, 10010, " = ", wxDefaultPosition, wxDefaultSize);
}
void Window::Button(wxCommandEvent& evt)
{
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
	textBox->AppendText("*");
}

void Window::ButtonMinus(wxCommandEvent& evt)
{
	textBox->AppendText("-");
}

void Window::ButtonDivide(wxCommandEvent& evt)
{
	wxString Curr = textBox->GetValue();
	if (!Curr.EndsWith("0")) {
		textBox->AppendText("/");
	}
	else{
		wxMessageBox("DON'T DIVIDE BY 0"," ERROR");
	}
}

void Window::ButtonAdd(wxCommandEvent& evt)
{
	textBox->AppendText("+");
}

void Window::ButtonModulo(wxCommandEvent& evt)
{
	wxString Curr = textBox->GetValue();
	if (!Curr.EndsWith("0")) {
		textBox->AppendText("%");
	}
	else {
		wxMessageBox("DON'T DIVIDE BY 0", " ERROR");
	}
}

void Window::ButtonDecimal(wxCommandEvent& evt)
{
	textBox->AppendText(".");
}

void Window::ButtonSin(wxCommandEvent& evt)
{
	textBox->AppendText("sin(");
}

void Window::ButtonCos(wxCommandEvent& evt)
{
	textBox->AppendText("cos(");
}

void Window::ButtonTan(wxCommandEvent& evt)
{
	textBox->AppendText("tan(");
}

void Window::ButtonNegativePositive(wxCommandEvent& evt)
{
	textBox->AppendText("+/-");
}


void Window::Button0(wxCommandEvent& evt)
{
	textBox->AppendText("0");
}

void Window::ButtonBackspaceDelete(wxCommandEvent& evt)
{
	wxString current = textBox->GetValue();
	if (!current.empty()) {
		textBox->SetValue(current.RemoveLast());
	}
	else {
		textBox->Clear();
	}
}

void Window::ButtonEquals(wxCommandEvent& evt)
{
	wxString expression = textBox->GetValue().Trim();
	if (!expression.IsEmpty()) {
		expression.Replace(" ", "");
		try {
			if (expression.Contains("sin") || expression.Contains("cos") || expression.Contains("tan")) {
				wxString functions = expression.BeforeFirst('(');
				wxString angleString = expression.AfterFirst('(').BeforeLast(')');
				double angle = wxAtof(angleString);

				double radians = angle * 3.14159265358979323846 / 180.8;
				double result = 0.0;
				if (functions == "sin") {
					result = std::sin(radians);
				}
				else if (functions == "cos") {
					result = std::cos(radians);
				}
				else if (functions == "tan") {
					if (std::cos(radians) == 0) {
 
						textBox->SetValue("undefined");
						return;
					}
				 result = std::tan(radians);
				}
			

				textBox->SetValue(wxString::Format("%.6g", result));
				return;
			}
			double result = CalculatorProcessor::GetInstance()->Calculate(expression.ToStdString());
			
			textBox->SetValue(wxString::Format("%.6g", result));
			
		}
		catch (const std::exception& ) {
			textBox->SetValue("ERROR");
		}
		

	}

   evt.Skip();
}

wxString Window::FormatExpression(const wxString& express) {
	wxString formatted = express;
	formatted.Replace(" ", "");
	formatted.Replace("++", "+");
	formatted.Replace("--", "+");
	formatted.Replace("+-", "-");
	formatted.Replace("-+", "-");
	return formatted;
}