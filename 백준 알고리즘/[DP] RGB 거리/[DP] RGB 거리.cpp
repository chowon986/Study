// [DP] RGB 거리

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> colors(n, vector<int>(3));
	vector<vector<int>> d(n, vector<int>(3));

	int a = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		colors[i][0] = a;
		colors[i][1] = b;
		colors[i][2] = c;
	}

	d[0][0] = colors[0][0];
	d[0][1] = colors[0][1];
	d[0][2] = colors[0][2];

	for (int i = 1; i < n; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + colors[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + colors[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + colors[i][2];
	}

	int minValue = 1000 * n;

	for (int i = 0; i < 3; i++)
	{
		minValue = min(d[n - 1][i], minValue);
	}

	cout << minValue;
}