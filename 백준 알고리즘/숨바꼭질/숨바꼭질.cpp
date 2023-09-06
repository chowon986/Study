// 숨바꼭질 : https://www.acmicpc.net/problem/1697

// 이전 풀이

//#include <iostream>
//#include <queue>
//#include <vector>
//
//#define MAX 200001
//
//using namespace std;
//
//int main()
//{
//	vector<bool> check(MAX);
//	vector<int> count(MAX, 0);
//
//	int n, k;
//	cin >> n >> k;
//
//	queue<int> q;
//	q.push(n);
//	count[0] = 0;
//
//	while (!q.empty())
//	{
//		int now = q.front();
//
//		if (now == k)
//		{
//			cout << count[now];
//			break;
//		}
//		q.pop();
//
//		if (now - 1 >= 0)
//		{
//			if (check[now - 1] == false)
//			{
//				q.push(now - 1);
//				check[now - 1] = true;
//				count[now - 1] = count[now] + 1;
//			}
//		}
//
//		if (now + 1 < MAX)
//		{
//			if (check[now + 1] == false)
//			{
//				q.push(now + 1);
//				check[now + 1] = true;
//				count[now + 1] = count[now] + 1;
//			}
//		}
//
//		if (now * 2 < MAX)
//		{
//			if (check[now * 2] == false)
//			{
//				q.push(now * 2);
//				check[now * 2] = true;
//				count[now * 2] = count[now] + 1;
//			}
//		}
//	}
//}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> isVisited;
vector<int> dis;
vector<int> prevPos;
int n, k;

void PrintMovePos(int now)
{
	if (now == n)
	{
		cout << n << ' ';
		return;
	}

	PrintMovePos(prevPos[now]);

	cout << now << ' ';
}

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
			cout << dis[now] << '\n';
			PrintMovePos(now);
			return;
		}

		q.pop();

		if (now + 1 < 200001)
		{
			if (isVisited[now + 1] == false)
			{
				q.push(now + 1);
				isVisited[now + 1] = true;
				dis[now + 1] = dis[now] + 1;
				prevPos[now + 1] = now;
			}
		}

		if (now - 1 >= 0)
		{
			if (isVisited[now - 1] == false)
			{
				q.push(now - 1);
				isVisited[now - 1] = true;
				dis[now - 1] = dis[now] + 1;
				prevPos[now - 1] = now;
			}
		}

		if (now * 2 < 200001)
		{
			if (isVisited[now * 2] == false)
			{
				q.push(now * 2);
				isVisited[now * 2] = true;
				dis[now * 2] = dis[now] + 1;
				prevPos[now * 2] = now;
			}
		}
	}
}

int main()
{
	cin >> n >> k;

	isVisited.resize(200001, false);
	dis.resize(200001);
	prevPos.resize(200001);

	bfs(n);
}