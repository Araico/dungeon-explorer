#pragma once
#include <wx/listctrl.h>
#include <wx/wx.h>
#include <string>

using namespace std;

class ItemsFrame : public wxFrame {
  private:
   wxListView* itemsListView;

   ///
   void OnLoadCSV(wxCommandEvent& event);
   void AddMenuBar();
   void AddItemsListView();
   void BindEvents();

   void AppendSpellToListView(const string name, const string type,
                              const string description, const string value);

  public:
   ItemsFrame(const wxString& title);
};
