#pragma once

#include "Expression.h"
#include "ParseHelper.h"

class MathExpressionOneParam : public Expression
{
public:
	virtual double GetValue() const override;
	virtual void Parse(std::vector<std::string> &input) override;
	~MathExpressionOneParam();

private:
	std::unique_ptr<Expression> inner = nullptr;
	Operator op = Operator::None;
};