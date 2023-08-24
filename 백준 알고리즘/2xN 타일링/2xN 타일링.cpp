// 2xN 타일링 : https://www.acmicpc.net/problem/11726

#include <iostream>
#include <vector>
using namespace std;

vector<int> f(1000);

int main()
{
	int n;
	cin >> n;

	f[0] = 1;
	f[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}

	cout << f[n];
}