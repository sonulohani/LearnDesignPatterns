#include "Proxy.h"
using namespace Proxy;

int main()
{
	Proxy::RealAdditiveOpeationClient client;

	try
	{
		double result;
		result = client.Add(1.0, 2.0);
		result = client.Sub(1.0, 2.0);
	}
	catch (OperationNotSupportedException e)
	{

	}

	return 0;
}