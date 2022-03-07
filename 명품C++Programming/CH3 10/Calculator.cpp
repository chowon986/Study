#include "Calculator.h"
#include <iostream>


void Add::setValue(int x, int y)
{
	a = x;
	b = y;
}

void Add::calculate()
{
	std::cout << a + b << std::endl;
}

void Sub::setValue(int x, int y)
{
	a = x;
	b = y;
}

void Sub::calculate()
{
	std::cout << a - b << std::endl;
}

void Mul::setValue(int x, int y)
{
	a = x;
	b = y;
}

void Mul::calculate()
{
	std::cout << a * b << std::endl;
}

void Div::setValue(int x, int y)
{
	a = x;
	b = y;
}

void Div::calculate()
{
	std::cout << a / b << std::endl;
}
