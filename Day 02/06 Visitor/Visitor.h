#pragma once

namespace Visitor
{
	class Real
	{
	public:
		Real(double real = 0.0) : real(real) {}
	public:
		double GetReal() { return real; }
	private:
		double real;
	};

	class Complex
	{
	public:
		Complex(double real = 0.0, double imaginary = 0.0) : real(real), imaginary(imaginary) {}
	public:
		double GetReal() { return real; }
		double GetImaginary() { return imaginary; }
	private:
		double real;
		double imaginary;
	};

	class OperationNotSupportedException {};

	class OperationVisitor
	{
	public:
		virtual Real Operation(Real operands[]) { throw OperationNotSupportedException(); }
		virtual Complex Operation(Complex operands[]) { throw OperationNotSupportedException(); }
	};

	class AddOperationVisitor : public OperationVisitor
	{
	public:
		Real Operation(Real operands[])
		{
			double result = operands[0].GetReal() + operands[1].GetReal();
			return Real(result);
		}
		Complex Operation(Complex operands[])
		{
			double realResult = operands[0].GetReal() + operands[1].GetReal();
			double imgResult = operands[0].GetImaginary() + operands[1].GetImaginary();
			return Complex(realResult, imgResult);
		}
	};

	class SubOperationVisitor : public OperationVisitor
	{
	public:
		Real Operation(Real operands[])
		{
			double result = operands[0].GetReal() - operands[1].GetReal();
			return Real(result);
		}
		Complex Operation(Complex operands[])
		{
			double realResult = operands[0].GetReal() - operands[1].GetReal();
			double imgResult = operands[0].GetImaginary() - operands[1].GetImaginary();
			return Complex(realResult, imgResult);
		}
	};

	class IOperation
	{
	public:
		virtual void Accept(OperationVisitor &operationVisitor) = 0;
	};

	class RealOperation : public IOperation
	{
	public:
		void Accept(OperationVisitor &operationVisitor)
		{
			pOperationVisitor = &operationVisitor;
		}
	public:
		Real Operation(Real operands[])
		{
			return pOperationVisitor->Operation(operands);
		}
	private:
		OperationVisitor *pOperationVisitor;
	};

	class ComplexOperation : public IOperation
	{
	public:
		void Accept(OperationVisitor &operationVisitor)
		{
			pOperationVisitor = &operationVisitor;
		}
	public:
		Complex Operation(Complex operands[])
		{
			return pOperationVisitor->Operation(operands);
		}
	private:
		OperationVisitor *pOperationVisitor;
	};
}