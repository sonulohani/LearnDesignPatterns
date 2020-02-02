#pragma once

#include <vector>
using namespace std;

namespace Iterator
{
	class Sequence
	{
	private:
		typedef vector<double> _collection;
		typedef _collection::iterator _iterator;
		
	public:
		class Iterator
		{
		public:
			Iterator( Sequence &sequence )
				: sequence(sequence), it(sequence.numbers.begin()) {}

		public:
			virtual void First()
			{
				it = sequence.numbers.begin();
			}

			virtual void Next()
			{
				it++;
			}

			virtual bool IsDone()
			{
				return it == sequence.numbers.end();
			}

			virtual double CurrentItem()
			{
				return *it;
			}
		private:
			Sequence& sequence;
			_iterator it;
		};
	public:
		void AddNumber( double number )
		{
			numbers.push_back( number );
		}

		Iterator *CreateIterator()
		{
			return new Iterator( *this );
		}

	private:
		_collection numbers;
	};
}
