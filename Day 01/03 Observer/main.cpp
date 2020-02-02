#include <memory>
#include <iostream>
using namespace std;

#include "Observer.h"
using namespace Observer;

int main()
{
	RangeModel rangeModel;

	MinView minView(rangeModel);
	SumView sumView(rangeModel);

	rangeModel.Attach(minView);
	rangeModel.Attach(sumView);

	system("cls");
	rangeModel.AddNumber(1);

	system("cls");
	rangeModel.AddNumber(5);

	system("cls");
	rangeModel.AddNumber(6);

	system("cls");
	rangeModel.AddNumber(-3);

	PositiveNumberIteratorFactory positiveNumberIteratorFactory;
	rangeModel.GetSequence().SetIteratorFactory(&positiveNumberIteratorFactory);

	system("cls");
	rangeModel.AddNumber(-5);

	return 0;
}