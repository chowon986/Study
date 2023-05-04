#include <iostream>
using namespace std;

int A[100001];
int D[100001];

int main()
{
	int Cnt;
	cin >> Cnt;

	for (int i = 1; i <= Cnt; i++)
	{
		int N;
		cin >> N;
		A[i] = N;
	}

	D[1] = A[1];

	int Max = -1001;
	for (int i = 1; i <= Cnt; i++)
	{
		D[i] = max(D[i - 1] + A[i], A[i]);

		if (D[i] > Max)
		{
			Max = D[i];
		}
	}

	cout << Max;
}