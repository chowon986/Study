// [복습] 테트로미노

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n);

	for (int i = 0; i < n; i++)
	{
		board[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i + 3 < n)
			{
				int temp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
				ans = max(ans, temp);
			}

			if (j + 3 < m)
			{
				int temp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
				ans = max(ans, temp);
			}

			if (i + 1 < n && j + 2 < m)
			{
				int temp = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2];
				ans = max(ans, temp);
			}

			if (i + 2 < n && j + 1 < m)
			{
				int temp = board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 2][j];
				ans = max(ans, temp);
			}

			if (i + 1 < n && j + 2 < m)
			{
				int temp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2];
				ans = max(ans, temp);
			}

			if (i + 2 < n && j - 1 >= 0)
			{
				int temp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j - 1];
				ans = max(ans, temp);
			}

			if (i - 1 >= 0 && j + 2 < m)
			{
				int temp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i - 1][j + 2];
				ans = max(ans, temp);
			}

			if (i + 2 < n && j + 1 < m)
			{
				int temp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1];
				ans = max(ans, temp);
			}

			if (i + 1 < n && j + 2 < m)
			{
				int temp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j];
				ans = max(ans, temp);
			}

			if (i + 2 < n && j + 1 < m)
			{
				int temp = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1];
				ans = max(ans, temp);
			}

			if (i + 1 < n && j + 1 < m)
			{
				int temp = board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1];
				ans = max(ans, temp);
			}

			if (i - 1 >= 0 && j + 2 < m)
			{
				int temp = board[i][j] + board[i][j + 1] + board[i - 1][j + 1] + board[i - 1][j + 2];
				ans = max(ans, temp);
			}

			if (i + 2 < n && j + 1 < m)
			{
				int temp = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1];
				ans = max(ans, temp);
			}

			if (i + 1 < n && j + 2 < m)
			{
				int temp = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2];
				ans = max(ans, temp);
			}

			if (i + 2 < n && j - 1 >= 0)
			{
				int temp = board[i][j] + board[i + 1][j] + board[i + 1][j - 1] + board[i + 2][j - 1];
				ans = max(ans, temp);
			}

			if (j + 2 < m)
			{
				int temp = board[i][j] + board[i][j + 1] + board[i][j + 2];
				if (i - 1 >= 0)
				{
					int temp2 = temp + board[i - 1][j + 1];
					if (ans < temp2) ans = temp2;
				}

				if (i + 1 < n)
				{
					int temp2 = temp + board[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
			}

			if (i + 2 < n)
			{
				int temp = board[i][j] + board[i + 1][j] + board[i + 2][j];
				if (j + 1 < m)
				{
					int temp2 = temp + board[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}

				if (j - 1 >= 0)
				{
					int temp2 = temp + board[i + 1][j - 1];
					if (ans < temp2) ans = temp2;
				}
			}
		}
	}

	cout << ans;
}