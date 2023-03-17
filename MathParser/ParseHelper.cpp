#include "ParseHelper.h"
#include "ConstExpression.h"
#include "MathExpressionTwoParam.h"
#include "MathExpressionOneParam.h"

#include <algorithm>


Expression* CreateExpression(std::vector<std::string>& input)
{
	Expression* Out = nullptr;
	std::string back = input.back();

	if (Operator op = GetOperator(back); op != Operator::None)
	{
		if(op > Operator::_DoubleParam)
			Out = new MathExpressionOneParam;
		else
			Out = new MathExpressionTwoParam;
	}
	else if (back == "PI")
	{
		Out = new ConstExpression;
	}
	else
	{
		//should check if number
		Out = new ConstExpression;
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
		if (i == "sqrt")
		{
			op = Operator::Sqrt;
		}
		else if (i == "abs")
		{
			op = Operator::Abs;
		}
		else if (i == "sin")
		{
			op = Operator::Sin;
		}
		else if (i == "cos")
		{
			op = Operator::Cos;
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