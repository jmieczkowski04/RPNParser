#include "FunctionExpression.h"

double FunctionExpression::GetValue() const
{
    if(!ctx || name.empty() || !GFunctionStore.contains(name))
        return 0.0;
    GContextStack.push(ctx->GetValue());
    double Out = GFunctionStore[name]->GetValue();
    GContextStack.pop();
    return Out;
}

void FunctionExpression::Parse(std::vector<std::string>& input)
{
    name = input.back();
    input.pop_back();
    ctx = CreateExpression(input);
    if (!ctx)
        return;
    ctx->Parse(input);
}

FunctionExpression::~FunctionExpression()
{
    delete ctx;
}
