// [큐와 그래프] 이분 그래프

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[20001];
int color[20001];

bool dfs(int node, int c) // node에 방문, node의 색
{
	color[node] = c;

	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i];
		if (color[next] == 0)
		{
			if (dfs(next, 3 - c) == false) // 이분그래프가 아니면
			{
				return false;
			}
		}
		else if (color[next] == color[node])
		{
			return false;
		}

	}

	return true;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;

		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			color[i] = 0;
		}

		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		bool ok = true;
		for (int i = 1; i <= n; i++)
		{
			if (color[i] == 0)
			{
				if (dfs(i, 1) == false)
				{
					ok = false;
				}
			}
		}

		string ans = ok == true ? "YES" : "NO";
		cout << ans << '\n';
	}
}