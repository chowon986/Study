// [DP] 가장 긴 증가하는 부분 수열

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> b;
	vector<int> a(n + 1, 1);

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		b.push_back(temp);
	}

	int maxValue = -1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (b[i] > b[j])
			{
				a[i] = max(a[i], a[j] + 1);
				maxValue = max(a[i], maxValue);
			}
		}
	}

	cout << maxValue;

}