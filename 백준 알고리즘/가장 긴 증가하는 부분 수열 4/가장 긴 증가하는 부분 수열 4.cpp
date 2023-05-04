#include <iostream>
#include <vector>
using namespace std;

int A[1001];
int D[1001];
int V[1001];

int main()
{
	int Cnt;
	cin >> Cnt;

	for (int i = 1; i <= Cnt; i++)
	{
		cin >> A[i];
		D[i] = 1;
	}

	if (Cnt == 1)
	{
		cout << 1 << '\n';
		cout << A[1];
		return 0;
	}

	int Max = 0;
	int MaxIndex = 0;

	for (int i = 2; i <= Cnt; i++)
	{
		for (int j = i - 1; j > 0; j--)
		{
			if (A[i] > A[j])
			{
				if (D[i] < D[j] + 1)
				{
					D[i] = D[j] + 1;
					V[i] = j;
				}
			}
		}

		if (D[i] > Max)
		{
			Max = D[i];
			MaxIndex = i;
		}
	}

	cout << Max << '\n';

	vector<int> Numbers;
	while (true)
	{
		Numbers.push_back(A[MaxIndex]);
		MaxIndex = V[MaxIndex];
		if (MaxIndex == 0)
		{
			while (Numbers.size() != 0)
			{
				cout << Numbers.back() << ' ';
				Numbers.pop_back();
			}

			return 0;
		}
	}
}