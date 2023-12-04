// 팰린드롬인지 확인하기.cpp

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string temp;
	cin >> temp;

	int size = temp.size();

	for (int i = 0; i < size; i++)
	{
		if (temp[i] != temp[size - 1 - i])
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}