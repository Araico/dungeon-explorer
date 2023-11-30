#pragma once
#include <wx/listctrl.h>
#include <wx/wx.h>
#include <string>

using namespace std;

class MainFrame : public wxFrame {
  private:
   void BindEvents();

   int lastRolledD20 = 0;
   int lastRolledD10 = 0;
   int lastRolledD8 = 0;

  protected:
   wxStaticText* hp_label;
   wxGauge* hp_bar;
   wxStaticText* hp_text;
   wxStaticText* map_title;
   wxStaticText* lp_label;
   wxGauge* lp_bar1;
   wxStaticText* lp_text;
   wxButton* D20_button;
   wxStaticText* D20_text;
   wxButton* D10_button;
   wxStaticText* D10_text;
   wxButton* D8_button;
   wxStaticText* D8_text;
   wxStaticText* current_dungeon_text;
   wxStaticText* mode_status_text;
   wxStaticText* turn_text;
   wxStaticText* enemy_hp_text;
   wxGauge* enemy_hp_bar;
   wxStaticText* enemy_title;
   wxStaticText* enemy_name_text;

  public:
   MainFrame(const wxString& title);
   void refreshUI();
   void OnD20(wxCommandEvent& event);
   void OnD10(wxCommandEvent& event);
   void OnD8(wxCommandEvent& event);
};
