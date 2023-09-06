// 03 떡볶이 떡 만들기

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	vector<int> b;
//
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//		b.push_back(temp);
//	}
//
//	sort(b.begin(), b.end(), greater<>());
//
//	int maxValue = -1;
//
//	for (int i = b[0]; i > 0; i--)
//	{
//		int sum = 0;
//		for (int j = 0; j < b.size(); j++)
//		{
//			if (b[j] - i > 0)
//			{
//				sum += b[j] - i;
//			}
//		}
//
//		if (sum >= m)
//		{
//			maxValue = max(maxValue, i);
//		}
//	}
//
//	cout << maxValue;
//}

// 이진 탐색으로 풀기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> b;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		b.push_back(temp);
	}

	sort(b.begin(), b.end(), greater<>());

	int start = 0;
	int end = b[0];
	int result = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int ttlLong = 0;

		for (int i : b)
		{
			if (i > mid)
				ttlLong += (i - mid);
		}

		if (ttlLong < m)
			end = mid - 1;
		else
		{
			result = mid;
			start = mid + 1;
		}
	}

	cout << result;
}