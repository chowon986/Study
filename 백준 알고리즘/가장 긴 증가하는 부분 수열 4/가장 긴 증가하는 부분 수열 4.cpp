//#include <iostream>
//#include <vector>
//using namespace std;
//
//int A[1001];
//int D[1001];
//int V[1001];
//
//int main()
//{
//	int Cnt;
//	cin >> Cnt;
//
//	for (int i = 1; i <= Cnt; i++)
//	{
//		cin >> A[i];
//		D[i] = 1;
//	}
//
//	if (Cnt == 1)
//	{
//		cout << 1 << '\n';
//		cout << A[1];
//		return 0;
//	}
//
//	int Max = 0;
//	int MaxIndex = 0;
//
//	for (int i = 2; i <= Cnt; i++)
//	{
//		for (int j = i - 1; j > 0; j--)
//		{
//			if (A[i] > A[j])
//			{
//				if (D[i] < D[j] + 1)
//				{
//					D[i] = D[j] + 1;
//					V[i] = j;
//				}
//			}
//		}
//
//		if (D[i] > Max)
//		{
//			Max = D[i];
//			MaxIndex = i;
//		}
//	}
//
//	cout << Max << '\n';
//
//	vector<int> Numbers;
//	while (true)
//	{
//		Numbers.push_back(A[MaxIndex]);
//		MaxIndex = V[MaxIndex];
//		if (MaxIndex == 0)
//		{
//			while (Numbers.size() != 0)
//			{
//				cout << Numbers.back() << ' ';
//				Numbers.pop_back();
//			}
//
//			return 0;
//		}
//	}
//}

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> numbers;
vector<int> index(1001, -1);

void go(int maxIndex)
{
	if (maxIndex == -1) return;

	go(index[maxIndex]);

	cout << numbers[maxIndex] << ' ';
}

int main()
{
	int n;
	cin >> n;

	int maxValue = -1;
	int maxIndex = -1;

	vector<int> count(1001, 1);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (numbers[i] > numbers[j])
			{
				if (count[i] < (count[j] + 1))
				{
					count[i] = count[j] + 1;
					index[i] = j;
				}
			}
		}

		if (maxValue < count[i])
		{
			maxValue = count[i];
			maxIndex = i;
		}
	}

	cout << maxValue << '\n';

	go(maxIndex);
}