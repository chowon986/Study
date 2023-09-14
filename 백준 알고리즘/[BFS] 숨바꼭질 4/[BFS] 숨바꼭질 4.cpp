// [BFS] 숨바꼭질 4

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 200000

vector<bool> isVisited(MAX + 1);
vector<int> prevVisited(MAX + 1, -1);
vector<int> d(MAX + 1);

void PrintVisitSpot(int now)
{
	if (now == -1) return;

	PrintVisitSpot(prevVisited[now]);
	cout << now << ' ';
}

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
			cout << d[m] << '\n';
			PrintVisitSpot(m);
			return 0;
		}

		q.pop();

		if (now + 1 <= MAX)
		{
			if (isVisited[now + 1] == false)
			{
				d[now + 1] = d[now] + 1;
				isVisited[now + 1] = true;
				q.push(now + 1);
				prevVisited[now + 1] = now;
			}
		}

		if (now - 1 >= 0)
		{
			if (isVisited[now - 1] == false)
			{
				d[now - 1] = d[now] + 1;
				isVisited[now - 1] = true;
				q.push(now - 1);
				prevVisited[now - 1] = now;
			}
		}

		if (now * 2 <= MAX)
		{
			if (isVisited[now * 2] == false)
			{
				d[now * 2] = d[now] + 1;
				isVisited[now * 2] = true;
				q.push(now * 2);
				prevVisited[now * 2] = now;
			}
		}
	}
}