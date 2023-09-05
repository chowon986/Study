// 04 효율적인 화폐 구성

#include <iostream>
#include <vector>
using namespace std;

int a[101];
vector<int> d(10001, 10001);

int main()
{
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a[i] = temp;
	}
	
	d[0] = 0;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i - a[j] < 0) continue;

			if (d[i - a[j]] != 10001)
			{
				d[i] = min(d[i], d[i - a[j]] + 1);
			}
		}
	}

	if (d[m] == 10001)
	{
		cout << -1;
		return 0;
	}

	cout << d[m];
}