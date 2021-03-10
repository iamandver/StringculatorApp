#pragma once
#include "EquationNode.h"

class EquationTree
{
	EquationNode* mRoot = nullptr;
	EquationNode* mLastNode = nullptr;
	EquationNode* Compute(EquationNode* node);

public:
	void Clear();
	void Insert(EquationNode* node);
	double CalculateResult();
};
