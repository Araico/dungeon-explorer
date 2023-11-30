#include "MainFrame.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../../classes/GameManager.h"
#include "ItemsFrame.h"
#include "MonsterCodexFrame.h"

enum IDs { D20_BUTTON_ID = 1, D10_BUTTON_ID = 2, D8_BUTTON_ID = 3 };

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title) {

   // show monster codex
   MonsterCodexFrame* monsterCodexFrame =
       new MonsterCodexFrame("Monster Codex");
   monsterCodexFrame->Show(true);
   //

   // show items
   ItemsFrame* itemsFrame = new ItemsFrame("Items");
   itemsFrame->Show(true);
   //

   this->SetSizeHints(wxDefaultSize, wxDefaultSize);

   wxBoxSizer* main_boxSizer;
   main_boxSizer = new wxBoxSizer(wxVERTICAL);

   wxBoxSizer* top_boxSizer;
   top_boxSizer = new wxBoxSizer(wxHORIZONTAL);

   wxGridSizer* top_boxSizer_grid;
   top_boxSizer_grid = new wxGridSizer(0, 2, 0, 0);

   wxBoxSizer* hp_boxSizer;
   hp_boxSizer = new wxBoxSizer(wxHORIZONTAL);

   hp_label = new wxStaticText(this, wxID_ANY, wxT("HP"), wxDefaultPosition,
                               wxDefaultSize, 0);
   hp_label->Wrap(-1);
   hp_boxSizer->Add(hp_label, 0, wxALL, 5);

   hp_bar = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize,
                        wxGA_HORIZONTAL);
   hp_bar->SetValue(10);
   hp_boxSizer->Add(hp_bar, 0, wxALL, 5);

   hp_text = new wxStaticText(this, wxID_ANY, wxT("10"), wxDefaultPosition,
                              wxDefaultSize, 0);
   hp_text->Wrap(-1);
   hp_boxSizer->Add(hp_text, 0, wxALL, 5);

   top_boxSizer_grid->Add(hp_boxSizer, 1, wxEXPAND, 5);

   map_title = new wxStaticText(this, wxID_ANY, wxT("Map"), wxDefaultPosition,
                                wxDefaultSize, 0);
   map_title->Wrap(-1);
   top_boxSizer_grid->Add(map_title, 0, wxALIGN_CENTER | wxALL, 5);

   wxBoxSizer* lp_boxSizer;
   lp_boxSizer = new wxBoxSizer(wxHORIZONTAL);

   lp_label = new wxStaticText(this, wxID_ANY, wxT("LP"), wxDefaultPosition,
                               wxDefaultSize, 0);
   lp_label->Wrap(-1);
   lp_boxSizer->Add(lp_label, 0, wxALL, 5);

   lp_bar1 = new wxGauge(this, wxID_ANY, 999, wxDefaultPosition, wxDefaultSize,
                         wxGA_HORIZONTAL);
   lp_bar1->SetValue(100);
   lp_boxSizer->Add(lp_bar1, 0, wxALL, 5);

   lp_text = new wxStaticText(this, wxID_ANY, "100", wxDefaultPosition,
                              wxDefaultSize, 0);
   lp_text->Wrap(-1);
   lp_boxSizer->Add(lp_text, 0, wxALL, 5);

   top_boxSizer_grid->Add(lp_boxSizer, 1, wxEXPAND, 5);

   top_boxSizer->Add(top_boxSizer_grid, 1, wxEXPAND, 5);

   main_boxSizer->Add(top_boxSizer, 0, wxEXPAND, 1);

   wxGridSizer* main_grid;
   main_grid = new wxGridSizer(0, 2, 0, 0);

   wxBoxSizer* dice_boxSizer;
   dice_boxSizer = new wxBoxSizer(wxVERTICAL);

   wxBoxSizer* D20_boxSizer;
   D20_boxSizer = new wxBoxSizer(wxHORIZONTAL);

   D20_button = new wxButton(this, IDs::D20_BUTTON_ID, wxT("Roll D20"),
                             wxDefaultPosition, wxSize(200, 100), 0);
   D20_button->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                              wxFONTWEIGHT_NORMAL, false, wxEmptyString));

   D20_boxSizer->Add(D20_button, 0, wxALL, 5);

   D20_text = new wxStaticText(this, wxID_ANY, "0", wxDefaultPosition,
                               wxDefaultSize, 0);
   D20_text->Wrap(-1);
   D20_text->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                            wxFONTWEIGHT_NORMAL, false, wxEmptyString));
   D20_text->SetBackgroundColour(
       wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));

   D20_boxSizer->Add(D20_text, 0, wxALL, 5);

   dice_boxSizer->Add(D20_boxSizer, 1, wxEXPAND, 5);

   wxBoxSizer* D10_boxSizer;
   D10_boxSizer = new wxBoxSizer(wxHORIZONTAL);

   D10_button = new wxButton(this, IDs::D10_BUTTON_ID, wxT("Roll D10"),
                             wxDefaultPosition, wxSize(200, 100), 0);
   D10_button->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                              wxFONTWEIGHT_NORMAL, false, wxEmptyString));
   D10_button->Enable(false);

   D10_boxSizer->Add(D10_button, 0, wxALL, 5);

   D10_text = new wxStaticText(this, wxID_ANY, "0", wxDefaultPosition,
                               wxDefaultSize, 0);
   D10_text->Wrap(-1);
   D10_text->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                            wxFONTWEIGHT_NORMAL, false, wxEmptyString));
   D10_text->SetBackgroundColour(
       wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));

   D10_boxSizer->Add(D10_text, 0, wxALL, 5);

   dice_boxSizer->Add(D10_boxSizer, 1, wxEXPAND, 5);

   wxBoxSizer* D8_boxSizer;
   D8_boxSizer = new wxBoxSizer(wxHORIZONTAL);

   D8_button = new wxButton(this, IDs::D8_BUTTON_ID, wxT("Roll D8"),
                            wxDefaultPosition, wxSize(200, 100), 0);
   D8_button->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                             wxFONTWEIGHT_NORMAL, false, wxEmptyString));
   D8_button->Enable(false);

   D8_boxSizer->Add(D8_button, 0, wxALL, 5);

   D8_text = new wxStaticText(this, wxID_ANY, "0", wxDefaultPosition,
                              wxDefaultSize, 0);
   D8_text->Wrap(-1);
   D8_text->SetFont(wxFont(60, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                           wxFONTWEIGHT_NORMAL, false, wxEmptyString));
   D8_text->SetBackgroundColour(
       wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));

   D8_boxSizer->Add(D8_text, 0, wxALL, 5);

   dice_boxSizer->Add(D8_boxSizer, 1, wxEXPAND, 5);

   main_grid->Add(dice_boxSizer, 1, wxEXPAND, 5);

   wxBoxSizer* dungeon_boxSizer;
   dungeon_boxSizer = new wxBoxSizer(wxVERTICAL);

   wxBoxSizer* dungeon_info_boxSizer;
   dungeon_info_boxSizer = new wxBoxSizer(wxVERTICAL);

   current_dungeon_text = new wxStaticText(this, wxID_ANY, "Dungeon: NA",
                                           wxDefaultPosition, wxDefaultSize, 0);
   current_dungeon_text->Wrap(-1);
   current_dungeon_text->SetFont(wxFont(40, wxFONTFAMILY_DEFAULT,
                                        wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL,
                                        false, wxEmptyString));

   dungeon_info_boxSizer->Add(current_dungeon_text, 0, wxALIGN_CENTER | wxALL,
                              5);

   mode_status_text = new wxStaticText(this, wxID_ANY, wxT("EXPLORE MODE"),
                                       wxDefaultPosition, wxDefaultSize, 0);
   mode_status_text->Wrap(-1);
   mode_status_text->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT,
                                    wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL,
                                    false, wxEmptyString));
   mode_status_text->SetBackgroundColour(
       wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

   dungeon_info_boxSizer->Add(mode_status_text, 0, wxALIGN_CENTER | wxALL, 5);

   turn_text = new wxStaticText(this, wxID_ANY, wxT("PLAYER'S TURN"),
                                wxDefaultPosition, wxDefaultSize, 0);
   turn_text->Wrap(-1);
   turn_text->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                             wxFONTWEIGHT_NORMAL, false, wxEmptyString));
   turn_text->SetBackgroundColour(
       wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

   dungeon_info_boxSizer->Add(turn_text, 0, wxALIGN_CENTER | wxALL, 5);

   wxBoxSizer* enemy_info_boxSizer;
   enemy_info_boxSizer = new wxBoxSizer(wxVERTICAL);

   wxBoxSizer* enemy_hp_boxSizer;
   enemy_hp_boxSizer = new wxBoxSizer(wxHORIZONTAL);

   enemy_hp_text = new wxStaticText(this, wxID_ANY, wxT("NA"),
                                    wxDefaultPosition, wxDefaultSize, 0);
   enemy_hp_text->Wrap(-1);
   enemy_hp_boxSizer->Add(enemy_hp_text, 0, wxALL, 5);

   enemy_hp_bar = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition,
                              wxDefaultSize, wxGA_HORIZONTAL);
   enemy_hp_bar->SetValue(0);
   enemy_hp_boxSizer->Add(enemy_hp_bar, 0, wxALL, 5);

   enemy_info_boxSizer->Add(enemy_hp_boxSizer, 0, 0, 5);

   wxBoxSizer* enemy_name_boxSizer;
   enemy_name_boxSizer = new wxBoxSizer(wxVERTICAL);

   enemy_title = new wxStaticText(this, wxID_ANY, wxT("Enemy:"),
                                  wxDefaultPosition, wxDefaultSize, 0);
   enemy_title->Wrap(-1);
   enemy_title->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                               wxFONTWEIGHT_NORMAL, false, wxEmptyString));

   enemy_name_boxSizer->Add(enemy_title, 0, wxALL, 5);

   enemy_name_text = new wxStaticText(this, wxID_ANY, wxT("NA"),
                                      wxDefaultPosition, wxDefaultSize, 0);
   enemy_name_text->Wrap(-1);
   enemy_name_text->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                                   wxFONTWEIGHT_NORMAL, false, wxEmptyString));

   enemy_name_boxSizer->Add(enemy_name_text, 0, wxALL, 5);

   enemy_info_boxSizer->Add(enemy_name_boxSizer, 0, wxALIGN_CENTER_HORIZONTAL,
                            5);

   dungeon_info_boxSizer->Add(enemy_info_boxSizer, 1, wxALIGN_CENTER_HORIZONTAL,
                              5);

   dungeon_boxSizer->Add(dungeon_info_boxSizer, 1, wxEXPAND, 5);

   main_grid->Add(dungeon_boxSizer, 1, wxEXPAND, 5);

   main_boxSizer->Add(main_grid, 1, wxEXPAND, 5);

   this->SetSizer(main_boxSizer);
   this->Layout();

   this->Centre(wxBOTH);

   BindEvents();
}

void MainFrame::refreshUI() {
   GameState gameState = GameManager::getGameState();

   // Check if player is dead
   if (gameState == GameState::DEAD) {
      wxLogMessage("Dead");
   }

   // update buttons enable
   D20_button->Enable(gameState == GameState::D20);
   D10_button->Enable(gameState == GameState::D10_PLAYER ||
                      gameState == GameState::D10_PLAYER);
   D8_button->Enable(gameState == GameState::D8);

   // update mode text
   mode_status_text->SetLabel(
       (gameState == GameState::D10_ENEMY || gameState == GameState::D10_PLAYER)
           ? "COMBAT MODE"
       : gameState == GameState::D20 ? "EXPLORE MODE"
                                     : "REST MODE");

   // upodate turn text
   turn_text->SetLabel(gameState == GameState::D10_ENEMY    ? "ENEMIE'S TURN"
                       : gameState == GameState::D10_PLAYER ? "PLAYER'S TURN"
                                                            : "PLAYER'S TURN");

   // update monster info
   Monster* activeMonster = GameManager::getActiveDungeon()->getMonster();

   if (activeMonster->getHp() > 0) {
      D20_button->Enable(false);
      D10_button->Enable(true);

      enemy_name_text->SetLabel(activeMonster->getName());

      enemy_hp_bar->SetRange(activeMonster->getHp());
      enemy_hp_bar->SetValue(activeMonster->getHp());
      enemy_hp_text->SetLabel(std::to_string(activeMonster->getHp()));
   } else {
      enemy_name_text->SetLabel("Defeated");

      enemy_hp_bar->SetValue(0);
      enemy_hp_text->SetLabel("NA");
   }

   // update player stats:
   hp_text->SetLabel(std::to_string(GameManager::getPlayerHp()));
   hp_bar->SetValue(GameManager::getPlayerHp());

   lp_text->SetLabel(std::to_string(GameManager::getPlayerLp()));
   lp_bar1->SetValue(GameManager::getPlayerLp());
}

void MainFrame::OnD20(wxCommandEvent& event) {
   if (GameManager::getMonsterList().getLength() == 0 ||
       GameManager::getItemList().getLength() == 0) {
      wxLogMessage("Load monsters.csv to start");
      return;
   }

   int rolledNumber = GameManager::moveToRandomDungeon() + 1;

   D20_text->SetLabel(std::to_string(rolledNumber));
   current_dungeon_text->SetLabel("Dungeon: " + std::to_string(rolledNumber));

   refreshUI();
}

void MainFrame::OnD10(wxCommandEvent& event) {
   bool isPlayersTurn = GameManager::getGameState() == GameState::D10_PLAYER;

   int rolledNumber;

   if (isPlayersTurn) {
      rolledNumber = GameManager::playerAttack();
   } else {
      rolledNumber = GameManager::enemyAttack();
   }

   D10_text->SetLabel(std::to_string(rolledNumber));

   refreshUI();
}

void MainFrame::OnD8(wxCommandEvent& event) {
   int rolledNumber = GameManager::recoverPlayerLP();

   D8_text->SetLabel(std::to_string(rolledNumber));

   refreshUI();
}

void MainFrame::BindEvents() {
   Bind(wxEVT_BUTTON, &MainFrame::OnD20, this, IDs::D20_BUTTON_ID);
   Bind(wxEVT_BUTTON, &MainFrame::OnD10, this, IDs::D10_BUTTON_ID);
   Bind(wxEVT_BUTTON, &MainFrame::OnD8, this, IDs::D8_BUTTON_ID);
}
