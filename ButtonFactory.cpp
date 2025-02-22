#include "ButtonFactory.h"
#include "Windows.h"

wxButton* ButtonFactory::CreateBtn( wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size))
{
	return new wxButton(parent, id, label, pos, size);
}

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

wxButton* ButtonFactory::CreateEqualBtn(wxFrame* parent, int id, const wxString& label, wxPoint(pos), wxSize(size))
{
	return CreateBtn(parent, id, "=", pos, size);

}
