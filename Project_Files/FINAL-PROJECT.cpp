// FINAL-PROJECT.cpp : main project file.
#include "stdafx.h"
#include "Events.h"

using namespace FINALPROJECT;

Game mygame;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	InitializeIDTable();
	//timer1->Start();

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
