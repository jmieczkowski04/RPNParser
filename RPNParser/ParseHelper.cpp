#include "ParseHelper.h"
#include "ConstExpression.h"
#include "MathExpressionTwoParam.h"
#include "MathExpressionOneParam.h"
#include "VarExpression.h"
#include "FunctionExpression.h"

#include <algorithm>
#include <numbers>
#include <regex>
#include "xxhash.h"

#include "Constants.inl"

function_store GFunctionStore;
std::stack<double> GContextStack;

std::unique_ptr<Expression> CreateExpression(std::vector<std::string> &input)
{
	std::unique_ptr<Expression> Out = nullptr;
	if (!input.size())
	{
		ConstExpression *v = new ConstExpression;
		v->Value = 0;
		v->bSet = true;
		Out.reset(v);
		return Out;
	}

	std::string back = input.back();

	if (Operator op = GetOperator(back); op != Operator::None)
	{
		if (op > Operator::_DoubleParam)
			Out.reset(new MathExpressionOneParam);
		else
			Out.reset(new MathExpressionTwoParam);
	}
	else if (is_constant(back) || is_number(back))
	{
		Out.reset(new ConstExpression);
	}
	else if (GFunctionStore.contains(back))
	{
		Out.reset(new FunctionExpression);
	}
	else if (back == "x" && GParsingFunction)
	{
		Out.reset(new VarExpression);
	}
	else
	{
		ConstExpression *v = new ConstExpression;
		v->Value = 0;
		v->bSet = true;
		Out.reset(v);
		return Out;
	}

	return Out;
}

Operator GetOperator(std::string i)
{
	if (i.length() == 0)
		return Operator::None;

	Operator op = Operator::None;

	if (i.length() > 1)
	{
		std::transform(i.begin(), i.end(), i.begin(), tolower);
		XXH64_hash_t hashedOperator = XXH3_64bits(i.c_str(), i.size());
		switch (hashedOperator)
		{
		case SQRT:
			op = Operator::Sqrt;
			break;
		case ABS:
			op = Operator::Abs;
			break;
		case SIN:
			op = Operator::Sin;
			break;
		case COS:
			op = Operator::Cos;
			break;
		default:
			op = Operator::None;
			break;
		}
		return op;
	}

	char v = i[0];
	switch (v)
	{
	case '+':
		op = Operator::Add;
		break;
	case '-':
		op = Operator::Sub;
		break;
	case '*':
		op = Operator::Mul;
		break;
	case '/':
		op = Operator::Div;
		break;
	case '^':
		op = Operator::Pow;
		break;
	default:
		op = Operator::None;
	}
	return op;
}

bool is_number(std::string &str)
{
	static std::regex num("-?[0-9]+([.][0-9]+)?");
	return std::regex_match(str, num);
}

bool is_constant(std::string &str)
{
	bool Out = true;
	XXH64_hash_t hashedString = XXH3_64bits(str.c_str(), str.size());

	switch (hashedString)
	{
	case PI:
	case E:
		break;
	default:
		Out = false;
		break;
	}
	return Out;
}

double get_constant(std::string &str)
{
	double Out = 0;
	XXH64_hash_t hashedString = XXH3_64bits(str.c_str(), str.size());

	switch (hashedString)
	{
	case PI:
		Out = std::numbers::pi;
		break;
	case E:
		Out = std::numbers::e;
		break;
	default:
		break;
	}
	return Out;
}