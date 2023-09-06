// 숨바꼭질 3

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> isVisited;
vector<int> dis;
int n, k;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	dis[start] = 0;

	while (!q.empty())
	{
		int now = q.front();

		if (now == k)
		{
			cout << dis[now];
			return;
		}

		q.pop();

		if (now * 2 < 200001)
		{
			if (isVisited[now * 2])
			{
				dis[now * 2] = min(dis[now], dis[now * 2]);
			}
			else
			{
				q.push(now * 2);
				isVisited[now * 2] = true;
				dis[now * 2] = dis[now];
			}
		}

		if (now + 1 < 200001)
		{
			if (isVisited[now + 1])
			{
				dis[now + 1] = min(dis[now] + 1, dis[now + 1]);
			}
			else
			{
				q.push(now + 1);
				isVisited[now + 1] = true;
				dis[now + 1] = dis[now] + 1;
			}
		}

		if (now - 1 >= 0)
		{
			if (isVisited[now - 1])
			{
				dis[now - 1] = min(dis[now] + 1, dis[now - 1]);
			}
			else
			{
				q.push(now - 1);
				isVisited[now - 1] = true;
				dis[now - 1] = dis[now] + 1;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	isVisited.resize(200001, false);
	dis.resize(200001);

	bfs(n);
}