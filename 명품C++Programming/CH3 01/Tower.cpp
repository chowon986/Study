#include "Tower.h"

Tower::Tower()
{
	Height = 1;
}

Tower::Tower(int _Height)
{
	Height = _Height;
}

int Tower::getHeight()
{
	return Height;
}
