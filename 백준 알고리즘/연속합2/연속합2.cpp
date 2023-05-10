#include <iostream>
#include <vector>
using namespace std;
int DP[100001][2];
int Arr[100001];

int main()
{
	int Cnt;
	cin >> Cnt;

	for (int i = 0; i < Cnt; i++)
	{
		cin >> Arr[i];
	}

	DP[0][0] = Arr[0];
	DP[0][1] = Arr[0];

	int Max = Arr[0];

	for (int i = 1; i < Cnt; i++)
	{
		DP[i][0] = max(DP[i - 1][0] + Arr[i], Arr[i]);
		DP[i][1] = max(DP[i - 1][0], DP[i - 1][1] + Arr[i]);

		Max = max(Max, max(DP[i][0], DP[i][1]));
	}

	cout << Max;

}