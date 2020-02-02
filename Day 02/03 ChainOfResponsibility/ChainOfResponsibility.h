#pragma once
#include <string>
using namespace std;

#include "../02 Adapter/Adapter.h"
using namespace Adapter;

namespace ChainOfResponsibility
{
	class IOperationHandler
	{
	public:
		virtual bool HandleOperation(string operation, double operands[], double &result) = 0;
	};

	class AdditionHandler : public IOperationHandler
	{
	public:
		AdditionHandler(IOperationHandler *psuccessor) : psuccessor(psuccessor) {}
	public:
		bool HandleOperation(string operation, double operands[], double &result)
		{
			if (operation == "Add")
			{
				RealAdditiveOperations realAdditiveOperations;
				result = realAdditiveOperations.Add(operands[0], operands[1]);
				return true;
			}

			if (psuccessor != nullptr)
				return psuccessor->HandleOperation(operation, operands, result);

			return false;
		}
	private:
		IOperationHandler *psuccessor;
	};

	class SubtractionHandler : public IOperationHandler
	{
	public:
		SubtractionHandler(IOperationHandler *psuccessor) : psuccessor(psuccessor) {}
	public:
		bool HandleOperation(string operation, double operands[], double &result)
		{
			if (operation == "Sub")
			{
				RealAdditiveOperations realAdditiveOperations;
				result = realAdditiveOperations.Sub(operands[0], operands[1]);
				return true;
			}

			if (psuccessor != nullptr)
				return psuccessor->HandleOperation(operation, operands, result);

			return false;
		}
	private:
		IOperationHandler *psuccessor;
	};
}