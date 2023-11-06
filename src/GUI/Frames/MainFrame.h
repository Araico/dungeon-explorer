#pragma once
#include <wx/listctrl.h>
#include <wx/wx.h>
#include <string>
#include "../../classes/MonsterManager.h"

using namespace std;

class MainFrame : public wxFrame {
  private:
   void BindEvents();

  public:
   MainFrame(const wxString& title, MonsterManager& monsterManager);
};
