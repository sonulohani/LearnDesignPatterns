#pragma once

#include <memory>
#include <vector>
#include <iostream>
using namespace std;

#include "../02 Strategy/Strategy.h"
using namespace Strategy;

namespace Observer
{
	class StatisticalView
	{
	public:
		virtual void Update() = 0;
	};

	class Model
	{
	public:
		void Attach( StatisticalView &statisticalView )
		{
			statisticalViews.push_back( &statisticalView );
		}
	public:
		void Notify()
		{
			vector<StatisticalView *>::iterator it;
			for(it = statisticalViews.begin(); it != statisticalViews.end(); it++)
			{
				(*it)->Update();
			}
		}
	private:
		vector<StatisticalView *> statisticalViews;
	};

	class RangeModel : public Model
	{
	public:
		void AddNumber(double number)
		{
			sequence.AddNumber( number );
			Notify();
		}

	public:
		Sequence &GetSequence()
		{
			return sequence;
		}

	private:
		Sequence sequence;
	};

	class SumView : public StatisticalView
	{
	public:
		SumView( RangeModel &rangeModel ) : rangeModel(rangeModel) {}
	public:
		void Update()
		{
			Sequence &s = rangeModel.GetSequence();
			unique_ptr<Sequence::Iterator> it(s.CreateIterator());

			double sum = 0;

			it->First();
			while(!it->IsDone())
			{
				sum += it->CurrentItem();
				it->Next();
			}
			cout << "Sum = " << sum <<endl;
		}
	private:
		RangeModel &rangeModel;
	};

	class MinView : public StatisticalView
	{
	public:
		MinView( RangeModel &rangeModel ) : rangeModel(rangeModel) {}
	public:
		void Update()
		{
			Sequence &s = rangeModel.GetSequence();
			unique_ptr<Sequence::Iterator> it(s.CreateIterator());

			double min = 0;

			it->First();
			if(!it->IsDone())
			{
				min = it->CurrentItem(); it->Next();
				while( !it->IsDone() )
				{
					if( it->CurrentItem() < min )
					{
						min = it->CurrentItem();
					}
					it->Next();
				}
			}
			cout << "Min = " << min <<endl;
		}
	private:
		RangeModel &rangeModel;
	};
}