#include "ConstExpression.h"
#include <string>

#include <iostream>

double ConstExpression::GetValue()
{
	return Value;
}

void ConstExpression::Parse(std::vector<std::string>& input)
{
	std::string v = input.back();
	input.pop_back();
	Value = std::stod(v);
}