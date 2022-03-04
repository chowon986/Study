#include "CoffeeMachine.h"
#include <iostream>
#include <iomanip>

CoffeeMachine::CoffeeMachine(int _coffee, int _water, int _sugar)
{
	coffee = _coffee;
	water = _water;
	sugar = _sugar;
}

void CoffeeMachine::drinkEspresso()
{
	coffee -= 1;
	water -= 1;
}

void CoffeeMachine::drinkAmericano()
{
	coffee -= 1;
	water -= 2;
}

void CoffeeMachine::drinkSugarCoffee()
{
	coffee -= 1;
	water -= 2;
	sugar -= 1;
}

void CoffeeMachine::show()
{
	std::cout << "커피 머신 상태, 커피:" << std::setw(2) << std::left << coffee << " 물:" << std::setw(2) << std::left << water << " 설탕:" << std::setw(2) << std::left << sugar << std::endl;
}

void CoffeeMachine::fill()
{
	coffee = 10;
	water = 10;
	sugar = 10;
}
