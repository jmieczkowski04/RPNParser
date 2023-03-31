#include "VarExpression.h"

double VarExpression::GetValue() const
{
    if(GContextStack.empty())
        return 0.0;
    return GContextStack.top();
}

void VarExpression::Parse(std::vector<std::string>& input)
{
    input.pop_back();
}
