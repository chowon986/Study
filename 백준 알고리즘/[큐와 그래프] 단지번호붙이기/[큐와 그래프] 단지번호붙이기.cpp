// [큐와 그래프] 단지번호붙이기

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<vector<int>> board;
vector<vector<bool>> isVisited;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int n;
int TTLcount;
void bfs(int cx, int cy)
{
	queue<pair<int, int>> q;
	q.push({ cx,cy });
	isVisited[cx][cy] = true;

	while (!q.empty())
	{
		cx = q.front().first;
		cy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (board[nx][ny] == 0) continue;
			if (isVisited[nx][ny] == true) continue;
			isVisited[nx][ny] = true;
			q.push({ nx, ny });
			++TTLcount;
		}
	}
}

int main()
{
	cin >> n;

	board.resize(n, vector<int>(n));
	isVisited.resize(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < temp.size(); j++)
		{
			board[i][j] = temp[j] - '0';
		}
	}

	vector<int> ans;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 1 && isVisited[i][j] == false)
			{
				TTLcount = 1;
				bfs(i, j);

				ans.push_back(TTLcount);
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';

	for (int i : ans)
	{
		cout << i << '\n';
	}
}