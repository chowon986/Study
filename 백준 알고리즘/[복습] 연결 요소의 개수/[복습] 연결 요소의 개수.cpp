// [복습] 연결 요소의 개수

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> board;
vector<bool> isVisited;

void DFS(int x)
{
	for (int i = 1; i <= n; i++)
	{
		if (board[x][i] == 1 && isVisited[i] == false)
		{
			isVisited[i] = true;
			DFS(i);
		}
	}
 }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	board.resize(n + 1, vector<int>(n + 1));
	isVisited.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
		board[b][a] = 1;
	}

	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (isVisited[i] == false)
		{
			isVisited[i] = true;
			++count;
			DFS(i);
		}
	}

	cout << count;
}