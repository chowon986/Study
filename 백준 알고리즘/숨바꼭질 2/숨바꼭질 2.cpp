// 숨바꼭질 2

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> minVisitedCnt(100001, -1);
vector<int> minVisitedCase(100001, 0);

int main()
{
	int n, k;
	cin >> n >> k;
	minVisitedCnt[n] = 0;
	minVisitedCase[n] = 1;
	queue<int> q;
	q.push(n);

	if (n == k)
	{
		cout << 0 << '\n' << 1;
		return 0;
	}

	while (!q.empty())
	{
		int cp = q.front();
		q.pop();

		for (int np : {cp + 1, cp - 1, cp * 2})
		{
			if (np < 0 || np > 100000) continue;

			// 처음 방문한다면
			if (minVisitedCnt[np] == -1)
			{
				q.push(np);
				minVisitedCnt[np] = minVisitedCnt[cp] + 1;
				minVisitedCase[np] += minVisitedCase[cp];
			}
			else if(minVisitedCnt[np] == minVisitedCnt[cp] + 1)
			{
				minVisitedCase[np] += minVisitedCase[cp];
			}
		}
	}

	cout << minVisitedCnt[k] << '\n' << minVisitedCase[k];
}