#pragma once
#include <wx/wx.h>
#include <string>

class App : public wxApp {
  public:
   virtual bool OnInit();

   // Function to show errors
   virtual bool OnExceptionInMainLoop() override {
      try {
         throw;
      } catch (std::exception &e) {
         MessageBoxA(NULL, e.what(), "C++ Exception Caught", MB_OK);
      }
      return true;  // continue on. Return false to abort program
   }
};
