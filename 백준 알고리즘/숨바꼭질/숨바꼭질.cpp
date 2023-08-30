// 숨바꼭질 : https://www.acmicpc.net/problem/1697

#include <iostream>
#include <queue>
#include <vector>

#define MAX 200001

using namespace std;

int main()
{
	vector<bool> check(MAX);
	vector<int> count(MAX, 0);

	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	count[0] = 0;

	while (!q.empty())
	{
		int now = q.front();

		if (now == k)
		{
			cout << count[now];
			break;
		}
		q.pop();

		if (now - 1 >= 0)
		{
			if (check[now - 1] == false)
			{
				q.push(now - 1);
				check[now - 1] = true;
				count[now - 1] = count[now] + 1;
			}
		}

		if (now + 1 < MAX)
		{
			if (check[now + 1] == false)
			{
				q.push(now + 1);
				check[now + 1] = true;
				count[now + 1] = count[now] + 1;
			}
		}

		if (now * 2 < MAX)
		{
			if (check[now * 2] == false)
			{
				q.push(now * 2);
				check[now * 2] = true;
				count[now * 2] = count[now] + 1;
			}
		}
	}
}