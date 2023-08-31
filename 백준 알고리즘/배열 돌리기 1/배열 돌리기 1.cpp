// 배열 돌리기 1 : https://www.acmicpc.net/problem/16926

#include <iostream>
#include <vector>
using namespace std;

int n, m, r;

void RotateLeft(vector<vector<int>>& b, int count)
{
	vector<vector<int>> newBoard(n);
	for (int i = 0; i < n; i++)
		newBoard[i].resize(m);

	int vetricalCount = m;
	int horizontalCount = n;

	int originVetricalCount = m;
	int originHorizontalCount = n;

	string direction = "down";
	int i = 0; int j = 0;

	while (count !=  0)
	{
		if (direction == "down")
		{
			int temp = --horizontalCount;

			while (temp-- > 0)
			{
				newBoard[i + 1][j] = b[i][j];
				++i;
			}

			direction = "right";
		}
		if (direction == "right")
		{
			int temp = --vetricalCount;

			while (temp-- > 0)
			{
				newBoard[i][j + 1] = b[i][j];
				++j;
			}

			direction = "up";
		}
		if (direction == "up")
		{
			int temp = horizontalCount;

			while (temp-- > 0)
			{
				newBoard[i - 1][j] = b[i][j];
				--i;
			}

			direction = "left";
		}
		if (direction == "left")
		{
			int temp = vetricalCount;

			while (temp-- > 0)
			{
				newBoard[i][j - 1] = b[i][j];
				--j;
			}

			direction = "down";
			j += 1;
			i += 1;

			--horizontalCount;
			--vetricalCount;

			if (horizontalCount == 0 || vetricalCount == 0)
			{
				vetricalCount = originVetricalCount;
				horizontalCount = originHorizontalCount;
				i = 0; j = 0;
				--count;

				b = newBoard;
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> r;

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

	RotateLeft(board, r);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << board[i][j] <<' ';
		}
		cout << '\n';
	}
}