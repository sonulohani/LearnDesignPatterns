#include <iostream>
using namespace std;

#include "Adapter.h"
using namespace Adapter;

int main()
{
	IRealAdditiveOperations *pRealAdditiveOperations = new RealAdditiveOperations;
	cout << pRealAdditiveOperations->Add(1.0, 2.0) << endl;
	cout << pRealAdditiveOperations->Sub(1.0, 2.0) << endl;
	delete pRealAdditiveOperations;

	return 0;
}