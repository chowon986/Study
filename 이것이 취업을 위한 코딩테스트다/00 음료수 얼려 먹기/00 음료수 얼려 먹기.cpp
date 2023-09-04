// 00 음료수 얼려 먹기

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<vector<int>> b;
vector<vector<bool>> isVisited;
int sum = 0;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int cx, int cy, int count)
{
	// 칸을 초과하면 return
	if (cx <= 0 || cy <= 0 || cx > n || cy > m) return;

	// 칸막이면 return
	if (b[cx][cy] == 1) return; 

	// 이미 방문한 칸이면 return
	if (isVisited[cx][cy] == true) return;

	isVisited[cx][cy] = true;
	b[cx][cy] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = cx + dx[i];
		int ny = cy + dy[i];

		bfs(nx, ny, ++count);
	}

	if (count != 0)
		sum = 1;
}

int main()
{
	cin >> n >> m;

	b.resize(n + 1, vector<int>(m + 1));
	isVisited.resize(n + 1, vector<bool>(m + 1));

	for (int i = 1; i <= n; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < temp.size(); j++)
		{
			b[i][j + 1] = temp[j] - '0';
			if (b[i][j + 1] == 1)
				isVisited[i][j + 1] = true;
		}
	}

	int cx = 1;
	int cy = 1;
	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum = 0;
			bfs(i, j, 0);
			ans += sum;
		}
	}

	cout << ans;
}