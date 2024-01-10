// 뮤탈리스크

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int attackPower[6][3] =
{
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 9, 3},
	{1, 3, 9}
};

struct health
{
	int a, b, c;
};

health SCVHealth;
bool isVisitied[64][64][64];
int visitedCount[64][64][64];


int check(int a, int b, int c)
{
	queue<health> q;
	isVisitied[a][b][c] = true;
	q.push({ a, b, c });

	while (!q.empty())
	{
		int ca = q.front().a;
		int cb = q.front().b;
		int cc = q.front().c;

		q.pop();

		if (isVisitied[0][0][0]) break;

		for (int i = 0; i < 6; i++)
		{
			int na = max(0, ca - attackPower[i][0]);
			int nb = max(0, cb - attackPower[i][1]);
			int nc = max(0, cc - attackPower[i][2]);

			if (isVisitied[na][nb][nc]) continue;
			isVisitied[na][nb][nc] = true;
			q.push({ na, nb, nc });
			visitedCount[na][nb][nc] = visitedCount[ca][cb][cc] + 1;
		}
	}

	return visitedCount[0][0][0];
}

int n;
int a[3];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << check(a[0], a[1], a[2]);
}