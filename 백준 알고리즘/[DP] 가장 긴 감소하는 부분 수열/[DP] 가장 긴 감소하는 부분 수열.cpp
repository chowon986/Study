// [DP] 가장 긴 감소하는 부분 수열

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> d(n, 1);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a[i] = temp;
	}

	reverse(a.begin(), a.end());

	int maxValue = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] > a[j])
				d[i] = max(d[i], d[j] + 1);
		}

		maxValue = max(d[i], maxValue);
	}

	cout << maxValue;
}