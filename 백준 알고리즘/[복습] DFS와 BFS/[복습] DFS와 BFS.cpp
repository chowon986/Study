// [복습] DFS와 BFS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, v;
vector<bool> DFSisVisited;	
vector<vector<int>> board;

void DFS(int x)
{
	cout << x << ' ';

	for (int i = 1; i <= n; i++)
	{
		if (board[x][i] == 1 && DFSisVisited[i] == false)
		{
			DFSisVisited[i] = true;
			DFS(i);
		}
	}
}

int main()
{
	cin >> n >> m >> v;

	board.resize(n + 1, vector<int>(n + 1));
	vector<bool> isVisited(n + 1);
	DFSisVisited.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
		board[b][a] = 1;
	}

	// DFS
	DFSisVisited[v] = true;
	DFS(v);

	cout << '\n';

	// BFS
	queue<int> q;
	q.push(v);
	isVisited[v] = true;
	cout << v << ' ';
	while (!q.empty())
	{
		int now = q.front();

		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (board[now][i] == 1 && isVisited[i] == false)
			{
				isVisited[i] = true;
				cout << i << ' ';
				q.push(i);
			}
		}
	}
}