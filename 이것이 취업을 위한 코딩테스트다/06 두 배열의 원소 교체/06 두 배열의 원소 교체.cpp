// 06 두 배열의 원소 교체

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> a;
	vector<int> b;

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		b.push_back(temp);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	for (int i = 0; i < k; i++)
	{
		if (a[i] < b[i])
		{
			swap(a[i], b[i]);
		}
	}

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}

	cout << sum;
}