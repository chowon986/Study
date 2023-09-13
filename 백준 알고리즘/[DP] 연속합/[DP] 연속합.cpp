// [DP] 연속합

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> d(n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a[i] = temp;
	}

	d[0] = a[0];
	int maxValue = d[0];

	for (int i = 1; i < n; i++)
	{
		d[i] = max(a[i], d[i - 1] + a[i]);
		maxValue = max(maxValue, d[i]);
	}

	cout << maxValue;
}