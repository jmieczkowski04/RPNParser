#include "ParseHelper.h"
#include "ConstExpression.h"
#include "MathExpression.h"


Expression* CreateExpression(std::vector<std::string>& input)
{
	Expression* Out = nullptr;
	if (GetOperator(input.back()) != Operator::None)
	{
		Out = new MathExpression;
	}
	else if (std::stod(input.back()))
	{
		Out = new ConstExpression;
	}
	return Out;
}

Operator GetOperator(std::string i)
{
	if (i.length() != 1)
		return Operator::None;
	char v = i[0];
	Operator op;
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
	default:
		op = Operator::None;
	}
	return op;
}