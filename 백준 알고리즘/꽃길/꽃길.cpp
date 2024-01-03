// 꽃길

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
vector<vector<bool>> isVisited;
int minValue = 1000000;
int sum = 0;
int n;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool check(int cx, int cy)
{
	if (isVisited[cx][cy]) return false;

	for (int i = 0; i < 4; i++)
	{
		int nx = cx + dx[i];
		int ny = cy + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) return false;
		if (isVisited[nx][ny]) return false;
	}

	return true;
}

int setFlower(int cx, int cy)
{
	isVisited[cx][cy] = true;
	int s = board[cx][cy];

	for (int i = 0; i < 4; i++)
	{
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		isVisited[nx][ny] = true;
		s += board[nx][ny];
	}

	return s;
}

void eraseFlower(int cx, int cy)
{
	isVisited[cx][cy] = false;

	for (int i = 0; i < 4; i++)
	{
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		isVisited[nx][ny] = false;
	}
}

void flower(int cnt, int sum)
{
	if (cnt == 3)
	{
		minValue = min(minValue, sum);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check(i, j))
			{
				flower(cnt + 1, sum + setFlower(i, j));
				eraseFlower(i, j);
			}
		}
	}
}


int main()
{
	cin >> n;

	board.resize(n, vector<int>(n));
	isVisited.resize(n, vector<bool>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}

	flower(0, 0);

	cout << minValue;
}