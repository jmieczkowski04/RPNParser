#pragma once

#include "Expression.h"

#include <unordered_map>
#include <stack>
#include <memory>

using function_store = std::unordered_map<std::string, std::shared_ptr<Expression>>;

extern bool GReversedOrder;
extern bool GParsingFunction;
extern function_store GFunctionStore;
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

std::unique_ptr<Expression> CreateExpression(std::vector<std::string> &input);

bool is_number(std::string &str);

bool is_constant(std::string &str);

double get_constant(std::string &str);