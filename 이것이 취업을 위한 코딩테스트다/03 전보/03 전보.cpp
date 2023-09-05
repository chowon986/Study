// 03 전보

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> board(n + 1);
	vector<int> distance(n + 1, INF);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ b,c });
	}

	priority_queue<pair<int, int>> pq;

	int start;
	cin >> start;

	pq.push({ 0, start });
}