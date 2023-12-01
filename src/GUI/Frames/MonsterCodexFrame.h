#pragma once
#include <wx/listctrl.h>
#include <wx/wx.h>
#include <string>
#include "ItemsFrame.h"
#include "MainFrame.h"

using namespace std;

class MonsterCodexFrame : public wxFrame {
  private:
   wxListView* monsterListView;

   MainFrame* mainFrame;
   ItemsFrame* itemsFrame;

   ///
   void OnLoadCSV(wxCommandEvent& event);
   void AddMenuBar();
   void AddMonsterListView();
   void BindEvents();

   void AppendMonsterToListView(const string name, string cr, const string type,
                                const string size, const string ac,
                                const string hp, const string align);

  public:
   MonsterCodexFrame(const wxString& title, MainFrame* mainFrame,
                     ItemsFrame* itemsFrame);
};
