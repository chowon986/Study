// [BFS] 알고스팟

// 벽을 부수는 최소 개수
// 방 -> 방 0
// 방 -> 벽 1
// 벽 -> 방 0
// 벽 -> 벽 1
// 방인 곳을 다 이동하고
// 벽을 하나 부수고 이동할 수 있는 곳을 다 이동하고
// 벽을 두개 부수고 이동할 수 있는 곳을 다 이동하고
// 이렇게 진행

#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<vector<int>> board;
vector<vector<int>> TTLcount;
vector<vector<bool>> isVisited;


int main()
{
	int n, m;
	cin >> n >> m;
	board.resize(m + 1, vector<int>(n + 1));
	TTLcount.resize(m + 1, vector<int>(n + 1));
	isVisited.resize(m + 1, vector<bool>(n + 1));

	// 판 초기화
	for (int i = 1; i <= m; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < temp.size(); j++)
		{
			board[i][j + 1] = temp[j] - '0';
		}
	}
	
	deque<pair<int, int>> q;
	int cx = 1;
	int cy = 1;
	q.push_back({ cx, cy });
	isVisited[cx][cy] = true;

	int ans = 10001;

	while (!q.empty())
	{
		cx = q.front().first;
		cy = q.front().second;

		if (cx == m && cy == n)
		{
			ans = min(ans, TTLcount[m][n]);
		}

		q.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx <= 0 || ny <= 0 || nx > m || ny > n) continue;
			if (isVisited[nx][ny]) continue;

			isVisited[nx][ny] = true;

			// 방인 곳을 먼저 방문할 수 있도록 deque의 앞부분에 push
			if (board[nx][ny] == 0)
			{
				TTLcount[nx][ny] = TTLcount[cx][cy];
				q.push_front({ nx, ny });
			}
			else // 벽을 뚫고 방문할 수 있도록 deque의 뒷부분에 push
			{
				TTLcount[nx][ny] = TTLcount[cx][cy] + 1;
				q.push_back({ nx, ny });
			}
		}
	}

	cout << ans;
}