#pragma once
#include <string>
#include <iostream>

class Date
{
public:
	int Year;
	int Month;
	int Day;
	std::string A;

public:
	Date(int _year, int _month, int _day);
	Date(std::string _day);

public:
	int Show();
	int getYear();
	int getMonth();
	int getDay();
};

