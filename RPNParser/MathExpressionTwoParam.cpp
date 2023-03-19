#include "MathExpressionTwoParam.h"

#include <cmath>

double MathExpressionTwoParam::GetValue() const
{
	if (!(a && b))
	{
		return 0;
	}
	double Out = 1;
	switch (op)
	{
	case Operator::Add:
		Out = a->GetValue() + b->GetValue();
		break;
	case Operator::Sub:
		Out = a->GetValue() - b->GetValue();
		break;
	case Operator::Mul:
		Out = a->GetValue() * b->GetValue();
		break;
	case Operator::Div:
		Out = a->GetValue() / b->GetValue();
		break;
	case Operator::Pow:
		Out = pow(a->GetValue(), b->GetValue());
		break;
	default:
		break;
	}
	return Out;
}

void MathExpressionTwoParam::Parse(std::vector<std::string>& input)
{
	op = GetOperator(input.back());
	input.pop_back();

	Expression* first = CreateExpression(input);
	if (!first)
		return;
	first->Parse(input);

	Expression* second = CreateExpression(input);
	if (!second)
		return;
	second->Parse(input);

	if (GReversedOrder)
	{
		b = first;
		a = second;
	}
	else 
	{
		a = first;
		b = second;
	}
}

MathExpressionTwoParam::~MathExpressionTwoParam()
{
	if (a)
		delete a;
	if (b)
		delete b;
}

