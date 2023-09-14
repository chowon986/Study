// [BFS] 숨바꼭질

#include <iostream>
#include <queue>
using namespace std;

#define MAX 200000

int d[MAX + 1];
bool isVisited[MAX + 1];

int main()
{
	int n, m;
	cin >> n >> m;

	queue<int> q;
	q.push(n);
	isVisited[n] = true;

	while (!q.empty())
	{
		int now = q.front();

		if (now == m)
		{
			cout << d[m];
			return 0;
		}
		
		q.pop();

		if (now + 1 <= MAX)
		{
			if (isVisited[now + 1] == false)
			{
				d[now + 1] = d[now] + 1;
				q.push(now + 1);
				isVisited[now + 1] = true;
			}
		}

		if (now - 1 >= 0)
		{
			if (isVisited[now - 1] == false)
			{
				d[now - 1] = d[now] + 1;
				q.push(now - 1);
				isVisited[now - 1] = true;
			}
		}

		if (now * 2 <= MAX)
		{
			if (isVisited[now * 2] == false)
			{
				d[now * 2] = d[now] + 1;
				q.push(now * 2);
				isVisited[now * 2] = true;
			}
		}
	}
}