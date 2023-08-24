// 1, 2, 3 더하기 : https://www.acmicpc.net/problem/15990

#include <iostream>
using namespace std;

#define MAX 100000
#define MOD 1000000009

long long D[MAX + 1][4];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	D[1][1] = D[2][2] = D[3][1] = D[3][2] = D[3][3] = 1;

	for (int i = 4; i <= MAX; i++)
	{
		D[i][1] = ((D[i - 1][2] % MOD) + (D[i - 1][3] % MOD)) % MOD;
		D[i][2] = ((D[i - 2][1] % MOD) + (D[i - 2][3] % MOD)) % MOD;
		D[i][3] = ((D[i - 3][1] % MOD) + (D[i - 3][2] % MOD)) % MOD;
	}

	for (int i = 0; i < tc; i++)
	{
		int temp;
		cin >> temp;
		cout << (D[temp][1] + D[temp][2] + D[temp][3]) % MOD << '\n';
	}
}