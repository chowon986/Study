// 미로 탐색

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> board;
vector<vector<bool>> isVisited;
vector<vector<int>> visitedCount;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;

	q.push({ x, y });
	visitedCount[x][y] = 1;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx > n || ny > m || nx < 1 || ny < 1) continue;
			if (board[nx][ny] == 0) continue;
			if (isVisited[nx][ny] == true) continue;

			isVisited[nx][ny] = true;
			q.push({ nx, ny });
			visitedCount[nx][ny] = visitedCount[cx][cy] + 1;
		}
	}
}

int main()
{
	cin >> n >> m;
	board.resize(n + 1, vector<int>(m + 1));
	visitedCount.resize(n + 1, vector<int>(m + 1));
	isVisited.resize(n + 1, vector<bool>(m + 1, false));

	for (int i = 1; i <= n; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 1; j <= m; j++)
		{
			board[i][j] = temp[j - 1] - '0';
			if (temp[j - 1] - '0' == 0)
				isVisited[i][j] = true;
		}
	}

	bfs(1, 1);
	cout << visitedCount[n][m];
}