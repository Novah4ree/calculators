#pragma once
#include"wx\wx.h"
#include "App.h"


class Window : public wxFrame{
private:

		wxTextCtrl* textBox;
		wxButton* button1, * button2, * button3, * button4, * button5;
		wxButton* button6, * button7, * button8, * button9, * button0;
		wxButton* BackspaceDelete, * Equals, * Clear, * Multiply;

		wxButton* Minus, * Add, * Divide, * Modulo;
		wxButton* sin, * cos, * tan;
		wxButton* NegativePositive, *Negative, *Decimal;

		void Controls();


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
		void ButtonNegative(wxCommandEvent& evt);
		void ButtonSin(wxCommandEvent& evt);
		void ButtonCos(wxCommandEvent& evt);
		void ButtonTan(wxCommandEvent& evt);
		void ButtonNegativePositive(wxCommandEvent& evt);
		void Button(wxCommandEvent& evt);

		DECLARE_EVENT_TABLE();

public:

	Window();

	
};

