#include "Random.h"
#include <cstdlib>
#include <ctime>

Random::Random()
{
}

int Random::next()
{
	srand((unsigned)time(0));
}

int Random::nextInRange(int a, int b)
{
	srand((unsigned)time(0));
	int n = rand();
	if (n >= a && n <= b)
	{
		return n;
	}
}
