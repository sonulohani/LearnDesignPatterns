#include "ChainOfResponsibility.h"
using namespace ChainOfResponsibility;

int main()
{
	SubtractionHandler subtractionHandler(nullptr);
	AdditionHandler additionHandler(&subtractionHandler);
	IOperationHandler *pOperationHandler = &additionHandler;

	bool success;
	double result;
	double operands[] = { 1.0, 2.0 };
	success = pOperationHandler->HandleOperation("Sub", operands, result);
	success = pOperationHandler->HandleOperation("Add", operands, result);
	success = pOperationHandler->HandleOperation("Mul", operands, result);

	return 0;
}