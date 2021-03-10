#include <iostream>
#include <string>
#include "Calculator.h"

#define LOG(x) std::cout << (x) << std::endl

int main()
{
	LOG("[STRINGCULATOR] v1.0");
	LOG("");
	LOG("//// Instructions: 1. Enter an equation using numbers, and [+] [-] [*] [/] signs.");
	LOG("////               2. Type [ans] to recall previous result.");
	LOG("////               3. Type [quit] to quit.");
	LOG("//// Note: Use of (Parenthesis) is not yet implemented. Please avoid for now.");
	LOG("");

	std::cout.precision(10);

	const std::string ans = "ans";
	const std::string quit = "quit";
	double result = 0;

	std::string input;
	Calculator calculator;

	while (true)
	{
		LOG("Enter an equation:");

		std::getline(std::cin, input);

		if (input == quit)
			break;

		std::string::size_type found = input.find(ans);
		while (found != std::string::npos)
		{
			std::string resultString = std::to_string(result);
			std::string inputLeft = input.substr(0, found);
			std::string inputRight = input.substr(found + ans.size(),
				input.size() - ans.size() + inputLeft.size());

			if (!inputLeft.empty() && std::isdigit(*(inputLeft.end() - 1))
				|| !inputRight.empty() && std::isdigit(inputRight[0]))
			{
				LOG("[SYNTAX ERROR]");
				continue;
			}

			input = inputLeft + resultString + inputRight;
			found = input.find(ans);
		}

		if (input.empty())
			input = "0";

		result = calculator.Calculate(input);
		std::cout << "Result: " << result << std::endl;
		LOG("");
	}
	
	return 0;
}
