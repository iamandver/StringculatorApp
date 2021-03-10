#pragma once
#include <vector>
#include "EquationNode.h"

class InputParser
{
	const std::vector<char> mOperators{ '+', '-', '*', '/'};
	std::vector<EquationNode> mNodes;

	bool IsNumber(const char& value);
	bool IsNumber(const std::string& value);
	bool IsOperator(const char& value);

public:
	void Clear();
	bool InputIsValid();
	const std::vector<EquationNode>& ParseInput(const std::string& input);
};
