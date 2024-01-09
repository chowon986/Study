// 치킨 배달

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
vector<pair<int, int>> chickenPos;
vector<pair<int, int>> housePos;
int n, m;
int minSum = 1000000;

void check(int start, vector<int>& v)
{
	if (v.size() == m)
	{
		int sum = 0;
		for (auto i : housePos)
		{
			// 집마다 돌면서
			int minValue = 1000000;

			for (auto j : v)
			{
				// 가장 짧은 거리를 찾는다.
				int value = abs(chickenPos[j].first - i.first) + abs(chickenPos[j].second - i.second);
				minValue = min(value, minValue);
			}

			// 가장 짧은 거리를 더한다.
			sum += minValue;
		}

		minSum = min(minSum, sum);
	}

	for (int i = start + 1; i < chickenPos.size(); i++)
	{
		v.push_back(i);
		check(i, v);
		v.pop_back();
	}
}

int main()
{
	cin >> n >> m;

	board.resize(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 1)
				housePos.push_back({ i, j });
			else if (board[i][j] == 2)
				chickenPos.push_back({ i, j });
		}
	}

	vector<int> v;
	check(-1, v);

	cout << minSum;
}