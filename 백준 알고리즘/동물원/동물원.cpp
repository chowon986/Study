// 이전 풀이

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int D[100001][3];
//
//int main()
//{
//	int N;
//	cin >> N;
//
//	D[0][0] = 1;
//	D[0][1] = 0;
//	D[0][2] = 0;
//
//	for (int i = 1; i <= N; i++)
//	{
//		D[i][0] = (D[i - 1][0] + D[i - 1][1] + D[i - 1][2]) % 9901;
//		D[i][1] = (D[i - 1][0] + D[i - 1][2]) % 9901;
//		D[i][2] = (D[i - 1][0] + D[i - 1][1]) % 9901;
//	}
//
//	cout << (D[N][0] + D[N][1] + D[N][2]) % 9901;
//}

#include <iostream>
#include <vector>
using namespace std;

int d[100001][3];

int main()
{
	int n;
	cin >> n;

	d[0][0] = 1;
	d[0][1] = d[0][2] = 0;

	for (int i = 1; i <= n; i++)
	{
		d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % 9901;
		d[i][1] = (d[i - 1][0] + d[i - 1][2]) % 9901;
		d[i][2] = (d[i - 1][0] + d[i - 1][1]) % 9901;
	}

	cout << (d[n][0] + d[n][1] + d[n][2]) % 9901;
}
