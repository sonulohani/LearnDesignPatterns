#pragma once

#include "..\\01 FactoryMethod\\FactoryMethod.h"
using namespace FactoryMethod;

namespace Adapter
{
	class IRealAdditiveOperations
	{
	public:
		virtual double Add(double u, double v) = 0;
		virtual double Sub(double u, double v) = 0;
	};

	class RealAdditiveOperations : public IRealAdditiveOperations
	{
	public:
		double Add(double u, double v)
		{
			IRealAdder *pRealAdder = nullptr;
			IRealAdderFactory *pRealAdderFactory = new RealAdderFactory();
			pRealAdder = pRealAdderFactory->CreateRealAdder();
			delete pRealAdderFactory; pRealAdderFactory = nullptr;
			double result = pRealAdder->Add(u, v);
			delete pRealAdder; pRealAdder = nullptr;
			return result;
		}
		double Sub(double u, double v)
		{
			return Add(u, -v);
		}
	};
}