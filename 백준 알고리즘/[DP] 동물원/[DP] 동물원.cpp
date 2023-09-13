// [DP] 동물원

#include <iostream>
#include <vector>
using namespace std;

#define MOD 9901

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> b(n + 1, vector<int>(3));

	b[0][0] = 1;
	b[0][1] = b[0][2] = 0;

	for (int i = 1; i <= n; i++)
	{
		b[i][0] += (b[i - 1][0] + b[i - 1][1] + b[i-1][2]) % MOD;
		b[i][1] += (b[i - 1][0] + b[i - 1][2]) % MOD;
		b[i][2] += (b[i - 1][0] + b[i - 1][1]) % MOD;
	}

	cout << (b[n][0] + b[n][1] + b[n][2]) % MOD;
}