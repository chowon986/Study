// [큐와 그래프] 나이트의 이동

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[8] = { -2, -2, -1, -1, 2, 2, 1, 1 };
int dx[8] = { -1, 1, -2, 2, -1, 1, -2, 2 };

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;

		vector<vector<int>> board(m, vector<int>(m));
		queue<pair<int, int>> q;
		vector<vector<int>> count(m, vector<int>(m));
		vector<vector<bool>> isVisited(m, vector<bool>(m, false));
		int cx, cy, tx, ty;
		cin >> cx >> cy >> tx >> ty;

		q.push({ cx, cy });
		count[cx][cy] = 0;
		isVisited[cx][cy] = true;

		while (!q.empty())
		{
			cx = q.front().first;
			cy = q.front().second;

			if (cx == tx && cy == ty)
			{
				cout << count[tx][ty] << '\n';
				break;
			}

			q.pop();

			for (int i = 0; i < 8; i++)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (nx < 0 || ny < 0 || nx >= m || ny >= m) continue;
				if (isVisited[nx][ny] == true) continue;

				isVisited[nx][ny] = true;
				count[nx][ny] = count[cx][cy] + 1;
				q.push({ nx, ny });
			}
		}
	}
}