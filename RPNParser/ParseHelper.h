#pragma once

#include "Expression.h"

#include <map>
#include <stack>

extern bool GReversedOrder;
extern bool GParsingFunction;
extern std::map<std::string, Expression*> GFunctionStore;
extern std::stack<double> GContextStack;

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

bool is_constant(std::string& str);

double get_constant(std::string& str);