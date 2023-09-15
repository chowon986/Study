// [복습] 토마토

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<vector<int>> board;
vector<vector<bool>> isVisited;
vector<vector<int>> TTLCount;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main()
{
	int n, m;
	cin >> m >> n;
	board.resize(n, vector<int>(m));
	TTLCount.resize(n, vector<int>(m));
	isVisited.resize(n, vector<bool>(m));
	deque<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			board[i][j] = temp;

			if(temp == 1)
			{
				q.push_back({ i, j });
				isVisited[i][j] = true;
			}
		}
	}

	bool isAlreadyDone = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
			{
				isAlreadyDone = false;
				break;
			}
		}
	}

	if (isAlreadyDone)
	{
		cout << 0;
		return 0;
	}

	int cx, cy;

	while (!q.empty())
	{
		cx = q.front().first;
		cy = q.front().second;

		q.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (isVisited[nx][ny]) continue;
			if (board[nx][ny] != 0) continue;

			board[nx][ny] = 1;
			isVisited[nx][ny] = true;
			TTLCount[nx][ny] = TTLCount[cx][cy] + 1;
			q.push_back({ nx, ny });
		}
	}

	int maxValue = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
			{
				cout << -1;
				return 0;
			}

			maxValue = max(maxValue, TTLCount[i][j]);
		}
	}

	cout << maxValue;
}