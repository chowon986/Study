#pragma once

class Exp
{
public:
	int Base;
	int Index;
	int Value = 1;

public:
	Exp();
	Exp(int _Base, int _Index);
	Exp(int _Base);

public:
	int getValue();
	int getBase();
	int getExp();
	bool equals(Exp b);
};

