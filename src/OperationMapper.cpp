#include "OperationMapper.h"

double OperationMapper::Add(const double a, const double b)
{
	return a + b;
}

double OperationMapper::Subtract(const double a, const double b)
{
	return a - b;
}

double OperationMapper::Multiply(const double a, const double b)
{
	return a * b;
}

double OperationMapper::Divide(const double a, const double b)
{
	return a / b;
}

double OperationMapper::Power(const double input, const double powerOf)
{
	const int intInput = static_cast<int>(input);
	
	if (intInput == 0)
		return 0;

	double result = 1;

	for (int i = static_cast<int>(powerOf); i >= 1; i--)
	{
		result *= input;
	}

	return result;
}

void OperationMapper::PopulateMap()
{
	mOperations['+'] = Add;
	mOperations['-'] = Subtract;
	mOperations['*'] = Multiply;
	mOperations['/'] = Divide;
	mOperations['^'] = Power;
}

std::function<double(double, double)> OperationMapper::GetOperation(char opr)
{
	return mOperations[opr];
}
