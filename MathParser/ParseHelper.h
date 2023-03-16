#pragma once

#include "Expression.h"

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

};

Operator GetOperator(std::string i);

Expression* CreateExpression(std::vector<std::string>& input);