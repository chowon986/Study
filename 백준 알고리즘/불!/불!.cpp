// 불!

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> board;
vector<vector<bool>> isVisited;
vector<vector<int>> visitedCount;
int n, m;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool isOnFire = false;

void check(int y, int x)
{
	queue<pair<int, int>> q;
	isVisited[y][x] = true;
	visitedCount[y][x] = 0;

	q.push({ y, x });

	// 불이 퍼진다.
	
	
	queue<pair<int, int>> fireQ;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'F')
				fireQ.push({ i, j });
		}
	}

	while (!q.empty())
	{
		if (!fireQ.empty())
		{
			int size = fireQ.size();

			for (int i = 0; i < size; i++)
			{
				int cfy = fireQ.front().first;
				int cfx = fireQ.front().second;

				fireQ.pop();

				for (int i = 0; i < 4; i++)
				{
					int ncfy = cfy + dy[i];
					int ncfx = cfx + dx[i];

					if (ncfy < 0 || ncfx < 0 || ncfy >= n || ncfx >= m) continue;
					if (board[ncfy][ncfx] == '#' || board[ncfy][ncfx] == 'F') continue;
					board[ncfy][ncfx] = 'F';
					fireQ.push({ ncfy, ncfx });
				}
			}
		}


		if (!q.empty())
		{
			int size = q.size();

			for (int i = 0; i < size; i++)
			{
				int cy = q.front().first;
				int cx = q.front().second;

				q.pop();

				for (int i = 0; i < 4; i++)
				{
					int ny = cy + dy[i];
					int nx = cx + dx[i];

					if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					{
						cout << visitedCount[cy][cx] + 1;
						return;
					}

					if (isVisited[ny][nx]) continue;
					if (board[ny][nx] == '#' || board[ny][nx] == 'F') continue;

					isVisited[ny][nx] = true;
					visitedCount[ny][nx] = visitedCount[cy][cx] + 1;
					board[ny][nx] = 'J';
					board[cy][cx] = '.';
					q.push({ ny, nx });
				}
			}
		}
	}

	cout << "IMPOSSIBLE";
}

int main()
{
	cin >> n >> m;

	board.resize(n, vector<char>(m));
	isVisited.resize(n, vector<bool>(m, false));
	visitedCount.resize(n, vector<int>(m, 0));

	int cy = 0;
	int cx = 0;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < m; j++)
		{
			board[i][j] = temp[j];
			if (board[i][j] == 'J')
			{
				cy = i;
				cx = j;
			}
		}
	}

	check(cy, cx);
}