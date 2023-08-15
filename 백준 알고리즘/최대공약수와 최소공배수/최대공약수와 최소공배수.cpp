// 최대공약수와 최소공배수.cpp : https://www.acmicpc.net/problem/2609

#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int originA = a;
	int originB = b;

	while (true)
	{
		if (a < b)
		{
			int temp = b;
			b = a;
			a = temp;
		}

		int temp = b;
		b = a % b;
		a = temp;

		if (b == 0)
		{
			cout << a << '\n';
			cout << a * (originA / a) * (originB / a);
			break;
		}
	}
}