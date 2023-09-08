#pragma once
#include <wx/wx.h>
#include <string>
#include "../classes/MonsterManager.h"

class App : public wxApp {
  private:
   MonsterManager monsterManager;

  public:
   virtual bool OnInit();
};
