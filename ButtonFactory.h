#pragma once
#include "wx\wx.h"
#include "App.h"
#include <wx/msw/window.h>

class ButtonFactory 
{  
public:

	
	static wxButton* CreateBtn(wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size));

	static wxButton* CreateNumberBtn(wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size));
	static wxButton* CreateOperationBtn(wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size));
	static wxButton* CreateFunctionBtn(wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size));
	static wxButton* CreateClearBtn(wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size));
	static wxButton* CreateBackSpaceBtn(wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size));
	static wxButton* CreateEqualBtn(wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size));
	

};

