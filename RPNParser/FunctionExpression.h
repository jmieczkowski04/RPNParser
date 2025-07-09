#pragma once

#include "Expression.h"
#include "ParseHelper.h"
#include <memory>

class FunctionExpression : public Expression
{
public:
	virtual double GetValue() const override;
	virtual void Parse(std::vector<std::string> &input) override;

private:
	std::string name;
	std::unique_ptr<Expression> ctx = nullptr;
	Operator op = Operator::None;
};