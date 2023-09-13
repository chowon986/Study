// [DP] 1, 2, 3 더하기 3

#include <iostream>
using namespace std;

#define MOD 1000000009
#define MAX 1000000

int d[MAX + 1];

int main()
{
	int n;
	cin >> n;

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for(int i = 4; i <= MAX; i++)
	{
		d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % MOD;
	}

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		cout << d[temp] << '\n';
	}
}