// 1.cpp : https://www.acmicpc.net/problem/4375

#include <iostream>
using namespace std;

int main()
{
	int N;

	while (cin >> N)
	{
		int CurNum = 0;

		for (int i = 1; ; i++)
		{
			CurNum = CurNum * 10 + 1;
			CurNum = CurNum % N;
			if (CurNum == 0)
			{
				cout << i << '\n';
				break;
			}
		}
	}
}