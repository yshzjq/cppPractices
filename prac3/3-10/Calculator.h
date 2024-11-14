#ifndef CALCULATOR_H
#define CALCULATOR_H
class Add
{
	int a;
	int b;
public:
	void setValue(int x,int y);
	int calculate();
};

class Sub
{
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};

class Mul
{
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};

class Div
{
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};

#endif