// 이전 풀이

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int Cnt;
//	cin >> Cnt;
//
//	int Cost[3];
//	int House[1001][3];
//
//	House[0][0] = 0;
//	House[0][1] = 0;
//	House[0][2] = 0;
//
//	for (int i = 1; i <= Cnt; i++)
//	{
//		cin >> Cost[0] >> Cost[1] >> Cost[2];
//		House[i][0] = min(House[i - 1][1], House[i - 1][2]) + Cost[0];
//		House[i][1] = min(House[i - 1][0], House[i - 1][2]) + Cost[1];
//		House[i][2] = min(House[i - 1][0], House[i - 1][1]) + Cost[2];
//	}
//
//	cout << min(House[Cnt][2], min(House[Cnt][0], House[Cnt][1]));
//}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> d(n+1);
	
	for (int i = 0; i <= n; i++)
	{                   
		d[i].resize(3);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int temp;
			cin >> temp;
			d[i + 1][j] = temp;
		}
	}

	for (int j = 2; j <= n; j++)
	{
		d[j][0] += min(d[j - 1][1], d[j - 1][2]);
		d[j][1] += min(d[j - 1][0], d[j - 1][2]);
		d[j][2] += min(d[j - 1][0], d[j - 1][1]);
	}

	cout << min(d[n][0], min(d[n][1], d[n][2]));
}