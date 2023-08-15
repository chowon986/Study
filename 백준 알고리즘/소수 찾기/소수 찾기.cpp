// 소수 찾기.cpp : https://www.acmicpc.net/problem/1978

#include <iostream>
using namespace std;

int main()
{
	int count;
	cin >> count;
	int answer = 0;

	for (int i = 0; i < count; i++)
	{
		int num;
		cin >> num;

		bool isPrime = true;
		for (int j = 2; j < num; j++)
		{
			if (num % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (num == 1) isPrime = false;

		if (isPrime)
			++answer;
	}

	cout << answer;
}