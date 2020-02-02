#pragma once

#include "../03 ChainOfResponsibility/ChainOfResponsibility.h"
using namespace ChainOfResponsibility;

namespace Proxy
{
	class OperationNotSupportedException
	{
	};

	class OperationHandlerStub : public IOperationHandler
	{
	public:
		OperationHandlerStub()
			: subtractionHandler(nullptr), additionHandler(&subtractionHandler), pOperationHandler(&additionHandler) {}
	public:
		bool HandleOperation(string operation, double operands[], double &result)
		{
			return pOperationHandler->HandleOperation(operation, operands, result);
		}
	private:
		SubtractionHandler subtractionHandler;
		AdditionHandler additionHandler;
		IOperationHandler *pOperationHandler;
	};

	class OperationHandlerProxy : public IOperationHandler
	{
	public:
		bool HandleOperation(string operation, double operands[], double &result)
		{
			OperationHandlerStub operationHandlerStub;
			return operationHandlerStub.HandleOperation(operation, operands, result);
		}
	};

	class RealAdditiveOpeationClient : public IRealAdditiveOperations
	{
	public:
		double Add(double u, double v)
		{
			return HandleOperation("Add", u, v);
		}
		double Sub(double u, double v)
		{
			return HandleOperation("Sub", u, v);
		}
	private:
		double HandleOperation(string operation, double u, double v)
		{
			OperationHandlerProxy proxy;
			bool success;
			double operands[] = { u, v }, result;
			success = proxy.HandleOperation(operation, operands, result);
			if (!success)
				throw OperationNotSupportedException();
			return result;
		}
	};
}