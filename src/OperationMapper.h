#pragma once
#include <functional>
#include <unordered_map>

class OperationMapper
{
	std::unordered_map<char, std::function<double(double, double)>> mOperations;

	static double Add(double a, double b);
	static double Subtract(double a, double b);
	static double Multiply(double a, double b);
	static double Divide(double a, double b);
	static double Power(double input, double powerOf);

	void PopulateMap();

public:

	OperationMapper()
	{
		PopulateMap();
	}

	std::function<double(double, double)> GetOperation(char opr);
};
