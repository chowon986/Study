// 카잉 달력.cpp : https://www.acmicpc.net/problem/6064

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int m;
//	int n;
//	int targetX;
//	int targetY;
//	int curX;
//	int curY;
//	int year;
//
//	int tc;
//	cin >> tc;
//
//	for (int i = 0; i < tc; i++)
//	{
//		cin >> m;
//		cin >> n;
//		cin >> targetX;
//		cin >> targetY;
//		curX = 1;
//		curY = 1;
//		year = 1;
//
//		if (curX == m && curY == n)
//		{
//			cout << year << '\n';
//			continue;
//		}
//
//		while (curX != targetX || curY != targetY)
//		{
//			if (curX == m && curY == n)
//			{
//				year = -1;
//				break;
//			}
//
//			++curX;
//			if (curX > m)
//				curX = 1;
//			++curY;
//			if (curY > n)
//				curY = 1;
//			++year;
//		}
//
//		cout << year << '\n';
//	}
//}

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		x -= 1;
		y -= 1;

		bool ok = false;
		for (int k = x; k < (m * n); k += m)
		{
			if (k % n == y)
			{
				cout << k + 1 << '\n';
				ok = true;
				break;
			}
		}

		if (!ok)
			cout << -1 << '\n';
	}
}