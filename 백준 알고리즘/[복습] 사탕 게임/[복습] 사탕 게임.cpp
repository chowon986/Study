// [복습] 사탕 게임

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<char>> board;
int n;

int CheckBoard()
{
	char temp;
	int count = 0;
	int MaxCount = 0;
	for (int i = 0; i < n; i++)
	{
		temp = board[i][0];
		count = 0;
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == temp) ++count;
			else
			{
				MaxCount = max(count, MaxCount);
				count = 1;
				temp = board[i][j];
			}
		}

		MaxCount = max(count, MaxCount);
	}

	for (int i = 0; i < n; i++)
	{
		temp = board[0][i];
		count = 0;
		for (int j = 0; j < n; j++)
		{
			if (board[j][i] == temp) ++count;
			else
			{
				MaxCount = max(count, MaxCount);
				count = 1;
				temp = board[j][i];
			}
		}

		MaxCount = max(count, MaxCount);
	}

	return MaxCount;
}

int SwapRight(int x, int y)
{
	if (y >= n - 1) return 0;
	swap(board[x][y], board[x][y + 1]);
	int temp = CheckBoard();
	swap(board[x][y], board[x][y + 1]);

	return temp;
}

int SwapDown(int x, int y)
{
	if (x >= n - 1) return 0;
	swap(board[x][y], board[x + 1][y]);
	int temp = CheckBoard();
	swap(board[x][y], board[x + 1][y]);

	return temp;
}

int main()
{
	cin >> n;

	board.resize(n, vector<char>(n));

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++)
		{
			board[i][j] = temp[j];
		}
	}

	int maxCount = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			maxCount = max(maxCount, SwapRight(i, j));
			maxCount = max(maxCount, SwapDown(i, j));
		}
	}

	cout << maxCount;
}