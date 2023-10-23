// 행렬 덧셈.cpp 

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;

int main()
{
	int n, m;
	cin >> n >> m;

	board.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;

			board[i][j] = temp;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;

			board[i][j] += temp;
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