#include "SelectableRandom.h"
#include <cstdlib>
#include <ctime>

SelectableRandom::SelectableRandom(int num)
{
	n = num;
}

int SelectableRandom::next()
{
	n = rand();
	if (n % 2 == 0)
	{
		return n;
	}
	else if (n % 2 != 0)
	{
		return n - 1;
	}
}

int SelectableRandom::nextInRange(int a, int b)
{
	n = rand() % (b - a + 1) + a;
	if (n % 2 == 0)
	{
		return n+1;
	}
	if (n % 2 != 0)
	{
		return n;
	}
}
