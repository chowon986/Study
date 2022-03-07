#include "EvenRandom.h"
#include <cstdlib>
#include <ctime>

int EvenRandom::next()
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

int EvenRandom::nextInRange(int a, int b)
{
	n = rand() % (b - a + 1) + a;
	if (n % 2 == 0)
	{
		return n;
	}

	else if (n % 2 != 0)
	{
		return n - 1;
	}
}
