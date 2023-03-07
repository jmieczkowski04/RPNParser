#include "MathExpression.h"


double MathExpression::GetValue()
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
	default:
		break;
	}
	return Out;
}

void MathExpression::Parse(std::vector<std::string>& input)
{
	op = GetOperator(input.back());
	input.pop_back();

	b = CreateExpression(input);
	if (!b)
		return;
	b->Parse(input);

	a = CreateExpression(input);
	if (!a)
		return;
	a->Parse(input);
	
}

MathExpression::~MathExpression()
{
	if (a)
		delete a;
	if (b)
		delete b;
}

