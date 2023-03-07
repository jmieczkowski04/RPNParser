#pragma once

#include "Expression.h"

enum class Operator
{
	None,
	Add,
	Sub,
	Mul,
	Div,
};

Operator GetOperator(std::string i);

Expression* CreateExpression(std::vector<std::string>& input);