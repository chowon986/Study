// [DP] 가장 큰 증가하는 부분 수열

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
		d[i] = temp;
	}

	int maxValue = d[0];

	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] > a[j])
			{
				d[i] = max(d[i], a[i] + d[j]);
			}
		}

		maxValue = max(maxValue, d[i]);
	}

	cout << maxValue;
}