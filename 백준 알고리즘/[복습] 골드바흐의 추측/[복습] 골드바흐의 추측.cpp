// [복습] 골드바흐의 추측

#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000

vector<bool> d(MAX + 1, true);

bool IsPrimeAndOddNum(int num)
{
	if (num % 2 == 0) return false;

	return d[num];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	d[0] = d[1] = false;
	
	for (int i = 2; i <= MAX; i++)
	{
		if (!d[i]) continue;

		for (int j = 2; i * j <= MAX; j++)
		{
			if (d[i * j]) d[i * j] = false;
		}
	}

	int n;

	while (cin >> n)
	{
		if (n == 0)
			return 0;

		for (int i = 2; i <= n; i++)
		{
			if (IsPrimeAndOddNum(i) && IsPrimeAndOddNum(n - i))
			{
				cout << n << " = " << i << " + " << n - i << '\n';
				break;
			}
		}
	}
}
