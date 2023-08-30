// 숨바꼭질 : https://www.acmicpc.net/problem/13913

#include <queue>
#include <vector>
#include <iostream>

#define MAX 200001

using namespace std;

vector<int> prevNum(MAX);
int n, k;

void go(int index)
{
	if (index == n)
	{
		cout << index <<'\n';
		return;
	}

	if (index > MAX || index < 0) return;

	go(prevNum[index]);

	cout << index << '\n';
}

int main()
{
	cin >> n >> k;

	vector<int> count(MAX);
	vector<bool> check(MAX);
	queue<int> q;

	q.push(n);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now == k)
		{
			cout << count[now] << '\n';
			go(now);
			break;
		}

		if (now + 1 < MAX)
		{
			if (check[now + 1] == false)
			{
				q.push(now + 1);
				check[now + 1] = true;
				count[now + 1] = count[now] + 1;
				prevNum[now + 1] = now;
			}
		}

		if (now - 1 >= 0)
		{
			if (check[now - 1] == false)
			{
				q.push(now - 1);
				check[now - 1] = true;
				count[now - 1] = count[now] + 1;
				prevNum[now - 1] = now;
			}
		}

		if (now * 2 < MAX)
		{
			if (check[now * 2] == false)
			{
				q.push(now * 2);
				check[now * 2] = true;
				count[now * 2] = count[now] + 1;
				prevNum[now * 2] = now;
			}
		}
	}
}