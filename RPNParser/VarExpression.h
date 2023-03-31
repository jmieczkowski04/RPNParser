#pragma once

#include "Expression.h"
#include "ParseHelper.h"


class VarExpression : public Expression
{
public:
	virtual double GetValue() const override;
	virtual void Parse(std::vector<std::string>& input) override;
private:
	Operator op;
};