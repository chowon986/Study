///*
//점화식
//D[i] = i번까지 있을때 최대 값
//D[i] = A[1];
//*/
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> A(1001, 1);
//vector<int> D(1001, 0);
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
//		D[i] = N;
//	}
//
//	for (int i = 1; i <= Cnt; i++)
//	{
//		for (int j = i; j > 0; j--)
//		{
//			if (A[i] > A[j])
//			{
//				D[i] = max(D[i], D[j] + A[i]);
//			}
//		}
//	}
//
//	int Max = -1;
//	for (int i = 1; i <= Cnt; i++)
//	{
//		if (Max < D[i])
//		{
//			Max = D[i];
//		}
//	}
//
//	cout << Max;
//}

// ??

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<int> numbers;
//	vector<int> d(n + 1, 1);
//
//	int maxValue = -1;
//
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//		numbers.push_back(temp);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i; j >= 0; j--)
//		{
//			if (numbers[i] > numbers[j])
//			{
//				d[i] = max(d[i], d[j] + 1);
//			}
//		}
//
//		maxValue = max(maxValue, d[i]);
//	}
//
//	cout << maxValue;
//}

// 가장 큰 증가하는 부분 수열 : https://www.acmicpc.net/problem/11055

#include <iostream>
using namespace std;

int a[1001];
int d[1001];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a[i] = temp;
	}

	d[0] = a[0];

	for (int i = 1; i < n; i++)
	{
		d[i] = a[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] > a[j])
			{
				d[i] = max(d[i], a[i] + d[j]);
			}
		}
	}

	int maxValue = -1;

	for (int i = 0; i < n; i++)
	{
		maxValue = max(maxValue, d[i]);
	}

	cout << maxValue;
}