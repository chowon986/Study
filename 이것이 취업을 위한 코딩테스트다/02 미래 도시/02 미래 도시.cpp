// 02 미래 도시

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> b(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			b[i][j] = 1e9;
	}


	int a = 0;
}