#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int Cnt;
	cin >> Cnt;

	vector<int> D(Cnt + 1, 0);
	vector<int> A(Cnt + 1, 0);

	for (int i = Cnt; i > 0; i--)
	{
		int N;
		cin >> N;
		D[i] = N;
		A[i] = 1;
	}


	for (int i = 1; i <= Cnt; i++)
	{
		for (int j = i - 1; j > 0; j--)
		{
			if (D[i] > D[j])
			{
				A[i] = max(A[i], A[j] + 1);
			}
		}
	}

	int Max = -1;
	for (int i = 1; i <= Cnt; i++)
	{
		if (Max < A[i])
		{
			Max = A[i];
		}
	}

	cout << Max;
}