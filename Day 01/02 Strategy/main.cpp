#include <memory>
#include <iostream>
using namespace std;

#include "Strategy.h"
using namespace Strategy;

int main()
{
	Sequence s;

	s.AddNumber(-1);
	s.AddNumber(2);
	s.AddNumber(-3);
	s.AddNumber(-4);
	s.AddNumber(5);

	unique_ptr<Sequence::Iterator> it(s.CreateIterator());
	double d;

	//checking if sequence is empty
	if(it->IsDone())
		return 0;

	cout << "Displaying all numbers" << endl;

	it->First();

	while( !it->IsDone() )
	{
		d = it->CurrentItem();
		cout << d << endl;
		it->Next();
	}

	cout << "Displaying only positive numbers" << endl;

	PositiveNumberIteratorFactory positiveNumberIteratorFactory;

	s.SetIteratorFactory( &positiveNumberIteratorFactory );

	unique_ptr<Sequence::Iterator> it2(s.CreateIterator());

	it2->First();

	while( !it2->IsDone() )
	{
		d = it2->CurrentItem();
		cout << d << endl;
		it2->Next();
	}

	return 0;
}