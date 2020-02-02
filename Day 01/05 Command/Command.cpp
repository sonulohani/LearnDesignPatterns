#include <conio.h>
#include <string>
#include <iostream>

using namespace std;

#include "Command.h"
using namespace Command;

AddNumberCommand Command::addNumberCommand;
ExitCommand Command::exitCommand;
MenuCommand *Menu::pCommands[] = {&addNumberCommand, &exitCommand};
Terminator *Terminator::pTerminator = nullptr;
Controller *Controller::pController = nullptr;

void AddNumberCommand::Execute()
{
	AddNumberAlgorithm addNumberAlgorithm;
	addNumberAlgorithm.Execute();

	double number = addNumberAlgorithm.GetNumber();
	Controller::GetInstance()->GetRangeModel().AddNumber(number);
	system("pause");
}

void ExitCommand::Execute()
{
	Terminator::GetInstance()->SetTerminate(true);
}

void Menu::PreInput()
{
	int i=0;
	system("cls");
	int commandCount = sizeof(pCommands) / sizeof(MenuCommand*);
	for(i=0;i<commandCount;i++)
	{
		cout << i+1 << " " << pCommands[i]->GetCommandText() << endl;
	}
	cout << "Enter your choice";
}

void Menu::Input()
{
	cin >> choice;
}

void Menu::Process()
{
	int commandCount = sizeof(pCommands) / sizeof(MenuCommand*);
	if( choice < 1 || choice > 2 )
	{
		cout << "Incorrect choice. ";
		system("pause");
		return;
	}
	choice--;
	pCommands[choice]->Execute();

	if(Terminator::GetInstance()->GetTerminate() == true)
		this->SetTerminate();
}

void Menu::Terminate()
{
	SetTerminate(false);
}

void AddNumberAlgorithm::Init()
{
	number = 0.0;
}

void AddNumberAlgorithm::PreInput()
{
	cout << "Input Number: ";
}

void AddNumberAlgorithm::Input()
{
	cin >> number;
}
