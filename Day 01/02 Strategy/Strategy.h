#pragma once

#include <vector>
using namespace std;

namespace Strategy
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
		class IteratorFactory
		{
		public:
			virtual Sequence::Iterator* CreateIterator( Sequence &sequence )
			{
				return new Sequence::Iterator(sequence);
			}
		};
	public:
		Sequence()
		{
			SetIteratorFactory();
		}
	public:
		void AddNumber( double number )
		{
			numbers.push_back( number );
		}

		Iterator *CreateIterator()
		{
			return pIteratorFactory->CreateIterator( *this );
		}
		void SetIteratorFactory( IteratorFactory *pIteratorFactory = &iteratorFactory )
		{
			this->pIteratorFactory = pIteratorFactory;
		}

	private:
		_collection numbers;
		IteratorFactory *pIteratorFactory;
	private:
		static IteratorFactory iteratorFactory;
	};

	class PositiveNumberIterator : public Sequence::Iterator
	{
	public:
		PositiveNumberIterator( Sequence &sequence ) : Iterator(sequence) {}
	public:
		void First()
		{
			Sequence::Iterator::First();

			// Sequence is empty
			if( IsDone() )
				return;

			// Found first number as positive number
			if( Sequence::Iterator::CurrentItem() >= 0 )
				return;

			// Search for next positive number
			Next();
		}

		void Next()
		{
			while( !IsDone() )
			{
				Sequence::Iterator::Next();

				if( !IsDone() && CurrentItem() >=0 )
					break;
			}
		}
	};

	class PositiveNumberIteratorFactory : public Sequence::IteratorFactory
	{
	public:
		virtual Sequence::Iterator* CreateIterator( Sequence &sequence )
		{
			return new Strategy::PositiveNumberIterator(sequence);
		}
	};
}