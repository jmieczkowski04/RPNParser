#pragma once

#include "Expression.h"

class ConstExpression : public Expression
{
public: 
	double GetValue() override;
	virtual void Parse(std::vector<std::string>& input) override;

private:
	double Value;
};