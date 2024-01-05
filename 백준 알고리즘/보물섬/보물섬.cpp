// 치킨 배달

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<vector<char>> board;
vector<vector<bool>> isVisited;
vector<vector<int>> visitedCount;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m;
int maxValue;

void check(int y, int x)
{
	queue<pair<int, int>> q;
	isVisited[y][x] = true;
	visitedCount[y][x] = 0;
	q.push({ y, x });

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];


			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (board[ny][nx] == 'W') continue;
			if (isVisited[ny][nx] == true) continue;

			q.push({ ny, nx });
			isVisited[ny][nx] = true;
			visitedCount[ny][nx] = visitedCount[cy][cx] + 1;
			maxValue = max(maxValue, visitedCount[ny][nx]);
		}
	}

	fill(isVisited.begin(), isVisited.end(), vector<bool>(m, false));
}

int main()
{
	cin >> n >> m;

	board.resize(n, vector<char>(m));
	isVisited.resize(n, vector<bool>(m, false));
	visitedCount.resize(n, vector<int>(m, false));

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < m; j++)
		{
			board[i][j] = temp[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'W') continue;
			check(i, j);
		}
	}

	cout << maxValue;
}