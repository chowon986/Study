#include "Random.h"
#include <cstdlib>
#include <ctime>

int Random::next()
{
	n = rand();
	return n;
}

int Random::nextInRange(int a, int b)
{
	n = rand()%(b-a+1)+a;
		return n;
}
