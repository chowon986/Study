#include "Date.h"
using namespace std;

Date::Date(int _year, int _month, int _day)
{
	Year = _year;
	Month = _month;
	Day = _day;
}

Date::Date(string _day)
{
	Day2 = _day;
}

void Date::Show()
{
	int len = Day2.length();
	int count = 0;
	int count2 = 0;
	int a = 0;
	for (int i = 0; i < len; i++)
	{
		if (Day2[i] != '/')
		{
			count++;
		}
		else if (Day2[i] == '/')
		{
			break;
		}
	}

	for (int i = 0; i < count; i++)
	{
		std::cout << Day2[i];
	}
	std::cout << "³â";
	
	count2 = count;
	for (int i = ++count; i < len; i++)
	{
		if (Day2[i] != '/')
		{
			count++;
		}
		else if (Day2[i] == '/')
		{
			break;
		}
	}

	for (int i = ++count2; i < count; i++)
	{
		std::cout << Day2[i];
	}

	std::cout << "¿ù";

	for (int i = ++count; i < len; i++)
	{
		std::cout << Day2[i];
	}

	std::cout << "ÀÏ" << endl;
}

int Date::getYear()
{
	return Year;
}

int Date::getMonth()
{
	return Month;
}

int Date::getDay()
{
	return Day;
}
