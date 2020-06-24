// FarmStrayVoltage.cpp : main project file.

#include "stdafx.h"
#include "ScrSplash.h"
#include "Form1.h"

using namespace Microsoft::VisualBasic::ApplicationServices;
using namespace FarmStrayVoltage;

public ref class MyApp : WindowsFormsApplicationBase {
protected:
  virtual void OnCreateSplashScreen() override {
    this->SplashScreen = gcnew ScrSplash;
  }
virtual void OnCreateMainForm() override {
    // Do your initialization work here...
    //..
    //System:: Threading:: Thread:: Sleep(2000);   // Pretend we're doing work

    // Then create the main form, the splash screen will automatically close
    this->MainForm = gcnew Form1;
  }
};

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 


	// Create the main window and run it
	 // Create app instance
  MyApp^ app = gcnew MyApp;
  app->Run(args);
  return 0;

}
