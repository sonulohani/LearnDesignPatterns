#pragma once

namespace TemplateMethod
{
	class Algorithm
	{
	public:
		void Execute()
		{
			SetTerminate(false);
			Init();
			do 
			{
				PreInput(); if(terminate) break;
				Input(); if(terminate) break;
				Process(); if(terminate) break;
				Output(); if(terminate) break;
				Terminate(); if(terminate) break;
			} while (1);
			OnTerminate();
		}
	public:
		void SetTerminate(bool terminate = true) {this->terminate = terminate;}
	public:
		virtual void Init() {}
		virtual void PreInput() {}
		virtual void Input() {}
		virtual void Process() {}
		virtual void Output() {}
		virtual void Terminate() {
			SetTerminate();
		}
		virtual void OnTerminate() {}
	private:
		bool terminate;
	};

	class SimpleInterestAlgorithm : public Algorithm
	{
	public:
		void PreInput();
		void Input();
		void Process();
		void Output();
	private:
		double principle;
		int noOfYears;
		double interestRate;
		double simpleInterest;
	};
}