// 최댓값.cpp 
#include <iostream>
#include <vector>
using namespace std;

#define MAX 9

vector<vector<int>> board(MAX, vector<int>(MAX));

int main()
{
	int maxValue = -1;
	int row = -1;
	int col = -1;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			int temp;
			cin >> temp;
			board[i][j] = temp;

			if (temp > maxValue)
			{
				maxValue = temp;
				row = i + 1;
				col = j + 1;
			}
		}
	}

	cout << maxValue << '\n';
	cout << row << ' ' << col;
}