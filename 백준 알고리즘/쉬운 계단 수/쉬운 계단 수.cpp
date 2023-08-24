// 쉬운 계단 수 : https://www.acmicpc.net/problem/10844

#include <iostream>
using namespace std;

#define MOD 1000000000

int main()
{
	int n;
	cin >> n;
	int d[101][10] = { 0, };

	for (int i = 1; i <= 9; i++)
	{
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{

			if (d[i][j] > 0)
			{
				continue;
			}

			if (j == 0)
				d[i][j] = d[i - 1][j + 1] % MOD;

			else if (j == 9)
				d[i][j] = d[i - 1][j - 1] % MOD;

			else
			{
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % MOD;
			}
		}
	}

	long long sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += d[n][i];
	}

	cout << sum % MOD;
}