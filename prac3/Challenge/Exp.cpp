#include "Exp.h"

// 클래스 구현부
Exp::Exp(int _base, int _exp)
{
	base = _base;
	exp = _exp;
}

Exp::Exp(int _base) : Exp()
{
	base = _base;
}

Exp::Exp()
{
	base = 1;
	exp = 1;
}

int Exp::getBase()
{
	return base;
}

int Exp::getExp()
{
	return exp;
}

int Exp::getValue()
{
	int value = 1;

	for (int i = 0; i < exp; i++)
	{
		value *= base;
	}

	return value;
}

bool Exp::equals(Exp _exp)
{
	if (getValue() == _exp.getValue())
	{
		return true;
	}

	return false;
}