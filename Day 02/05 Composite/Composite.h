#pragma once

#include <map>
#include <string>
using namespace std;

namespace Composite
{
	typedef map<string, double> SymbolTable;
	typedef std::pair<string, double> SymbolTableEntry;

	enum OpeationConstants
	{
		Add,
		Sub,
		Mul,
		Div
	};

	class OperationNotSupportedException
	{
	};

	class IExpression
	{
	public:
		virtual double Evaluate(SymbolTable &symbolTable) = 0;
	};

	class Constant : public IExpression
	{
	public:
		Constant(double value) : value(value) {}
	public:
		double Evaluate(SymbolTable &symbolTable)
		{
			return value;
		}
	private:
		double value;
	};

	class Variable : public IExpression
	{
	public:
		Variable(string variableName) : variableName(variableName) {}
	public:
		double Evaluate(SymbolTable &symbolTable)
		{
			return symbolTable[variableName];
		}
	private:
		string variableName;
	};

	class BinaryOperation : public IExpression
	{
	public:
		BinaryOperation(OpeationConstants operation, IExpression &lhs, IExpression &rhs)
			: operation(operation), lhs(lhs), rhs(rhs) {}
	public:
		double Evaluate(SymbolTable &symbolTable)
		{
			switch (operation)
			{
			case Add:
				return lhs.Evaluate(symbolTable) + rhs.Evaluate(symbolTable);
			case Sub:
				return lhs.Evaluate(symbolTable) - rhs.Evaluate(symbolTable);
			case Mul:
				return lhs.Evaluate(symbolTable) * rhs.Evaluate(symbolTable);
			case Div:
				return lhs.Evaluate(symbolTable) / rhs.Evaluate(symbolTable);
			}
			throw OperationNotSupportedException();
		}
	private:
		OpeationConstants operation;
		IExpression &lhs;
		IExpression &rhs;
	};
}