// ROT13.cpp

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string temp;
	getline(cin, temp);

	for (int i = 0; i < temp.size(); i++)
	{
		char k = ' ';
		if (temp[i] >= 'A' && temp[i] <= 'Z')
		{
			if (temp[i] + 13 > 'Z')
				temp[i] = '@' + (temp[i] + 13) % 'Z';
			else
				temp[i] += 13;
		}
		else if (temp[i] >= 'a' && temp[i] <= 'z')
		{
			if (temp[i] + 13 > 'z')
				temp[i] = '`' + (temp[i] + 13) % 'z';
			else
				temp[i] += 13;
		}
	}

	for (auto i : temp)
		cout << i;
}