/*
점화식
D[i] = i번까지 있을때 최대 값
D[i] = A[1];
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> A(1001, 1);
vector<int> D(1001, 0);

int main()
{
	int Cnt;
	cin >> Cnt;

	for (int i = 1; i <= Cnt; i++)
	{
		int N;
		cin >> N;
		A[i] = N;
		D[i] = N;
	}

	for (int i = 1; i <= Cnt; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (A[i] > A[j])
			{
				D[i] = max(D[i], D[j] + A[i]);
			}
		}
	}

	int Max = -1;
	for (int i = 1; i <= Cnt; i++)
	{
		if (Max < D[i])
		{
			Max = D[i];
		}
	}

	cout << Max;
}
