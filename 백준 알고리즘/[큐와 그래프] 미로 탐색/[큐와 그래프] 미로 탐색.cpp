// [큐와 그래프] 미로 탐색

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<int>> TTLcount;
vector<vector<bool>> isVisited;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs()
{
	int cx = 1;
	int cy = 1;
	queue<pair<int, int>> q;
	q.push({ cx, cy });
	TTLcount[cx][cy] = 1;
	isVisited[cx][cy] = true;

	while (!q.empty())
	{
		cx = q.front().first;
		cy = q.front().second;

		q.pop();

		if (cx == n && cy == m)
		{
			cout << TTLcount[cx][cy];
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
			if (board[nx][ny] == 0) continue;
			if (isVisited[nx][ny] == true) continue;

			isVisited[nx][ny] = true;
			q.push({ nx, ny });
			TTLcount[nx][ny] = TTLcount[cx][cy] + 1;
		}
	}
}

int main()
{
	cin >> n >> m;

	board.resize(n + 1, vector<int>(m + 1));
	TTLcount.resize(n + 1, vector<int>(m + 1));
	isVisited.resize(n + 1, vector<bool>(m + 1, false));

	for (int i = 1; i <= n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++)
		{
			board[i][j + 1] = temp[j] - '0';
		}
	}

	bfs();
}