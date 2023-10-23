// 색종이.cpp 

#include <iostream>
#include <vector>
using namespace std;

#define MAX 100

vector<vector<bool>> board(MAX + 1, vector<bool>(MAX + 1, false));

int main()
{
	int n;
	cin >> n;
	int pageSize = 10;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		for (int j = a; j < a + pageSize; j++)
		{
			for (int k = b; k < b + pageSize; k++)
			{
				board[j][k] = true;
			}
		}
	}

	int count = 0;
	for (int i = 0; i <= MAX; i++)
	{
		for (int j = 0; j <= MAX; j++)
		{
			if (board[i][j])
				++count;
		}
	}

	cout << count;
}