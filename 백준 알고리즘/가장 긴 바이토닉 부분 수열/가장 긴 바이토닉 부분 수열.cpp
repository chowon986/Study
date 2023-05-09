#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int Cnt;
	cin >> Cnt;

	vector<int> Numbers(Cnt + 1, 0);
	vector<int> U(Cnt + 1, 0);
	vector<int> D(Cnt + 1, 0);

	for (int i = 1; i <= Cnt; i++)
	{
		int N;
		cin >> N;
		Numbers[i] = N;
		U[i] = 1;
		D[i] = 1;
	}

	for (int i = 1; i <= Cnt; i++)
	{
		for (int j = i - 1; j > 0; j--)
		{
			if (Numbers[i] > Numbers[j])
			{
				U[i] = max(U[i], U[j] + 1);
			}
		}
	}

	for (int i = Cnt - 1; i > 0; i--)
	{
		for (int j = i + 1; j <= Cnt; j++)
		{
			if (Numbers[i] > Numbers[j])
			{
				D[i] = max(D[i], D[j] + 1);
			}
		}
	}

	int Max = -1;
	for (int i = 1; i <= Cnt; i++)
	{
		if (Max < U[i] + D[i])
		{
			Max = U[i] + D[i];
		}
	}

	cout << Max - 1;
}