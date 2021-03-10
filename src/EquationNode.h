#pragma once
#include <functional>
#include "OperationMapper.h"

struct EquationNode
{
private:
	OperationMapper mMapper;
	double mValue;
	char mOperator;
	std::function<double(double, double)> mOperation;
	bool mIsNumber;
	EquationNode* mLeft = nullptr;
	EquationNode* mRight = nullptr;

public:
	explicit EquationNode()
		: mValue(0), mOperator(0), mOperation(nullptr), mIsNumber(false)
	{
	}

	explicit EquationNode(const double& val)
		: mValue(val), mOperator(0), mOperation(nullptr), mIsNumber(true)
	{
	}

	explicit EquationNode(const char& opr)
		: mValue(0), mOperator(opr), mIsNumber(false)
	{
		mOperation = mMapper.GetOperation(opr);
	}

	void SetValue(const double& value);
	void SetLeft(EquationNode* left);
	void SetRight(EquationNode* right);
	double GetValue() const;
	char GetOperator() const;
	std::function<double(double, double)> GetOperation() const;
	EquationNode* GetLeft() const;
	EquationNode* GetRight() const;
	bool IsNumber() const;
	bool IsPrimary() const;
};
