#include "MainFrame.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "../../enums/MonsterEnums.h"
#include "MonsterCodexFrame.h"

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title) {

   // show monster codex
   MonsterCodexFrame* monsterCodexFrame =
       new MonsterCodexFrame("Monster Codex");
   monsterCodexFrame->Show(true);
   //

   BindEvents();
}

void MainFrame::BindEvents() {
   // Bind(wxEVT_MENU, &MainFrame::OnLoadCSV, this, 1);
}
