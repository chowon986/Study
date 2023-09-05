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
using namespace std;

int main()
{

}