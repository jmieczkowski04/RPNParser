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
	Expression* a;
	Expression* b;
	Operator op;


};