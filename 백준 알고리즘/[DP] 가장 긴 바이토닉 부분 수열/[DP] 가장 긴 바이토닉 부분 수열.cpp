// [DP] 가장 긴 바이토닉 부분 수열

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> d(n, 1);
	vector<int> p(n, 1);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a[i] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] > a[j])
				d[i] = max(d[i], d[j] + 1);
		}
	}

	reverse(a.begin(), a.end());

	for (int i = 0; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] > a[j])
				p[i] = max(p[i], p[j] + 1);
		}
	}

	int maxValue = -1;

	for (int i = 0; i < n; i++)
	{
		maxValue = max(maxValue, d[i] + p[n - i - 1]);
	}

	cout << maxValue - 1;
}