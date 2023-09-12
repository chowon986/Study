// [DP] 1, 2, 3 더하기 5

#include <iostream>
using namespace std;

#define MAX 100000
#define MOD 1000000009

long long d[MAX + 1][4];

int main()
{
	int n;
	cin >> n;

	d[1][1] = d[2][2] = d[3][1] = d[3][2] = d[3][3] = 1;

	for (int i = 4; i <= MAX; i++)
	{
		d[i][1] = ((d[i - 1][2] % MOD) + (d[i - 1][3] % MOD)) % MOD;
		d[i][2] = ((d[i - 1][1] % MOD) + (d[i - 1][3] % MOD)) % MOD;
		d[i][3] = ((d[i - 1][1] % MOD) + (d[i - 1][2] % MOD)) % MOD;
	}

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		cout << (d[temp][1] + d[temp][2] + d[temp][3]) % MOD << '\n';
	}
}