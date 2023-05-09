#include <iostream>
using namespace std;

int A[501][501] = { 0, };
int D[501][501] = { 0, };

int main()
{
	int Cnt;
	cin >> Cnt;

	for (int i = 1; i <= Cnt; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int N;
			cin >> N;
			A[i][j] = N;
		}
	}

	for (int i = 1; i <= Cnt; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			D[i][j] = max(D[i - 1][j], D[i - 1][j - 1]) + A[i][j];
		}
	}

	int Max = -1;
	for (int i = 0; i <= Cnt; i++)
	{
		if (Max < D[Cnt][i])
			Max = D[Cnt][i];
	}

	cout << Max;
}
