#pragma once
#include <string>
using namespace std;
#include "../04 TemplateMethod/templatemethod.h"
#include "../03 Observer/Observer.h"
using namespace TemplateMethod;
using namespace Observer;

namespace Command
{
	class Terminator
	{
	public:
		static Terminator *GetInstance(){
			if( pTerminator == nullptr )
				pTerminator = new Terminator;
			return pTerminator;
		}
	public:
		bool GetTerminate() {return terminate;}
	public:
		void SetTerminate( bool terminate ) {this->terminate = terminate;}
	private:
		Terminator() :terminate(false){}
	private:
		static Terminator *pTerminator;
	private:
		bool terminate;
	};

	class Controller
	{
	public:
		static Controller *GetInstance()
		{
			if(pController==nullptr)
				pController = new Controller;
			return pController;
		}
		RangeModel &GetRangeModel(){return rangeModel;}
	private:
		Controller() : minView(rangeModel), sumView(rangeModel) {
			rangeModel.Attach(minView);
			rangeModel.Attach(sumView);
		}
	private:
		RangeModel rangeModel;
		MinView minView;
		SumView sumView;
	private:
		static Controller *pController;
	};

	class MenuCommand
	{
	public:
		MenuCommand(string commandText)
			:commandText(commandText) {}

	public:
		string GetCommandText() { return commandText;}
	public:
		virtual void Execute() = 0;
	private:
		string commandText;
	};

	class AddNumberCommand : public MenuCommand
	{
	public:
		AddNumberCommand() : MenuCommand("Add Number") {}
	public:
		void Execute();
	};

	class ExitCommand : public MenuCommand
	{
	public:
		ExitCommand() : MenuCommand("Exit") {}
	public:
		void Execute();
	};

	extern AddNumberCommand addNumberCommand;
	extern ExitCommand exitCommand;

	class Menu : public Algorithm
	{
	public:
		void PreInput();
		void Input();
		void Process();
		void Terminate();
	private:
		int choice;
	private:
		static MenuCommand *pCommands[];
	};

	class AddNumberAlgorithm : public Algorithm
	{
	public:
		void Init();
		void PreInput();
		void Input();
	public:
		double GetNumber(){return number;}
	private:
		double number;
	};
}
