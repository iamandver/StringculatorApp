#pragma once
#include <string>
#include "InputParser.h"
#include "EquationTree.h"

class Calculator
{
	InputParser mParser;
	EquationTree mTree;

public:
	double Calculate(const std::string& input);
	void Print(const std::vector<EquationNode>& nodes) const;
};
