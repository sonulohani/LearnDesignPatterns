#include <iostream>
using namespace std;

#include "templatemethod.h"
using namespace TemplateMethod;

void TemplateMethod::SimpleInterestAlgorithm::PreInput()
{
	this->principle = 0.0;
	this->interestRate = 0.0;
	this->noOfYears = 0.0;
	system("cls");
}

void TemplateMethod::SimpleInterestAlgorithm::Input()
{
	cout << "Input Principle: ";
	cin >> this->principle;

	cout << "Input No of Years: ";
	cin >> this->noOfYears;

	cout << "Input Interest Rate per Annum: ";
	cin >> this->interestRate;
}

void TemplateMethod::SimpleInterestAlgorithm::Process()
{
	this->simpleInterest = this->principle * this->noOfYears * this->interestRate / 100;
}

void TemplateMethod::SimpleInterestAlgorithm::Output()
{
	cout << "Simple Interest = " << this->simpleInterest << endl;
}

