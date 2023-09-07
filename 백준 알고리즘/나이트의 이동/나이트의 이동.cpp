// 나이트의 이동

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a, b, c, d, e;

int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };



void bfs(int cx, int cy, int size)
{
	vector<vector<int>> board(size, vector<int>(size));
	vector<vector<bool>> isVisited(size, vector<bool>(size));
	vector<vector<int>> countArray(size, vector<int>(size));

	queue<pair<int, int>> q;

	q.push({ cx, cy });
	isVisited[cx][cy] = true;
	countArray[cx][cy] = 0;

	while (!q.empty())
	{
		cx = q.front().first;
		cy = q.front().second;

		if (cx == d && cy == e)
		{
			cout << countArray[cx][cy] << '\n';
			return;
		}

		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= size || ny >= size) continue;

			if (isVisited[nx][ny]) continue;

			isVisited[nx][ny] = true;
			countArray[nx][ny] = countArray[cx][cy] + 1;
			q.push({ nx, ny });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c >> d >> e;

		int cx = b;
		int cy = c;

		bfs(cx, cy, a);
	}
}