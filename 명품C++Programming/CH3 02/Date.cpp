#include "Date.h"

Date::Date(int _year, int _month, int _day)
{
	Year = _year;
	Month = _month;
	Day = _day;
}

Date::Date(std::string a)
{
	A = a;
}

int Date::Show()
{
	return (int)(Day);
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
