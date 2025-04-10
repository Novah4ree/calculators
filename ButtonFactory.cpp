#include "ButtonFactory.h"
#include "Windows.h"
#include "CalculatorProcessor.h"
#include <vector>

//base button method
wxButton* ButtonFactory::CreateBtn( wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size))
{
	return new wxButton(parent, id, label, pos, size);
}
//creates number buttons 0-9 wit event binding
wxButton* ButtonFactory::CreateNumberBtn(wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size))
{
	wxButton* button = new wxButton(parent, id, label);
	parent->Bind(wxEVT_BUTTON, [parent, label](wxCommandEvent& evt) {
		Window* _window = dynamic_cast<Window*>(parent);
		if (_window && _window->GetTextBox()) {
			_window->GetTextBox()->AppendText(label+ " ");
		}
	}, id);
	return button;
		
}
//create operation button
wxButton* ButtonFactory::CreateOperationBtn(wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size))
{
	wxButton* button = CreateBtn(parent, id, label, pos, size);
	parent->Bind(wxEVT_BUTTON, [parent, label](wxCommandEvent& evt) {
		Window* window = dynamic_cast<Window*>(parent);
		if (window) {
			window->GetTextBox()->AppendText(label + " ");
		}
    }, id);
  return button;
}
//creates functions button
wxButton* ButtonFactory::CreateFunctionBtn(wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size))
{
	wxButton* button = CreateBtn(parent, id, label, pos, size);
	parent->Bind(wxEVT_BUTTON, [parent, label](wxCommandEvent& evt) {
		Window* window = dynamic_cast<Window*>(parent);

		if (window) {
			window->GetTextBox()->AppendText(label + "(");
		}
	}, id);
	return button;
}
//create clear button
wxButton* ButtonFactory::CreateClearBtn(wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size))
{
	wxButton* button = CreateBtn(parent, id, "C", pos, size);
	parent->Bind(wxEVT_BUTTON, [parent, label](wxCommandEvent& evt) {
		Window* window = dynamic_cast<Window*>(parent);
		if (window) {
			window->GetTextBox()->Clear();
		}
		}, id);
	return button;
}
//create backspace/ delete button
wxButton* ButtonFactory::CreateBackSpaceBtn(wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size))
{
	wxButton* button = CreateBtn(parent, id, "<-",pos , size);
	parent->Bind(wxEVT_BUTTON, [parent](wxCommandEvent& evt) {
		Window* window = dynamic_cast<Window*>(parent);
		if (window) {
			wxString current = window->GetTextBox()->GetValue();
			if (!current.empty()) {
				window->GetTextBox()->SetValue(current.RemoveLast());

			}
		}
	}, id);
	return button;
}
// create equal button 
wxButton* ButtonFactory::CreateEqualBtn(wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size))
{
	
		wxButton* button = CreateBtn(parent, id, "=", pos, size);
		parent->Bind(wxEVT_BUTTON, [parent](wxCommandEvent& evt) {
			Window* window = dynamic_cast<Window*>(parent);
			if (window) {
				wxString expression = window->GetTextBox()->GetValue();
				expression.Replace(" ", "");

				try {
					double result = CalculatorProcessor::GetInstance()->Calculate(expression.ToStdString());
					window->GetTextBox()->SetValue(wxString::Format("%.2f", result));
				}
				catch (...) {
					window->GetTextBox()->SetValue("Error");
				}
			}
		}, id);
		return button;
	


}
