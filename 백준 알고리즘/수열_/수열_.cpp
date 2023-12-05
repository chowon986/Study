// 수열_.cpp
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;

	int n, k;
	cin >> n >> k;

	int maxValue = -10000000;
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (q.size() < k)
		{
			q.push(temp);
			sum += temp;
		}
		if (q.size() == k)
		{
			maxValue = max(maxValue, sum);
			sum -= q.front();
			q.pop();
		}
	}

	cout << maxValue;
}