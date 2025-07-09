#include "MathExpressionOneParam.h"
#include <cmath>

double MathExpressionOneParam::GetValue() const
{
	if (!inner)
	{
		return 0;
	}
	double Out;

	switch (op)
	{
	case Operator::Sqrt:
		Out = std::sqrt(inner->GetValue());
		break;
	case Operator::Abs:
		Out = std::abs(inner->GetValue());
		break;
	case Operator::Sin:
		Out = std::sin(inner->GetValue());
		break;
	case Operator::Cos:
		Out = std::cos(inner->GetValue());
		break;
	default:
		Out = 1;
		break;
	}

	return Out;
}

void MathExpressionOneParam::Parse(std::vector<std::string> &input)
{
	op = GetOperator(input.back());
	input.pop_back();

	inner = CreateExpression(input);
	if (!inner)
		return;
	inner->Parse(input);
}

MathExpressionOneParam::~MathExpressionOneParam()
{
}