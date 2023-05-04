#include <iostream>
using namespace std;

#define MAX 201
#define MOD 1000000000

int D[MAX][MAX];

int main()
{
	int N;
	int K;
	cin >> N >> K;

	D[0][0] = 1;

	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			for (int l = 0; l <= j; l++)
			{
				D[i][j] += D[i - 1][j - l];
				D[i][j] %= MOD;
			}
		}
	}

	cout << D[K][N];
}