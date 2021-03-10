#include "EquationTree.h"

void EquationTree::Insert(EquationNode* node)
{
	if (mRoot == nullptr)
	{
		mRoot = node;
		return;
	}

	if (mLastNode == nullptr)
	{
		node->SetLeft(mRoot);
		mRoot = node;
		mLastNode = mRoot;
		return;
	}

	if (!node->IsNumber())
	{
		EquationNode* temp;

		if (!node->IsPrimary())
		{
			temp = mRoot;
			mRoot = node;
			mRoot->SetLeft(temp);
			mLastNode = mRoot;
		}
		else
		{
			temp = mLastNode->GetRight();
			mLastNode->SetRight(node);
			mLastNode = node;
			mLastNode->SetLeft(temp);
		}
	}
	else
	{
		if (mLastNode->GetRight() == nullptr)
			mLastNode->SetRight(node);
	}
}

double EquationTree::CalculateResult()
{
	mRoot = Compute(mRoot);
	return mRoot->GetValue();
}

EquationNode* EquationTree::Compute(EquationNode* node)
{
	if (node->IsNumber())
		return node;

	EquationNode* left = Compute(node->GetLeft());
	EquationNode* right = Compute(node->GetRight());
	double result = node->GetOperation()(left->GetValue(), right->GetValue());
	node->SetValue(result);

	return node;
}

void EquationTree::Clear()
{
	mRoot = nullptr;
	mLastNode = nullptr;
}
