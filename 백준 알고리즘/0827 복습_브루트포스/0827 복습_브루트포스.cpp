// 복습_브루트포스

// NM과 K (1) : https://www.acmicpc.net/problem/18290
#include <iostream>
using namespace std;

int a[10][10];
bool c[10][10];
int n, m, k;
int ans = -2147483647;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void go(int cnt, int sum)
{
	if (cnt == k)
	{
		if (ans < sum) ans = sum;
		return;
	}
	
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (c[x][y]) continue;
			bool ok = true;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m)
				{
					// 격자판 범위 안에 있고,
					if (c[nx][ny]) // 선택한 적이 있다면 선택할 수 없음
						ok = false;
				}
			}

			if (ok)
			{
				c[x][y] = true;
				go(cnt + 1, sum + a[x][y]);
				c[x][y] = false;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;

			a[i][j] = temp;
		}
	}

	go(0, 0);

	cout << ans;
}


// 리모컨 : https://www.acmicpc.net/problem/1107

// N과 M (1) : https://www.acmicpc.net/problem/15649

// N과 M (7) : https://www.acmicpc.net/problem/15656

// 일곱 난쟁이 : https://www.acmicpc.net/problem/2309

// 사탕 게임 : https://www.acmicpc.net/problem/3085

// 날짜 계산 : https://www.acmicpc.net/problem/1476

// 테트로미노 : https://www.acmicpc.net/problem/14500

// 카잉 달력 : https://www.acmicpc.net/problem/6064

// 수 이어 쓰기1 : https://www.acmicpc.net/problem/1748
