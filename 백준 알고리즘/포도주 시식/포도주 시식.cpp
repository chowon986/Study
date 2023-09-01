// 이전 풀이

//#include <iostream>
//using namespace std;
//
//int D[10001][4];
//int A[10001];
//
//int main()
//{
//	int Cnt;
//	cin >> Cnt;
//
//	for (int i = 1; i <= Cnt; i++)
//	{
//		int N;
//		cin >> N;
//		A[i] = N;
//	}
//
//	for (int i = 1; i <= Cnt; i++)
//	{
//		D[i][0] = max(D[i - 1][0], max(D[i - 1][1], D[i - 1][2]));
//		D[i][1] = D[i - 1][0] + A[i];
//		D[i][2] = D[i - 1][1] + A[i];
//	}
//
//	int Max = -1;
//
//	for (int i = 0; i < 3; i++)
//	{
//		if (Max < D[Cnt][i])
//			Max = D[Cnt][i];
//	}
//
//	cout << Max;
//}

#include <iostream>
#include <vector>
using namespace std;

int a[10001];

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> d(10001);

	d[0].resize(3);
	for (int i = 1; i <= n; i++)
	{
		d[i].resize(3);
		int temp;
		cin >> temp;
		a[i] = temp;
	}

	for (int i = 1; i <= n; i++)
	{
		d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}

	cout << max(d[n][0], max(d[n][1], d[n][2]));
}