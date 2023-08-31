// 배열 돌리기 3 : https://www.acmicpc.net/problem/16935

#include <iostream>
#include <vector>
using namespace std;

int n, m, r;

void MovePos(vector<vector<int>>& b, string direction)
{
	vector<vector<int>> newBoard(n);
	for (int i = 0; i < n; i++)
	{
		newBoard[i].resize(m);
	}

	if (direction == "right")
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i < n / 2 && j < m / 2 )
				{
					newBoard[i][j + m / 2] = b[i][j];
				}
				else if (i < n / 2 && j >= m / 2)
				{
					newBoard[i + n / 2][j] = b[i][j];
				}
				else if (i >= n / 2 && j >= m / 2)
				{
					newBoard[i][j - m / 2] = b[i][j];
				}
				else if (i >= n / 2 && j < m / 2)
				{
					newBoard[i - n/2][j] = b[i][j];
				}
			}
		}
	}
	else if (direction == "left")
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i < n / 2 && j < m / 2)
				{
					newBoard[i + n / 2][j] = b[i][j];
				}
				else if (i >= n / 2 && j < m / 2) // 왼쪽 아래
				{
					newBoard[i][j + m/2] = b[i][j];
				}
				else if (i >= n / 2 && j >= m / 2) // 오른쪽 아래
				{
					newBoard[i - n/2][j] = b[i][j];
				}
				else if (i < n / 2 && j >= m / 2) // 오른쪽 위
				{
					newBoard[i][j - m/2] = b[i][j];
				}
			}
		}
	}

	b = newBoard;
}

void Rotation(vector<vector<int>>& b, string direction)
{
	vector <vector<int>> newBoard(m);
	for (int i = 0; i < m; i++)
	{
		newBoard[i].resize(n);
	}

	if (direction == "right")
	{
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < m; j++)
			{
				newBoard[j][n - i - 1] = b[i][j];
			}
		}
	}
	else if (direction == "left")
	{
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < m; j++) 
			{
				newBoard[m - j - 1][i] = b[i][j];
			}
		}
	}

	int temp = m;
	m = n;
	n = temp;

	b = newBoard;
}

void SwitchArray(vector<vector<int>>& b, string direction)
{
	if (direction == "horizontal")
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j * 2 < n; j++)
			{
				swap(b[j][i], b[n - j - 1][i]);
			}
		}
	}
	else if (direction == "vertical")
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j * 2 < m; j++)
			{
				swap(b[i][j], b[i][m - j - 1]);
			}
		}
	}
}

int main()
{
	cin >> n >> m >> r;

	vector<vector<int>> board;

	board.resize(n);

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

	int calNum;
	for (int i = 0; i < r; i++)
	{
		cin >> calNum;

		switch (calNum)
		{
		case 1:
		{
			SwitchArray(board, "horizontal");
			break;
		}
		case 2:
		{
			SwitchArray(board, "vertical");
			break;
		}
		case 3:
		{
			Rotation(board, "right");
			break;
		}
		case 4:
		{
			Rotation(board, "left");
			break;
		}
		case 5:
			MovePos(board, "right");
			break;
		case 6:
			MovePos(board, "left");
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << board[i][j] << ' ';
		}

		cout << '\n';
	}
}