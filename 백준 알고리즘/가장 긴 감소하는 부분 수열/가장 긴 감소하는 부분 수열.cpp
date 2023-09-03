// 이전 풀이

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int Cnt;
//	cin >> Cnt;
//
//	vector<int> D(Cnt + 1, 0);
//	vector<int> A(Cnt + 1, 0);
//
//	for (int i = Cnt; i > 0; i--)
//	{
//		int N;
//		cin >> N;
//		D[i] = N;
//		A[i] = 1;
//	}
//
//
//	for (int i = 1; i <= Cnt; i++)
//	{
//		for (int j = i - 1; j > 0; j--)
//		{
//			if (D[i] > D[j])
//			{
//				A[i] = max(A[i], A[j] + 1);
//			}
//		}
//	}
//
//	int Max = -1;
//	for (int i = 1; i <= Cnt; i++)
//	{
//		if (Max < A[i])
//		{
//			Max = A[i];
//		}
//	}
//
//	cout << Max;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> a;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a.push_back(temp);
	}

	reverse(a.begin(), a.end());

	vector<int> d(n, 1);

	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[i] > a[j])
			{
				d[i] = max(d[i], d[j] + 1);
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