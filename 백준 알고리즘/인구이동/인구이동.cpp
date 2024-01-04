// 인구이동

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> newboard;
vector<vector<bool>> isVisited;
int n, l, r;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool move(int y, int x)
{
	queue<pair<int, int>> q;
	queue<pair<int, int>> dividedQ;

	q.push({ y, x });
	dividedQ.push({ y, x });
	isVisited[y][x] = true;
	int cnt = 1;
	int sum = board[y][x];

	bool isChanged = false;
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (isVisited[ny][nx]) continue;


			int curValue = abs(board[ny][nx] - board[cy][cx]);

			if (curValue < l || curValue > r) continue;
			isChanged = true;
			sum += board[ny][nx];
			++cnt;
			isVisited[ny][nx] = true;
			q.push({ ny, nx });
			dividedQ.push({ ny, nx });
		}
	}

	if (isChanged == true)
	{
		int dividedValue = sum / cnt;

		while (!dividedQ.empty())
		{
			int ny = dividedQ.front().first;
			int nx = dividedQ.front().second;

			newboard[ny][nx] = dividedValue;
			dividedQ.pop();
		}
		return true;
	}

	return false;
}

int main()
{
	cin >> n >> l >> r;
	
	board.resize(n, vector<int>(n));
	newboard.resize(n, vector<int>(n));
	isVisited.resize(n, vector<bool>(n, false));

	// 인구판을 만든다
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}

	int answer = 0;

	while (true)
	{
		bool isChanged = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!isVisited[i][j])
				{
					if (move(i, j))
					{
						isChanged = true;
					}
				}
			}
		}

		if (!isChanged) break;

		answer++;
 
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (newboard[i][j] != 0)
					board[i][j] = newboard[i][j];
				isVisited[i][j] = false;
			}
		}
	}

	cout << answer;
}