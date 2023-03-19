#pragma once

#include <vector>
#include <string>

class Expression
{
public:
	virtual double GetValue() const = 0;
	virtual void Parse(std::vector<std::string>& input) = 0;
};