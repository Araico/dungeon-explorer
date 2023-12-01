#include "ItemsFrame.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "../../classes/GameManager.h"

enum IDs { LOAD_CSV_BUTTON_ID = 1, USE_ITEM_BUTTON_ID = 50 };

ItemsFrame::ItemsFrame(const wxString& title, MainFrame* mainFrame)
    : wxFrame(nullptr, wxID_ANY, title) {

   this->mainFrame = mainFrame;

   AddMenuBar();
   AddItemsListView();

   BindEvents();
}

void ItemsFrame::refreshFrame() {}

void ItemsFrame::AddMenuBar() {
   wxMenu* menuFile = new wxMenu;
   menuFile->Append(LOAD_CSV_BUTTON_ID, "&Load items.csv");

   // menu bar
   wxMenuBar* menuBar = new wxMenuBar;
   menuBar->Append(menuFile, "&File");

   SetMenuBar(menuBar);
}

void ItemsFrame::AddItemsListView() {
   itemsListView = new wxListView(this, wxID_ANY, wxDefaultPosition,
                                  wxDefaultSize, wxLC_REPORT);

   // Set up columns in the list view
   itemsListView->AppendColumn("Name", wxLIST_FORMAT_LEFT);
   itemsListView->AppendColumn("Type", wxLIST_FORMAT_LEFT);
   itemsListView->AppendColumn("Description", wxLIST_FORMAT_LEFT);
   itemsListView->AppendColumn("Value", wxLIST_FORMAT_LEFT);

   // Create a sizer to arrange the controls
   wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
   mainSizer->Add(itemsListView, 1, wxEXPAND | wxALL, 10);
   SetSizer(mainSizer);

   // Create a sizer for the button
   use_item_button =
       new wxButton(this, IDs::USE_ITEM_BUTTON_ID, wxT("Use item"),
                    wxDefaultPosition, wxSize(300, 25), 0);
   use_item_button->Enable(false);

   wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
   buttonSizer->Add(use_item_button, 0, wxALL, 10);
   mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER_HORIZONTAL);
}

void ItemsFrame::BindEvents() {
   Bind(wxEVT_MENU, &ItemsFrame::OnLoadCSV, this, LOAD_CSV_BUTTON_ID);
   Bind(wxEVT_BUTTON, &ItemsFrame::OnUseItem, this, USE_ITEM_BUTTON_ID);
}

void ItemsFrame::AppendSpellToListView(const string name, const string type,
                                       const string description,
                                       const string value) {

   int lastIndex = itemsListView->GetItemCount();

   itemsListView->InsertItem(lastIndex, type);
   itemsListView->SetItem(lastIndex, 1, name);
   itemsListView->SetItem(lastIndex, 2, description);
   itemsListView->SetItem(lastIndex, 3, value);
}

void ItemsFrame::OnUseItem(wxCommandEvent& event) {

   int itemIndex = itemsListView->GetFocusedItem();

   if (itemIndex >= 0) {
      Spell spell = GameManager::useItem(itemIndex);

      // Remove the item from the wxListView
      itemsListView->DeleteItem(itemIndex);

      mainFrame->refreshUI();

      wxMessageBox("Used: " + spell.getName(), "Item");
   }

   //
}

///------------------------- event functions:--------------------------------
void ItemsFrame::OnLoadCSV(wxCommandEvent& event) {

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

      if (columns.size() != 4) {
         wxLogError("Invalid items.csv");
         return;
      }

      //------------Load items  into linked list----------------------
      Spell tempSpell(columns[1], (columns[0]), columns[2], stoi(columns[3]));
      GameManager::addItemToList(tempSpell);
   }
   file.close();

   // add linked list elements to ui list
   for (int i = 0; i < GameManager::getItemList().getLength(); i++) {
      Spell temp = GameManager::getItemList()[i];

      AppendSpellToListView(temp.getType(), temp.getName(),
                            temp.getDescription(), to_string(temp.getValue()));
   }

   use_item_button->Enable(true);
}