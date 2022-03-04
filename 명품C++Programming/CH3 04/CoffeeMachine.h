#pragma once
class CoffeeMachine
{
public: 
	int coffee;
	int water;
	int sugar;

public:
	CoffeeMachine(int _coffee, int _water, int _sugar);

public:
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugarCoffee();
	void show();
	void fill();
};

