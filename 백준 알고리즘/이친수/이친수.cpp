// 이친수

#include <iostream>
using namespace std;

long long D[91][2];
// D[i][0] = D[i-1][0] + D[i-1][1]
// D[i][1] = D[i-1][0]

int main()
{
	int n;
	cin >> n;

	D[1][0] = 0;
	D[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		D[i][0] += D[i - 1][0] + D[i - 1][1];
		D[i][1] += D[i - 1][0];
	}

	cout << D[n][0] + D[n][1];
}