// 행렬 덧셈.cpp 

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board1;
vector<vector<int>> board2;

int main()
{
	int n, m;
	cin >> n >> m;

	board1.resize(n, vector<int>(m));
	board2.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;

			board1[i][j] = temp;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;

			board2[i][j] = temp;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << board1[i][j] + board2[i][j] << ' ';
		}
		cout << '\n';
	}
}