// 골드바흐의 추측.cpp : https://www.acmicpc.net/problem/6588

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	vector<bool> prime(1000001, 1);
	prime[0] = prime[1] = 0;

	for (int i = 2; i * i < 1000001; i++)
	{
		if (prime[i] == 1)
		{
			for (int j = i + i; j < 1000001; j += i)
				prime[j] = 0;
		}
	}

	while (true)
	{
		cin >> n;

		if (n == 0)
			return 0;

		for (int i = 2; i < n; i++)
		{
			if (prime[i] == true)
			{
				if (prime[n - i] == true)
				{
					cout << n << " = " << i << " + " << n - i << '\n';
					break;
				}
			}
		}
	}
}