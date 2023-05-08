// https://www.acmicpc.net/problem/11057

#include <iostream>

using namespace std;

int D[1001][10];

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < 10; i++)
	{
		D[0][i] = 1;
	}

	int Sum = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				D[i][j] += D[i - 1][k] % 10007;
			}
		}
	}

	cout << D[N][9] % 10007;
}