// [큐와 그래프] DFS와 BFS

// 인접 행렬을 이용한 dfs 재귀 구현
// dfs에서 방문 = 함수의 호출을 의미

//void dfs(int x)
//{
//	isVisited[x] = true;
//
//	for (int i = 1; i <= n; i++)
//	{
//		// x와 i 사이에 간선이 있어야 함
//		// i를 방문한 적이 없어야 함
//		if (a[x][i] == 1 && isVisited[i] == false)
//		{
//			dfs(i);
//		}
//	}
//}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> Array;
vector<bool> bIsVisited;
vector<bool> dIsVisited;
int n, m, v;

void dfs(int x)
{
	dIsVisited[x] = true;
	cout << x << ' ';

	for (int i = 1; i <= n; i++)
	{
		if (Array[x][i] == 1 && dIsVisited[i] == false)
		{
			dfs(i);
		}
	}
}

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	bIsVisited[x] = true;

	while (!q.empty())
	{
		int now = q.front();
		cout << now << ' ';

		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (Array[now][i] == 1 && bIsVisited[i] == false)
			{
				q.push(i);
				bIsVisited[i] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> v;
	Array.resize(n + 1, vector<int>(n + 1));
	bIsVisited.resize(n + 1, false);
	dIsVisited.resize(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		Array[a][b] = 1;
		Array[b][a] = 1;
	}

	dfs(v);
	cout << '\n';
	bfs(v);
}