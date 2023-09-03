// 02 숫자 카드 게임

// 내 풀이

//#include <iostream>
//
//using namespace std;
//
//int a[101][101];
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	int ans = -1;
//	for (int i = 0; i < n; i++)
//	{
//		int minValue = 10001;
//		for (int j = 0; j < m; j++)
//		{
//			int temp;
//			cin >> temp;
//
//			a[i][j] = temp;
//
//			minValue = min(temp, minValue);
//		}
//
//		if (ans < minValue)
//			ans = minValue;
//	}
//
//	cout << ans;
//}

// 책 풀이

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int a[101][101];

int main()
{
	int n, m;
	cin >> n >> m;

	int minValue;
	int result = -1;

	for (int i = 0; i < n; i++)
	{
		list<int> data;
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;

			data.push_back(temp);
		}

		minValue = *min_element(data.begin(), data.end());
		result = max(result, minValue);
	}

	cout << result;
}