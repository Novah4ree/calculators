#pragma once
#include"wx\wx.h"
#include "App.h"


class Window : public wxFrame{
private:
	
	wxTextCtrl* textBox = nullptr;
    wxButton* sin = nullptr;
    wxButton* cos = nullptr;
    wxButton* tan = nullptr;
    wxButton* button0 = nullptr;
    wxButton* button1 = nullptr;
    wxButton* button2 = nullptr;
    wxButton* button3 = nullptr;
    wxButton* button4 = nullptr;
    wxButton* button5 = nullptr;
    wxButton* button6 = nullptr;
    wxButton* button7 = nullptr;
    wxButton* button8 = nullptr;
    wxButton* button9 = nullptr;
    wxButton* Add = nullptr;
    wxButton* Minus = nullptr;
	wxButton* Multiply = nullptr;
    wxButton* Divide = nullptr;
    wxButton* Modulo = nullptr;
    wxButton* Clear = nullptr;
    wxButton* Equals = nullptr;
    wxButton* Decimal = nullptr;
    wxButton* BackspaceDelete = nullptr;
    wxButton* NegativePositive = nullptr;
    wxButton* button = nullptr;

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

	void BindEvents();

	wxTextCtrl* GetTextBox();
};

