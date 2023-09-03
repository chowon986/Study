// 이전 풀이

//// https://www.acmicpc.net/problem/11057
//
//#include <iostream>
//
//using namespace std;
//
//int D[1001][10];
//
//int main()
//{
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < 10; i++)
//	{
//		D[0][i] = 1;
//	}
//
//	int Sum = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			for (int k = 0; k <= j; k++)
//			{
//				D[i][j] += D[i - 1][k] % 10007;
//			}
//		}
//	}
//
//	cout << D[N][9] % 10007;
//}

// 시간 초과 풀이

//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> d;
//int sum = 0;
//
//void go(int index, int start, int count)
//{
//	if (index > 0)
//		if (start < d[index - 1]) return;
//
//	if (index == count)
//	{
//		++sum;
//
//		if (sum > 10007)
//			sum %= 10007;
//
//		return;
//	}
//
//	if (index > count) return;
//
//	for (int i = start; i < 10; i++)
//	{
//		d[index] = i;
//		go(index + 1, i, count);
//	}
//}
//
//int main()
//{
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//	d.resize(n);
//
//	go(0, 0, n);
//	cout << sum % 10007;
//}

//#include <iosteam>
//using namespace std;
//
//int d[1001][10];
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	// i번째 자리 수의 값은 j
//	// i-1번째 자리 수의 값은 k
//	// 문제 규칙 상 k <= j여야 함
//	// d[i][j]는 길이가 i이고, 마지막 숫자가 j인 오르막 수의 개수
//
//	for (int i = 0; i < 10; i++)
//		d[0][i] = 1;
//
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			for (int k = 0; k <= j; k++)
//			{
//				d[i][j] += d[i - 1][k] % 10007;
//			}
//		}
//	}
//
//	cout << d[n][9] % 10007;
//}

#include <iostream>
using namespace std;

int d[1001][10];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < 10; i++)
		d[0][i] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				d[i][j] += d[i - 1][k] % 10007;
			}
		}
	}

	cout << d[n][9] % 10007;
}