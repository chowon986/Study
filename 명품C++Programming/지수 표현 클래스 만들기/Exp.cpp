#include "Exp.h"

Exp::Exp()
{
	Base = 1;
	Index = 1;
}

Exp::Exp(int _Base, int _Index)
{
	Base = _Base;
	Index = _Index;
}

Exp::Exp(int _Base)
{
	Base = _Base;
	Index = 1;
}

int Exp::getValue()
{
	for (int i = 0; i < Index; i++)
	{
		Value *= Base;
	}

	return Value;
}

int Exp::getBase()
{
	return Base;
}

int Exp::getExp()
{
	return Index;
}

bool Exp::equals(Exp b)
{
	if (getValue() == b.getValue())
	{
		return true;
	}
	else
	{
		return false;
	}
}
