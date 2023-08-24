// 2xN 타일링 : https://www.acmicpc.net/problem/11727

#include <iostream>
#include <vector>
using namespace std;

vector<int> f(1001);

int main()
{
	int n;
	cin >> n;

	f[0] = 1;
	f[1] = 1;
	f[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		f[i] = (f[i - 1] + f[i - 2] * 2) % 10007;
	}

	cout << f[n];
}