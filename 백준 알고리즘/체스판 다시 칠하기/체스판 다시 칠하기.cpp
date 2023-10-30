// 체스판 다시 칠하기

#include <iostream>
#include <vector>
using namespace std;

int n, m;

int CheckBoard(vector<vector<bool>>& board, int startx, int starty)
{
	if (starty + 8 > n || startx + 8 > m) return -1;

	bool curBlock1 = true;
	bool curBlock2 = false;

	int count1 = 0;
	int count2 = 0;
	for (int i = starty; i < starty + 8; i++)
	{
		for (int j = startx; j < startx + 8; j++)
		{
			curBlock1 = !curBlock1;
			curBlock2 = !curBlock2;

			if (board[i][j] != curBlock1)
				++count1;
			if (board[i][j] != curBlock2)
				++count2;
		}
		curBlock1 = !curBlock1;
		curBlock2 = !curBlock2;
	}

	return count1 < count2 ? count1 : count2;
}

int main()
{
	cin >> n >> m;

	vector<vector<bool>> board(n, vector<bool>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char temp;
			cin >> temp;

			board[i][j] = temp == 'W' ? true : false;
		}
	}

	int minValue = 64;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp = CheckBoard(board, j, i);
			if (temp != -1)
				minValue = min(minValue, temp);
		}
	}

	cout << minValue;
}