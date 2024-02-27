#pragma once

#include "Expression.h"
#include "ParseHelper.h"


class FunctionExpression : public Expression
{
public:
	virtual double GetValue() const override;
	virtual void Parse(std::vector<std::string>& input) override;
	~FunctionExpression();
private:
	std::string name;
	Expression* ctx = nullptr;
	Operator op = Operator::None;
};