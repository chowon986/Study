// 미로 탐색_.cpp

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
int n, m;
vector<vector<bool>> isVisited;
vector<vector<int>> visitCount;
vector<vector<int>> v;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });

	visitCount[x][y] = 1;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (isVisited[nx][ny] == true) continue;
			if (v[nx][ny] == 0) continue;

			visitCount[nx][ny] = visitCount[cx][cy] + 1;
			isVisited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
}

int main()
{
	cin >> n >> m;

	v.resize(n, vector<int>(m));
	visitCount.resize(n, vector<int>(m, 0));
	isVisited.resize(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < m; j++)
			v[i][j] = temp[j] - '0';

		int a = 0;
	}

	bfs(0, 0);
	cout << visitCount[n - 1][m - 1];
}