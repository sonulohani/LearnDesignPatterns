#include "Composite.h"
using namespace Composite;

// a + b * c / 2
// a + *bc / 2
// a + /*bc2
// + a/*bc2

int main()
{
	SymbolTable symbolTable;

	symbolTable.insert(SymbolTableEntry("a", 2.0));
	symbolTable.insert(SymbolTableEntry("b", 1.6));
	symbolTable.insert(SymbolTableEntry("c", 3.14));

	Constant two(2.0);
	Variable a("a"), b("b"), c("c");

	BinaryOperation e1(Mul, b, c);
	BinaryOperation e2(Div, e1, two);
	BinaryOperation e3(Add, a, e2);

	double result = e3.Evaluate(symbolTable);

	return 0;
}