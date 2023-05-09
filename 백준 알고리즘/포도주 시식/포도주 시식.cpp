#include <iostream>
using namespace std;

int D[10001][4];
int A[10001];

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

	for (int i = 1; i <= Cnt; i++)
	{
		D[i][0] = max(D[i - 1][0], max(D[i - 1][1], D[i - 1][2]));
		D[i][1] = D[i - 1][0] + A[i];
		D[i][2] = D[i - 1][1] + A[i];
	}

	int a = 0;
}