#include "Visitor.h"
using namespace Visitor;

int main()
{
	Real r[] = { 1, 2 }, r_result;
	Complex c[] = { Complex( 1.0, 1.0 ),Complex( 2.0, 2.0 ) }, c_result;

	AddOperationVisitor av;
	SubOperationVisitor sv;

	RealOperation ro;
	ComplexOperation co;

	ro.Accept(av);
	r_result = ro.Operation(r);

	co.Accept(av);
	c_result = co.Operation(c);

	ro.Accept(sv);
	r_result = ro.Operation(r);

	co.Accept(sv);
	c_result = co.Operation(c);

	return 0;
}