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

void MathExpressionTwoParam::Parse(std::vector<std::string> &input)
{
	op = GetOperator(input.back());
	input.pop_back();

	a = CreateExpression(input);
	if (!a)
		return;
	a->Parse(input);

	b = CreateExpression(input);
	if (!b)
		return;
	b->Parse(input);

	if (GReversedOrder)
	{
		std::swap(a, b);
	}
}

MathExpressionTwoParam::~MathExpressionTwoParam()
{
}
