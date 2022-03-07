#pragma once
#include <string>
#include <iostream>
using namespace std;

class Date
{
public:
	int Year;
	int Month;
	int Day;
	string Day2;

public:
	Date(int _year, int _month, int _day);
	Date(std::string _day);

public:
	void Show();
	int getYear();
	int getMonth();
	int getDay();
};

