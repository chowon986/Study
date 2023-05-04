#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int Cnt;
	cin >> Cnt;

	vector<int> T(Cnt + 1, 0);
	vector<int> P(Cnt + 1, 0);
	vector<int> D(Cnt + 1, 0);

	for (int i = 1; i <= Cnt; i++)
	{
		int Num;
		cin >> Num;
		T[i] = Num;

		cin >> Num;
		P[i] = Num;
	}

	for (int i = Cnt; i > 0; i--)
	{
		if (i + T[i] > Cnt +1)
			continue;

		int Sum = 0;

		if (T[i] == 1)
			D[i] = P[i];
		else
		{
			for (int j = i + 1; j < i + T[i]; j++)
			{
				Sum += D[j];
			}

			if (P[i] > Sum)
				D[i] = P[i] - Sum;
			else
			{
				D[i] = 0;
			}
		}
	 }

	int Sum = 0;
	for (int Value : D)
	{
		Sum += Value;
	}

	cout << Sum;
}
