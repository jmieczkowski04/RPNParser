#include "MathExpressionOneParam.h"

double MathExpressionOneParam::GetValue()
{
	if (!inner)
	{
		return 0;
	}
	double Out;
	
	switch (op)
	{
	case Operator::Sqrt:
		Out = sqrt(inner->GetValue());
		break;
	case Operator::Abs:
		Out = abs(inner->GetValue());
		break;
	case Operator::Sin:
		Out = sin(inner->GetValue());
		break;
	case Operator::Cos:
		Out = cos(inner->GetValue());
		break;
	default:
		Out = 1;
		break;
	}

	return Out;
}

void MathExpressionOneParam::Parse(std::vector<std::string>& input)
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
	if (inner)
		delete inner;
}