#include <iostream>
#include <vector>
using namespace std;

vector<int> p(1001);
vector<int> d(1001);

int main()
{
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++)
	{
		int temp;
		cin >> temp;
		p[i] = temp;
	}

	for (int i = 1; i <= tc; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			d[i] = max(d[i], d[i - j] + p[j]);
		}
	}

	cout << d[tc];
}