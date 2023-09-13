// [DP] 정수 삼각형

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> a(n + 1, vector<int>(n + 1));
	vector<vector<int>> d(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int temp;
			cin >> temp;
			a[i][j] = temp;
		}
	}

	int maxValue = -1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
			maxValue = max(maxValue, d[i][j]);
		}
	}

	cout << maxValue;
}