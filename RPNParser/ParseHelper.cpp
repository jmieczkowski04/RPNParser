#include "ParseHelper.h"
#include "ConstExpression.h"
#include "MathExpressionTwoParam.h"
#include "MathExpressionOneParam.h"

#include <algorithm>
#include <regex>
#include "xxhash.h"

//xxhashed functions
#define SQRT	0x1CAC55EAAF7B4466
#define ABS		0x334A2BAA36EF2A93
#define SIN		0xAE8218BE62EA760B
#define COS		0x4AF0EE5D46AC31A4

//xxhashed constants
#define PI	0xD2E3A8A90A0D1151
#define E	0xE5E72E5E3BEC4A78


//values of constants
#define PI_VALUE	3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define E_VALUE		2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274

Expression* CreateExpression(std::vector<std::string>& input)
{
	Expression* Out = nullptr;
	if (!input.size())
	{
		ConstExpression* v = new ConstExpression;
		Out = v;
		v->Value = 0;
		v->bSet = true;
		return Out;
	}

	std::string back = input.back();

	if (Operator op = GetOperator(back); op != Operator::None)
	{
		if (op > Operator::_DoubleParam)
			Out = new MathExpressionOneParam;	
		else
			Out = new MathExpressionTwoParam;
	}
	else if (is_constant(back) || is_number(back))
	{
		Out = new ConstExpression;
	}
	else
	{
		ConstExpression* v = new ConstExpression;
		Out = v;
		v->Value = 0;
		v->bSet = true;
		return Out;
	}
	
	return Out;
}

Operator GetOperator(std::string i)
{
	if (i.length() == 0)
		return Operator::None;

	Operator op = Operator::None;

	if (i.length() > 1)
	{
		std::transform(i.begin(), i.end(), i.begin(), tolower);
		XXH64_hash_t hashedOperator = XXH3_64bits(i.c_str(), i.size());
		switch (hashedOperator)
		{
		case SQRT: 
			op = Operator::Sqrt;
			break;
		case ABS:
			op = Operator::Abs;
			break;
		case SIN:
			op = Operator::Sin;
			break;
		case COS:
			op = Operator::Cos;
			break;
		default:
			op = Operator::None;
			break;
		}
		return op;
	}

	char v = i[0];
	switch (v)
	{
	case '+':
		op = Operator::Add;
		break;
	case '-':
		op = Operator::Sub;
		break;
	case '*':
		op = Operator::Mul;
		break;
	case '/':
		op = Operator::Div;
		break;
	case '^':
		op = Operator::Pow;
		break;
	default:
		op = Operator::None;
	}
	return op;
}

bool is_number(std::string& str)
{	
	static std::regex num("-?[0-9]+([.][0-9]+)?");
	return std::regex_match(str, num);
}

bool is_constant(std::string& str)
{
	bool Out = true;
	XXH64_hash_t hashedString = XXH3_64bits(str.c_str(), str.size());

	switch (hashedString)
	{
	case PI:
	case E:
		break;
	default:
		Out = false;
		break;
	}
	return Out;
}

double get_constant(std::string& str)
{
	double Out = 0;
	XXH64_hash_t hashedString = XXH3_64bits(str.c_str(), str.size());

	switch (hashedString)
	{
	case PI:
		Out = PI_VALUE;
		break;
	case E:
		Out = E_VALUE;
		break;
	default:
		break;
	}
	return Out;
}