#pragma once
#include <wx/listctrl.h>
#include <wx/wx.h>
#include <string>
#include "MainFrame.h"

using namespace std;

class ItemsFrame : public wxFrame {
  private:
   MainFrame* mainFrame;

   wxListView* itemsListView;
   wxButton* use_item_button;

   ///
   void OnLoadCSV(wxCommandEvent& event);
   void AddMenuBar();
   void AddItemsListView();
   void BindEvents();

   void AppendSpellToListView(const string name, const string type,
                              const string description, const string value);

  public:
   ItemsFrame(const wxString& title, MainFrame* mainFrame);

   void refreshFrame();

   void OnUseItem(wxCommandEvent& event);
};
