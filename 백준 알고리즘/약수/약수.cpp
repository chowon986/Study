// 약수.cpp : https://www.acmicpc.net/problem/1037

#include <iostream>
using namespace std;

int main()
{
	int count;
	cin >> count;

	int max = -1;
	int min = 1000001;

	for (int i = 0; i < count; i++)
	{
		int num;
		cin >> num;
		if (num > max) max = num;
		if (num < min) min = num;
	}

	cout << min * max << '\n';
}