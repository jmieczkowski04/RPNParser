#include "ConstExpression.h"
#include <string>

#include "ParseHelper.h"

double ConstExpression::GetValue() const
{
	return Value;
}

void ConstExpression::Parse(std::vector<std::string>& input)
{
	if (bSet)
		return;
	bSet = true;
	std::string v = input.back();
	input.pop_back();
	if (is_constant(v))
		Value = get_constant(v);
	else
		Value = std::stod(v);
}