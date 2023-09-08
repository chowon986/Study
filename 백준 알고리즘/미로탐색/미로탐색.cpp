// 미로탐색

#include <iostream>
#include <string>
#include <queue>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> visitCount;
vector<vector<bool>> isVisited;

int n, m;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0, -1,1 };

void bfs()
{
	queue<pair<int,int>> q;
	int cx = 1;
	int cy = 1;

	q.push({ cx, cy });
	isVisited[cx][cy] = true;
	visitCount[cx][cy] = 1;

	while (!q.empty())
	{
		cx = q.front().first;
		cy = q.front().second;

		q.pop();

		if (cx == n && cy == m)
		{
			cout << visitCount[cx][cy];
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
			if (isVisited[nx][ny]) continue;
			if (board[nx][ny] == 0) continue;

			q.push({ nx, ny });
			isVisited[nx][ny] = true;
			visitCount[nx][ny] = visitCount[cx][cy] + 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	board.resize(n + 1, vector<int>(m + 1));
	visitCount.resize(n + 1, vector<int>(m + 1));
	isVisited.resize(n + 1, vector<bool>(m + 1, false));

	for (int i = 1; i <= n; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < temp.size(); j++)
			board[i][j + 1] = temp[j] - '0';
	}

	bfs();
}