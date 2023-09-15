// [복습] 정수 삼각형

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> answer(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int temp;
			cin >> temp;
			answer[i][j] = temp;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			answer[i][j] = answer[i][j] + max(answer[i - 1][j - 1], answer[i - 1][j]);
		}
	}

	int maxValue = -1;

	for (int i = 1; i <= n; i++)
	{
		maxValue = max(maxValue, answer[n][i]);
	}
	
	cout << maxValue;
}