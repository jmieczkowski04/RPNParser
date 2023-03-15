#include "ParseHelper.h"
#include "ConstExpression.h"
#include "MathExpressionTwoParam.h"
#include "MathExpressionOneParam.h"


Expression* CreateExpression(std::vector<std::string>& input)
{
	Expression* Out = nullptr;
	if (Operator op = GetOperator(input.back()); op != Operator::None)
	{
		if(op > Operator::_DoubleParam)
			Out = new MathExpressionOneParam;
		else
			Out = new MathExpressionTwoParam;
	}
	else if (std::stod(input.back()))
	{
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
		if (i == "sqrt")
		{
			op = Operator::Sqrt;
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