#pragma once


#include "Expression.h"
#include "ParseHelper.h"


class MathExpression : public Expression
{
public:
	virtual double GetValue() override;
	virtual void Parse(std::vector<std::string>& input) override;
	~MathExpression();
private:
	Expression* a;
	Expression* b;
	Operator op;


};