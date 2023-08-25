//#include <iostream>
//using namespace std;
//
//int A[100001];
//int D[100001];
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
//	D[1] = A[1];
//
//	int Max = -1001;
//	for (int i = 1; i <= Cnt; i++)
//	{
//		D[i] = max(D[i - 1] + A[i], A[i]);
//
//		if (D[i] > Max)
//		{
//			Max = D[i];
//		}
//	}
//
//	cout << Max;
//}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> numbers(n + 1);
	vector<int> d(n + 1);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		numbers[i] = temp;
	}

	int maxValue = d[0] = numbers[0];

	for (int i = 1; i < n; i++)
	{
		if (numbers[i] < d[i - 1] + numbers[i])
			d[i] = d[i - 1] + numbers[i];
		else
			d[i] = numbers[i];

		maxValue = max(d[i], maxValue);
	}

	cout << maxValue;
}