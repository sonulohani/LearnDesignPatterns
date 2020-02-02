#pragma once 

namespace FactoryMethod
{
	class IRealAdder
	{
	public:
		virtual double Add(double u, double v) = 0;
	};
	class RealAdder : public IRealAdder
	{
	public:
		double Add(double u, double v)
		{
			return u+v;
		}
	};

	class IRealAdderFactory
	{
	public:
		virtual IRealAdder *CreateRealAdder() = 0;
	};

	class RealAdderFactory : public IRealAdderFactory
	{
	public : 
		IRealAdder *CreateRealAdder()
		{
			return new RealAdder;
		}
	};
}