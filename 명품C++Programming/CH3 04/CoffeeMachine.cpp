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
	std::cout << "Ŀ�� �ӽ� ����, Ŀ��:" << std::setw(2) << std::left << coffee << " ��:" << std::setw(2) << std::left << water << " ����:" << std::setw(2) << std::left << sugar << std::endl;
}

void CoffeeMachine::fill()
{
	coffee = 10;
	water = 10;
	sugar = 10;
}
