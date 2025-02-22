#pragma once
#include"wx\wx.h"
#include "App.h"


class Window : public wxFrame{
private:
	
	wxTextCtrl* textBox;
    wxButton* sin;
    wxButton* cos;
    wxButton* tan;
    wxButton* button0;
    wxButton* button1;
    wxButton* button2;
    wxButton* button3;
    wxButton* button4;
    wxButton* button5;
    wxButton* button6;
    wxButton* button7;
    wxButton* button8;
    wxButton* button9;
    wxButton* Add;
    wxButton* Minus;
    wxButton* Multiply;
    wxButton* Divide;
    wxButton* Modulo;
    wxButton* Clear;
    wxButton* Equals;
    wxButton* Decimal;
    wxButton* BackspaceDelete;
    wxButton* NegativePositive;
    wxButton* button;

		void Controls();

		void CreateBtn();
		void Button(wxCommandEvent& evt);
		void Button1(wxCommandEvent& evt);
		void Button2(wxCommandEvent& evt);
		void Button3(wxCommandEvent& evt);

		void Button4(wxCommandEvent& evt);
		void Button5(wxCommandEvent& evt);
		void Button6(wxCommandEvent& evt);
		void Button7(wxCommandEvent& evt);
		void Button8(wxCommandEvent& evt);
		void Button9(wxCommandEvent& evt);

		void Button0(wxCommandEvent& evt);
		void ButtonBackspaceDelete(wxCommandEvent& evt);
		void ButtonEquals(wxCommandEvent& evt);
		void ButtonClear(wxCommandEvent& evt);
		void ButtonMultiply(wxCommandEvent& evt);
		void ButtonMinus(wxCommandEvent& evt);
		void ButtonDivide(wxCommandEvent& evt);
		void ButtonAdd(wxCommandEvent& evt);
		void ButtonModulo(wxCommandEvent& evt);
	    void ButtonDecimal(wxCommandEvent& evt);
		
		void ButtonSin(wxCommandEvent& evt);
		void ButtonCos(wxCommandEvent& evt);
		void ButtonTan(wxCommandEvent& evt);
		void ButtonNegativePositive(wxCommandEvent& evt);
		wxBoxSizer* mainSizer;

public:

	Window();

	wxTextCtrl* GetTextBox() { return textBox; }
};

