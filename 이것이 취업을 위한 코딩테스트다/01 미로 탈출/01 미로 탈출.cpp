// 01 미로 탈출

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
int moveCount = 1000000;
vector<vector<int>> b;
vector<vector<bool>> isVisited;

int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

void bfs(int cx, int cy, int tx, int ty, int count)
{
	// 범위를 초과하면 return
	if (cx <= 0 || cy <= 0 || cx > n || cy > m) return;

	// 이미 방문한 곳이면 return
	if (isVisited[cx][cy] == true) return;

	// 도착한 곳에 몬스터가 있으면 return;
	if (b[cx][cy] == 0) return;

	// 도착하면 가장 적게 도착한 count 세기
	if (cx == tx && cy == ty)
	{
		moveCount = min(moveCount, count);
		return;
	}

	isVisited[cx][cy] = true;

	// 상 하 좌 우
	for (int i = 0; i < 4; i++)
	{
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		bfs(nx, ny, tx, ty, ++count);
		--count;
	}
}

int main()
{
	cin >> n >> m;

	b.resize(n + 1, vector<int>(m + 1));
	isVisited.resize(n + 1, vector<bool>(m + 1, false));

	for (int i = 1; i <= n; i++)
	{
		string temp;
		cin >> temp;

		for (int k = 0; k < temp.size(); k++)
		{
			b[i][k + 1] = temp[k] - '0';
			if (b[i][k + 1] == 0)
			{
				isVisited[i][k + 1] = true;
			}
		}
	}

	isVisited[1][1] = false;

	int count = 1;

	int cx = 1;
	int cy = 1;
	int tx = n;
	int ty = m;


	bfs(cx, cy, tx, ty, count);

	cout << moveCount;
}