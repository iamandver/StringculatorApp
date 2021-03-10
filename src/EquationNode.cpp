#include "EquationNode.h"

void EquationNode::SetValue(const double& value)
{
	mValue = value;
	mIsNumber = true;
}

void EquationNode::SetLeft(EquationNode* left)
{
	mLeft = left;
}

void EquationNode::SetRight(EquationNode* right)
{
	mRight = right;
}

double EquationNode::GetValue() const
{
	return mValue;
}

char EquationNode::GetOperator() const
{
	return mOperator;
}

std::function<double(double, double)> EquationNode::GetOperation() const
{
	return mOperation;
}

EquationNode* EquationNode::GetLeft() const
{
	return mLeft;
}

EquationNode* EquationNode::GetRight() const
{
	return mRight;
}

bool EquationNode::IsNumber() const
{
	return mIsNumber;
}

bool EquationNode::IsPrimary() const
{
	return mOperator == '*' || mOperator == '/';
}
