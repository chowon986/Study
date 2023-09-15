// [복습] 소수 구하기

#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000

vector<bool> d(MAX + 1, true);

bool IsPrime(int n)
{
	return d[n];
}

int main()
{
	int n, m;
	cin >> n >> m;

	d[0] = d[1] = false;

	for (int i = 2; i <= MAX; i++)
	{
		if (d[i])
		{
			for (int j = 2; i * j <= MAX; j++)
			{
				if (d[i * j]) d[i * j] = false;
			}
		}
	}

	for (int i = n; i <= m; i++)
	{
		if (IsPrime(i)) cout << i << '\n';
	}
}