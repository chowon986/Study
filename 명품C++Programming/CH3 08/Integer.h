#pragma once
#include <string>
using namespace std;

class Integer
{
public:
	int num;

public:
	Integer(int _num)
	{
		num = _num;
	}

	Integer(string _num)
	{
		num = stoi(_num);
	}

	int get()
	{
		return num;
	}

	void set(int _num)
	{
		num = _num;
	}

	bool isEven()
	{
		if (num % 2 == 0)
		{
			return 1;
		}
		else if (num % 2 != 0)
		{
			return 0;
		}
	}
};

