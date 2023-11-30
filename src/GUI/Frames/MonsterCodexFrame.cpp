#include "MonsterCodexFrame.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "../../classes/GameManager.h"

enum IDs { LOAD_CSV_BUTTON_ID = 1, TEST = 0 };

MonsterCodexFrame::MonsterCodexFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title) {

   AddMenuBar();
   AddMonsterListView();

   BindEvents();
}

void MonsterCodexFrame::AddMenuBar() {
   wxMenu* menuFile = new wxMenu;
   menuFile->Append(LOAD_CSV_BUTTON_ID, "&Load monsters.csv");

   // menu bar
   wxMenuBar* menuBar = new wxMenuBar;
   menuBar->Append(menuFile, "&File");

   SetMenuBar(menuBar);
}

void MonsterCodexFrame::AddMonsterListView() {
   monsterListView = new wxListView(this, wxID_ANY, wxDefaultPosition,
                                    wxDefaultSize, wxLC_REPORT);

   // Set up columns in the list view
   monsterListView->AppendColumn("Name", wxLIST_FORMAT_LEFT);
   monsterListView->AppendColumn("CR", wxLIST_FORMAT_LEFT);
   monsterListView->AppendColumn("Type", wxLIST_FORMAT_LEFT);
   monsterListView->AppendColumn("Size", wxLIST_FORMAT_LEFT);
   monsterListView->AppendColumn("AC", wxLIST_FORMAT_LEFT);
   monsterListView->AppendColumn("HP", wxLIST_FORMAT_LEFT);
   monsterListView->AppendColumn("Align", wxLIST_FORMAT_LEFT);

   // Create a sizer to arrange the controls
   wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
   mainSizer->Add(monsterListView, 1, wxEXPAND | wxALL, 10);
   SetSizer(mainSizer);
}

void MonsterCodexFrame::BindEvents() {
   Bind(wxEVT_MENU, &MonsterCodexFrame::OnLoadCSV, this, LOAD_CSV_BUTTON_ID);
}

void MonsterCodexFrame::AppendMonsterToListView(
    const string name, string cr, const string type, const string size,
    const string ac, const string hp, const string align) {

   int lastIndex = monsterListView->GetItemCount();

   monsterListView->InsertItem(lastIndex, name);
   monsterListView->SetItem(lastIndex, 1, cr);
   monsterListView->SetItem(lastIndex, 2, type);
   monsterListView->SetItem(lastIndex, 3, size);
   monsterListView->SetItem(lastIndex, 4, ac);
   monsterListView->SetItem(lastIndex, 5, hp);
   monsterListView->SetItem(lastIndex, 6, align);
}

///------------------------- event functions:--------------------------------
void MonsterCodexFrame::OnLoadCSV(wxCommandEvent& event) {

   wxFileDialog openFileDialog(this, _("Open CSV File"), "", "",
                               "CSV files (*.csv)|*.csv",
                               wxFD_OPEN | wxFD_FILE_MUST_EXIST);

   if (openFileDialog.ShowModal() == wxID_CANCEL)
      return;  // the user cancelled the dialog

   wxString filePath = openFileDialog.GetPath();

   // wxLogMessage(filePath);

   ifstream file;
   file.open(filePath.ToStdString());
   string line;
   // getline(file, line);
   bool isFirstLine = true;
   while (getline(file, line)) {
      if (isFirstLine) {
         isFirstLine = false;
         continue;
      }

      vector<string> columns;
      stringstream ss(line);
      string item;

      while (getline(ss, item, ',')) {
         columns.push_back(item);
      }

      if (columns.size() != 7) {
         wxLogError("Invalid monsters.csv");
         return;
      }

      //------------Load monsterts into linked list----------------------
      Monster tempMonster(columns[0], stof(columns[1]), columns[2], columns[3],
                          stoi(columns[4]), stoi(columns[5]), columns[6]);
      GameManager::addMonsterToList(tempMonster);
   }
   file.close();

   // add linked list elements to ui list
   for (int i = 0; i < GameManager::getMonsterList().getLength(); i++) {
      Monster temp = GameManager::getMonsterList()[i];

      AppendMonsterToListView(temp.getName(), to_string(temp.getCr()),
                              temp.getType(), temp.getSize(),
                              to_string(temp.getAc()), to_string(temp.getHp()),
                              temp.getAlign());
   }

   GameManager::startNewGame();
}