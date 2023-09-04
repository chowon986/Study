#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

stack<int> s;
queue<int> q;
vector<vector<int>> b;

void dfs(int v, vector<bool>& visited)
{
	s.push(v);
	visited[v] = true;
	cout << s.top() << ' ';

	for (int i = 1; i < b.size(); i++)
	{
		if (b[v][i] == 1 && visited[i] == false)
		{
			dfs(i, visited);
		}
	}
}

void bfs(int v, vector<bool>& visited)
{
	if (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
	}

	for (int i = 1; i < b.size(); i++)
	{
		if (b[v][i] == 1 && visited[i] == false)
		{
			q.push(i);
			visited[i] = true;
		}
	}

	if (!q.empty())
	{
		bfs(q.front(), visited);
	}
}

int main()
{
	int n, m, v;
	cin >> n >> m >> v;
	vector<bool> visitedDfs(n + 1, false);
	vector<bool> visitedBfs(n + 1, false);

	b.resize(n + 1);

	for (int i = 1; i <= n; i++)
		b[i].resize(n + 1);

	for (int j = 1; j <= m; j++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		b[temp1][temp2] = 1;
		b[temp2][temp1] = 1;
	}

	dfs(v, visitedDfs);
	cout << '\n';
	q.push(v);
	visitedBfs[v] = true;
	bfs(v, visitedBfs);
}