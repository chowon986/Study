// [복습] 가장 긴 바이토닉 부분수열

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> numbers(n);
	vector<int> d(n, 1);
	vector<int> a(n, 1);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		numbers[i] = temp;
	}
	
	// 오름차순 수열의 길이를 구한다.
	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (numbers[i] > numbers[j])
			{
				d[i] = max(d[j] + 1, d[i]);
			}
		}
	}

	// reverse 후 오름차순 수열의 길이를 구한다.
	reverse(numbers.begin(), numbers.end());

	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (numbers[i] > numbers[j])
			{
				a[i] = max(a[j] + 1, a[i]);
			}
		}
	}

	int maxCount = -1;
	for (int i = 0; i < n; i++)
	{
		maxCount = max(d[i] + a[n - i - 1], maxCount);
	}

	cout << maxCount - 1;
}