#include "App.h"
#include <wx/wx.h>
#include "./Frames/MainFrame.h"

bool App::OnInit() {
   // MainFrame* mainFrame = new MainFrame("Dungeon Explorer", monsterManager);
   MainFrame* mainFrame = new MainFrame("Dungeon Explorer");

   mainFrame->SetClientSize(800, 600);
   mainFrame->Center();
   mainFrame->Show();
   return true;
}