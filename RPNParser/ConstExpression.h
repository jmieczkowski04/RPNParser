#pragma once

#include "Expression.h"
#include <memory>

class ConstExpression : public Expression
{
public:
	double GetValue() const override;
	virtual void Parse(std::vector<std::string> &input) override;

private:
	double Value;
	bool bSet = false;
	friend std::unique_ptr<Expression> CreateExpression(std::vector<std::string> &input);
};