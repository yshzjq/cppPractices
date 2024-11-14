#include "Calculator.h"

void Add::setValue(int _a, int _b)
{
	a = _a;
	b = _b;
}

int Add::calculate()
{
	return a+b;
}


void Sub::setValue(int _a, int _b)
{
	a = _a;
	b = _b;
}

int Sub::calculate()
{
	return a - b;
}

void Mul::setValue(int _a, int _b)
{
	a = _a;
	b = _b;
}

int Mul::calculate()
{
	return a * b;
}


void Div::setValue(int _a, int _b)
{
	a = _a;
	b = _b;
}

int Div::calculate()
{
	return a / b;
}
