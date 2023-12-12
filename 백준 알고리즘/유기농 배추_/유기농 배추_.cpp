// 유기농 배추

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void bfs(int x, int y, vector<vector<bool>>& v)
{
	queue<pair<int, int>> q;
	q.push({ x, y });

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
			if (v[nx][ny] == 0) continue;
			v[nx][ny] = 0;
			q.push({ nx, ny });
		}
	}
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n >> m >> k;
		int count = 0;
		vector<vector<bool>> v;
		v.resize(n, vector<bool>(m, 0));

		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			v[x][y] = 1;
		}

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (v[j][k] == 1)
				{
					bfs(j, k, v);
					++count;
				}
			}
		}

		cout << count << '\n';
	}

}