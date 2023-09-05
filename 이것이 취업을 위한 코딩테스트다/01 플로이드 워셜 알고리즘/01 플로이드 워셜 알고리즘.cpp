// 01 플로이드 워셜 알고리즘

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;

int main()
{
	int n, m;
	cin >> n >> m;

	board.resize(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
				board[i][j] = 1e9;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		board[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int a = 1; a <= n; a++)
		{
			for (int b = 1; b <= n; b++)
			{
				board[a][b] = min(board[a][b], board[a][k] + board[k][b]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == 1e9)
				cout << "INFINITY" << ' ';
			else
				cout << board[i][j] << ' ';
		}

		cout << '\n';
	}
}