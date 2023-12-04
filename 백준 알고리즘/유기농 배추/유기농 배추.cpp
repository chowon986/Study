// 유기농 배추

#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<vector<int>> board(51, vector<int>(51, 0));

int dx[4] = { 0,0,-1,1};
int dy[4] = { -1,1,0,0};

void dfs(int x, int y)
{
	board[x][y] = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (board[nx][ny] == 0) continue;

		board[nx][ny] = 0;
		dfs(nx, ny);
	}
}

int main()
{
	int cnt;
	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		cin >> m >> n >> k;
		int sum = 0;

		for (int j = 0; j < k; j++)
		{
			int a, b;
			cin >> a >> b;
			board[b][a] = 1;
		}

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (board[j][k] == 1)
				{
					dfs(j, k);
					++sum;
				}
			}
		}

		cout << sum;
	}
}