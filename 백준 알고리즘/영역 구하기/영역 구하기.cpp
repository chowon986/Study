// 영역 구하기.cpp

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int n, m, k;
vector<vector<bool>> v;
int zoneCount;
vector<int> allCount;

void bfs(int x, int y)
{
	stack<pair<int, int>> q;
	q.push({ x, y });
	v[x][y] = true;
	zoneCount = 1;

	while (!q.empty())
	{
		int cx = q.top().first;
		int cy = q.top().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (v[nx][ny] == true) continue;

			v[nx][ny] = true;
			q.push({ nx, ny });
			++zoneCount;
		}
	}

}

int main()
{
	cin >> n >> m >> k;

	v.resize(n, vector<bool>(m, false));

	for (int i = 0; i < k; i++)
	{
		int sx, sy, ex, ey;
		cin >> sy >> sx >> ey >> ex;

		for (int j = sx; j < ex; j++)
		{
			for (int k = sy; k < ey; k++)
			{
				v[j][k] = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			zoneCount = 0;
			if (v[i][j] == false)
			{
				bfs(i, j);
				allCount.push_back(zoneCount);
			}
		}
	}

	sort(allCount.begin(), allCount.end());
	cout << allCount.size() << '\n';

	for (int i : allCount)
	{
		cout << i << ' ';
	}
}