// [DP] 포도주 시식

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> d(n + 1, vector<int>(3));
	vector<int> a(n + 1);

	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		a[i] = temp;
	}

	for (int i = 1; i <= n; i++)
	{
		d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}

	cout << max(d[n][0], max(d[n][1], d[n][2]));
}