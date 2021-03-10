#include <iostream>
#include "Calculator.h"

double Calculator::Calculate(const std::string& input)
{
	mParser.Clear();
	mTree.Clear();

	std::vector<EquationNode> parsedInput = mParser.ParseInput(input);

	if (!mParser.InputIsValid())
	{
		std::cout << "[SYNTAX ERROR]" << std::endl;
		return 0;
	}

	for (auto& node : parsedInput)
	{
		mTree.Insert(&node);
	}

	return mTree.CalculateResult();
}

void Calculator::Print(const std::vector<EquationNode>& nodes) const
{
	int i = 0;
	for (const EquationNode& c : nodes)
	{
		std::cout << "Element " << i << ": " << c.GetValue() << ", " << c.GetOperator() << std::endl;
		i++;
	}
}
