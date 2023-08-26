// 복습_브루트포스

// NM과 K (1)

// NM과 K (1) : https://www.acmicpc.net/problem/18290
//#include <iostream>
//using namespace std;
//
//int a[10][10];
//bool c[10][10];
//int n, m, k;
//int ans = -2147483647;
//int dx[] = { 0, 0, 1, -1 };
//int dy[] = { 1, -1, 0, 0 };
//
//void go(int cnt, int sum)
//{
//	if (cnt == k)
//	{
//		if (ans < sum) ans = sum;
//		return;
//	}
//	
//	for (int x = 0; x < n; x++)
//	{
//		for (int y = 0; y < m; y++)
//		{
//			if (c[x][y]) continue;
//			bool ok = true;
//			for (int i = 0; i < 4; i++)
//			{
//				int nx = x + dx[i];
//				int ny = y + dy[i];
//				if (0 <= nx && nx < n && 0 <= ny && ny < m)
//				{
//					// 격자판 범위 안에 있고,
//					if (c[nx][ny]) // 선택한 적이 있다면 선택할 수 없음
//						ok = false;
//				}
//			}
//
//			if (ok)
//			{
//				c[x][y] = true;
//				go(cnt + 1, sum + a[x][y]);
//				c[x][y] = false;
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m >> k;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			int temp;
//			cin >> temp;
//
//			a[i][j] = temp;
//		}
//	}
//
//	go(0, 0);
//
//	cout << ans;
//}


// 리모컨 : https://www.acmicpc.net/problem/1107

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int target, count;
	cin >> target >> count;

	bool brokenNumbers[10] = { false, };

	for (int i = 0; i < count; i++)
	{
		int temp;
		cin >> temp;
		brokenNumbers[temp] = true;
	}

	int curChannel = 100;
	int moveCount = curChannel > target ? curChannel - target : target - curChannel;

	int ChannelA = target;
	int copyChannel = ChannelA;

	while (copyChannel > 0)
	{
		if (brokenNumbers[copyChannel % 10])
		{
			// 고장난 채널이면
			--ChannelA;
			copyChannel = ChannelA;
		}
		else
		{
			copyChannel /= 10;
		}
	}


	if (ChannelA == 0)
	{
		if (brokenNumbers[0]) ChannelA = -1000000;
		else ChannelA = 0;
	}

	int tempNum = to_string(ChannelA).size();
	tempNum += target - ChannelA;

	moveCount = min(tempNum, moveCount);

	int ChannelB = target;
	copyChannel = ChannelB;

	while (copyChannel >= 0 && copyChannel < 1000000)
	{
		if (brokenNumbers[copyChannel % 10])
		{
			// 고장난 채널이면
			++ChannelB;
			copyChannel = ChannelB;
		}
		else
		{
			copyChannel /= 10;
			if (copyChannel == 0)
				break;
		}
	}

	tempNum = to_string(ChannelB).size();
	tempNum += ChannelB - target;

	moveCount = min(tempNum, moveCount);

	cout << moveCount;
}

// N과 M (1) : https://www.acmicpc.net/problem/15649

// N과 M (7) : https://www.acmicpc.net/problem/15656

// 일곱 난쟁이 : https://www.acmicpc.net/problem/2309

// 사탕 게임 : https://www.acmicpc.net/problem/3085

// 날짜 계산 : https://www.acmicpc.net/problem/1476

// 테트로미노 : https://www.acmicpc.net/problem/14500

// 카잉 달력 : https://www.acmicpc.net/problem/6064

// 수 이어 쓰기1 : https://www.acmicpc.net/problem/1748
