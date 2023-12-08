// 주몽.cpp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> v;
	int startIdx = 0;
	int endIdx = n - 1;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int count = 0;
	while (startIdx < endIdx)
	{
		int temp = v[startIdx] + v[endIdx];

		if (temp == m)
		{
			++count;
			++startIdx;
			--endIdx;
		}
		else if (temp > m)
			--endIdx;
		else
			++startIdx;
	}

	cout << count;
}