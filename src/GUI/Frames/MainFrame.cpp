#include "MainFrame.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "../../enums/MonsterEnums.h"

MainFrame::MainFrame(const wxString& title, MonsterManager& monsterManager)
    : wxFrame(nullptr, wxID_ANY, title), monsterManager(monsterManager) {

   AddMenuBar();
   AddMonsterListView();

   BindEvents();
}

void MainFrame::AddMenuBar() {
   wxMenu* menuFile = new wxMenu;
   menuFile->Append(1, "&Load monsters.csv");

   // menu bar
   wxMenuBar* menuBar = new wxMenuBar;
   menuBar->Append(menuFile, "&File");

   SetMenuBar(menuBar);
}

void MainFrame::AddMonsterListView() {
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

void MainFrame::BindEvents() {
   Bind(wxEVT_MENU, &MainFrame::OnLoadCSV, this, 1);
}

void MainFrame::AppendMonsterToListView(const string name, string cr,
                                        const string type, const string size,
                                        const string ac, const string hp,
                                        const string align) {

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
void MainFrame::OnLoadCSV(wxCommandEvent& event) {

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

      //------------Load monsterts into linked list----------------------
      Monster tempMonster(columns[0], stof(columns[1]), columns[2], columns[3],
                          stoi(columns[4]), stoi(columns[5]), columns[6]);
      monsterManager.AddMonster(tempMonster);
   }
   file.close();

   // add monsters to ui list
   for (int i = 0; i < monsterManager.getMonsterCount(); i++) {
      Monster temp = monsterManager.getMonsterAtIndex(i);

      AppendMonsterToListView(temp.getName(), temp.getType(),
                              to_string(temp.getCr()), temp.getSize(),
                              to_string(temp.getAc()), to_string(temp.getHp()),
                              temp.getAlign());
   }
}