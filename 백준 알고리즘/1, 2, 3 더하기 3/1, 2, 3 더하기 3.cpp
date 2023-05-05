#include <iostream>
#include <vector>

#define MAX 1000001
#define MOD 1000000009

using namespace std;

int main()
{
	int Cnt;
	cin >> Cnt;

	vector<int> D(MAX, 0);

	D[0] = 1;

	for (int i = 1; i < MAX; i++)
	{
		if (i - 1 >= 0)
			D[i] += D[i - 1];

		if (i - 2 >= 0)
			D[i] += D[i - 2];

		D[i] %= MOD;

		if (i - 3 >= 0)
			D[i] += D[i - 3];

		D[i] %= MOD;

	}

	for (int i = 0; i < Cnt; i++)
	{
		int Num;
		cin >> Num;
		cout << D[Num] << '\n';
	}
}
