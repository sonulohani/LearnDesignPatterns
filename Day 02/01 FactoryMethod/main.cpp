#include "FactoryMethod.h"
using namespace FactoryMethod;

int main()
{
	IRealAdderFactory *pRealAdderFactory = new RealAdderFactory;
	IRealAdder *pRealAdder = pRealAdderFactory->CreateRealAdder();

	double u = 1.0, v = 2.0, w = 0.0;

	w = pRealAdder->Add(u,v);

	delete pRealAdder;
	delete pRealAdderFactory;

	return 0;
}