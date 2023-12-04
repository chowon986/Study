// 농구 경기.cpp 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int cnt;
	cin >> cnt;

	int names[26] = { 0, };

	for (int i = 0; i < cnt; i++)
	{
		string temp;
		cin >> temp;

		++names[temp[0] - 'a'];
	}

	bool check = false;

	for (int i = 0; i < 26; i++)
	{
		if (names[i] >= 5)
		{
			check = true;
			cout << char(i + 'a');
		}
	}

	if (!check)
		cout << "PREDAJA";
}