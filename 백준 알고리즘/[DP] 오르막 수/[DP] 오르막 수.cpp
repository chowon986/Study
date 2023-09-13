// [DP] 오르막 수

// 시간 초과

//#include <iostream>
//using namespace std;
//
//int sum = 0;
//int d[1001];
//
//void go(int index, int count, int start)
//{
//	if (index == count)
//	{
//		++sum;
//		return;
//	}
//
//	if (index > count) return;
//
//	for (int i = start; i < 10; i++)
//	{
//		d[index] = i;
//
//		if (index > 0)
//		{
//			if (d[index] >= d[index - 1])
//			{
//				go(index + 1, count, i);
//			}
//		}
//		else
//			go(index + 1, count, i);
//	}
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	go(0, n, 0);
//
//	cout << sum % 10007; 
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