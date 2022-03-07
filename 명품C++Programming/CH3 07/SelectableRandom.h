#pragma once
class SelectableRandom
{
public:
	int n;

public:
	SelectableRandom(int num);
	int next();
	int nextInRange(int a, int b);
};

