#pragma once

#include "Expression.h"

extern bool GReversedOrder;

enum class Operator : int
{
	None = 0x0,
	Add,
	Sub,
	Mul,
	Div,
	Pow,

	_DoubleParam,

	Sqrt,
	Abs,
	Sin,
	Cos,

};

Operator GetOperator(std::string i);

Expression* CreateExpression(std::vector<std::string>& input);

bool is_number(std::string& str);