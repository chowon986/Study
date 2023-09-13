// [큐와 그래프] ABCDE

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool a[2000][2000];				// 인접행렬
vector<int> g[2000];			// 인접 리스트
vector<pair<int, int>> edges;   // 모든 간선 저장

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		edges.push_back({ from, to });    // 간선리스트에 양방향 저장
		edges.push_back({ to, from });
		a[from][to] = a[to][from] = true; // 인접 행렬에 저장
		g[from].push_back(to);			  // 인접 리스트에 저장
		g[to].push_back(from);
	}

	m *= 2; // 양방향이여서 2개씩 넣었으므로 *2

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int A = edges[i].first;
			int B = edges[i].second;

			int C = edges[j].first;
			int D = edges[j].second;

			// A->B C->D 확인
			if (A == B || A == C || A == D || B == C || B == D || C == D) continue;
		
			// B->C 확인
			if (!a[B][C]) continue;

			for (int E : g[D])
			{
				if (A == E || B == E || C == E || D == E) continue;

				cout << 1 << '\n';
				return 0;
			}
		}
	}

	cout << 0 << '\n';
	return 0;
}
