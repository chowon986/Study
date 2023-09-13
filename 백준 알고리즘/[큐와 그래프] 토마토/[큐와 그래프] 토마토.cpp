// [큐와 그래프] 토마토

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(m, vector<int>(n));
	vector<vector<int>> count(m, vector<int>(n));
	vector<vector<bool>> isVisited(m, vector<bool>(n, false));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			board[i][j] = temp;

			if (temp == 1)
			{
				q.push({ i, j });
			}
		}
	}

	int cx, cy;

	while (!q.empty())
	{
		cx = q.front().first;
		cy = q.front().second;

		q.pop();
		isVisited[cx][cy] = true;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (isVisited[nx][ny] == true) continue;
			if (board[nx][ny] == 1 || board[nx][ny] == -1) continue;

			isVisited[nx][ny] = true;
			board[nx][ny] = 1;
			count[nx][ny] = count[cx][cy] + 1;
			q.push({ nx, ny });
		}
	}

	int maxValue = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 0)
			{
				cout << -1;
				return 0;
			}

			maxValue = max(maxValue, count[i][j]);
		}
	}

	cout << maxValue;
}