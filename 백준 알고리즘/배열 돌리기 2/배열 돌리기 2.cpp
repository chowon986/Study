// 배열 돌리기 2 : https://www.acmicpc.net/problem/16927

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<vector<int>> boards;

	int n, m, r;
	cin >> n >> m >> r;

	vector<vector<int>> originboard;
	originboard.resize(n);

	for (int i = 0; i < n; i++)
	{
		originboard[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			originboard[i][j] = temp;
		}
	}

	// 그룹을 지어 1차원 배열에 넣는다.
	for (int i = 0; i < n ; i++)
	{
		vector<int> board;

		for (int k = i; k < m - i - 1; k++)
			board.push_back(originboard[i][k]);

		for (int k = i; k < n - 1 - i; k++)
			board.push_back(originboard[k][m - i - 1]);

		for (int k = m - 1 - i; k > i; k--)
			board.push_back(originboard[n - i - 1][k]);

		for (int k = n - 1 - i; k > i; k--)
			board.push_back(originboard[k][i]);

		boards.push_back(board);
	}

	// 그룹별로 회전 시킨다.
	for (int i = 0; i < boards.size(); i++)
	{
		if(boards[i].size() == 0) continue;

		int moveCount = r % boards[i].size();
		if (moveCount == 0)
			continue;

		vector<int> newboard(boards[i].size());

		for (int j = 0; j < boards[i].size(); j++)
		{
			if (j + moveCount >= boards[i].size())
			{
				int tempIdx = (j + moveCount) % boards[i].size();
				newboard[j] = boards[i][tempIdx];
			}
			else
			{
				newboard[j] = boards[i][j + moveCount];
			}
		}

		boards[i] = newboard;
	}

	for (int i = 0; i < n; i++)
	{
		int idx = 0;
		for (int k = i; k < m - i - 1; k++)
			originboard[i][k] = boards[i][idx++];

		for (int k = i; k < n - 1 - i; k++)
			originboard[k][m - i - 1] = boards[i][idx++];

		for (int k = m - 1 - i; k > i; k--)
			originboard[n - i - 1][k] = boards[i][idx++];

		for (int k = n - 1 - i; k > i; k--)
			originboard[k][i] = boards[i][idx++];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << originboard[i][j] << ' ';
		}

		cout << '\n';
	}
}