#pragma once


#include "Expression.h"
#include "ParseHelper.h"


class MathExpressionTwoParam : public Expression
{
public:
	virtual double GetValue() const override;
	virtual void Parse(std::vector<std::string>& input) override;
	~MathExpressionTwoParam();
private:
	Expression* a = nullptr;
	Expression* b = nullptr;
	Operator op = Operator::None;
};