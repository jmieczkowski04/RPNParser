#include "ConstExpression.h"
#include <string>


#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

double ConstExpression::GetValue()
{
	return Value;
}

void ConstExpression::Parse(std::vector<std::string>& input)
{
	std::string v = input.back();
	input.pop_back();
	if (v == "PI")
		Value = PI;
	else
		Value = std::stod(v);
}