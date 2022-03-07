#include "Oval.h"
#include <iostream>

Oval::Oval()
{
	width = 1;
	height = 1;
}

Oval::Oval(int _width, int _height)
{
	width = _width;
	height = _height;
}

Oval::~Oval()
{
	std::cout << "Oval ¼Ò¸ê : width = " << width << ", height = " << height << std::endl;
}

int Oval::getWidth()
{
	return width;
}

int Oval::getHeight()
{
	return height;
}

void Oval::set(int w, int h)
{
	width = w;
	height = h;
}

void Oval::show()
{
	std::cout << "width = " << width << ", height = " << height << std::endl;
}
