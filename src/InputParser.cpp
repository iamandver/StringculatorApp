#include <iostream>
#include <sstream>
#include "InputParser.h"

bool InputParser::IsNumber(const char& value)
{
	return std::isdigit(static_cast<unsigned char>(value));
}

bool InputParser::IsNumber(const std::string& value)
{
	auto itr = value.begin();

	while (itr != value.end() && std::isdigit(*itr))
	{
		++itr;
	}

	return !value.empty() && itr == value.end();
}

bool InputParser::IsOperator(const char& value)
{
	for (const char& expression : mOperators)
	{
		if (value == expression)
			return true;
	}

	return false;
}

void InputParser::Clear()
{
	mNodes.clear();
}

bool InputParser::InputIsValid()
{
	if (mNodes.size() % 2 == 0)
		return false;

	if (mNodes.empty() || !mNodes[0].IsNumber())
		return false;

	if (mNodes.size() == 1 && mNodes[0].IsNumber())
		return true;

	for (int i = 0; i < mNodes.size() - 2; i++)
	{
		if (!mNodes[i].IsNumber() && !mNodes[i + 1].IsNumber())
			return false;
	}

	return true;
}

const std::vector<EquationNode>& InputParser::ParseInput(const std::string& input)
{
	std::stringstream numberStream;
	std::string buffer;

	for (auto itr = input.begin(); itr != input.end(); ++itr)
	{
		if (IsNumber(*itr) || *itr == '.')
		{
			numberStream << *itr;
		}
		else
		{
			numberStream >> buffer;
			if (!buffer.empty())
			{
				EquationNode node(std::stod(buffer));
				mNodes.emplace_back(node);

				buffer.clear();
			}
			numberStream.str(std::string());
			numberStream.clear();

			if (*itr == ' ')
				continue;

			if (IsOperator(*itr))
			{
				EquationNode node(*itr);
				mNodes.emplace_back(node);
			}
			else
			{
				std::cout << "[ERROR] unknown value: " << *itr << std::endl;
			}
		}

		if (itr == input.end() - 1)
		{
			numberStream >> buffer;
			if (!buffer.empty())
			{
				EquationNode node(std::stod(buffer));
				mNodes.emplace_back(node);

				buffer.clear();
			}

			numberStream.str(std::string());
			numberStream.clear();
		}
	}

	return mNodes;
}
