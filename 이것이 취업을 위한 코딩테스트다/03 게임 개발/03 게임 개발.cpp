// 03 게임 개발

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> b;

// 북 동 남 서 순
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

bool check(int x, int y)
{
	// 이동할 위치가 바다거나 땅이 없는 경우
	if (b[x][y] == 1 || x < 0 || y < 0 || x > m || y > n) return false;

	return true;
}

int main()
{
	cin >> n >> m;

	b.resize(n);

	// dir은 0 북, 1 동, 2 남, 3 서
	int cx, cy, dir;
	cin >> cx >> cy >> dir;

	for (int i = 0; i < n; i++)
	{
		b[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			b[i][j] = temp;
		}
	}


	// 시작 위치 방문 처리
	b[cx][cy] = 1;
	int count = 1;

	while (true)
	{
		// 현재 방향을 기준으로 왼쪽 방향 확인
		int nDir = (dir + 3) % 4;

		// 왼쪽 방향에 가보지 않은 칸이 존재하면 한 칸 이동
		int nx = cx + dx[nDir];
		int ny = cy + dy[nDir];
		if (check(nx, ny))
		{
			cx = nx;
			cy = ny;
			// 간 곳임을 표시
			b[nx][ny] = 1;
			dir = nDir;
			++count;
		}
		else
		{
			bool canMove = false;
			for (int i = 0; i < 4; i++)
			{
				nx = cx + dx[i];
				ny = cy + dy[i];
				if (check(nx, ny))
				{
					canMove = true;
					break;
				}
			}

			// 네 방향 모두 이미 가본 칸이거나 바다로 되어있는 경우
			// dir을 바꾸지 않고, 한 칸 뒤로 가고 1단계로 돌아간다.
			if (!canMove)
			{
				int tempDir = (dir + 2) % 4;
				nx = cx + dx[tempDir];
				ny = cy + dy[tempDir];

				// 만약 뒤가 바다면 움직임을 멈춘다.
				if (b[nx][ny] == 1)
				{
					cout << count;
					return 0;
				}
				else
				{
					cx = nx;
					cy = ny;
				}
			}
			else
				dir = nDir;
		}
	}
}