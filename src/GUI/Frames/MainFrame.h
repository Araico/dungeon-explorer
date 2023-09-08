#pragma once
#include <wx/listctrl.h>
#include <wx/wx.h>
#include <string>
#include "../../classes/MonsterManager.h"

using namespace std;

class MainFrame : public wxFrame {
  private:
   // Atributes
   MonsterManager& monsterManager;

   wxListView* monsterListView;

   ///
   void OnLoadCSV(wxCommandEvent& event);
   void AddMenuBar();
   void AddMonsterListView();
   void BindEvents();

   void AppendMonsterToListView(const string name, string cr, const string type,
                                const string size, const string ac,
                                const string hp, const string align);

  public:
   MainFrame(const wxString& title, MonsterManager& monsterManager);
};
